#include "Behaviour.h"
#include <iostream>
#include <vector>
using std::vector;
using namespace std;

Behaviour::Behaviour()
{

}

Behaviour::~Behaviour()
{

}

//Distance is measure by car lengths, the y value of a car is 2, later we will see trucks being 10 etc. Adding more complexity for overtake
bool Behaviour :: scanYourSide(std::vector<Vehicle*> cars , Layout *road , Vehicle * car){ //Iteration 1 Speed up and Slow Down, This method will change throughout iterations to handle overtake
  bool decision = false;
  string direction = car->getDirection();
  int myCarX = car->GetX();
  int myCarY = car->GetY();
  int myCarSpeed = car->getSpeed();
  int closestCar = 1000000;
  int theirSpeed = 0;
  double driverAggression = car->getAggression();
  int speedLimit = road->getSpeedLimit();
  bool foundCar = false;


   for(int i=0; i< cars.size(); i++){
      int theirCarX = cars.at(i)->GetX();
      int theirCarY = cars.at(i)->GetY();
      if(direction == "North" || direction == "South"){  //We check X co-ordinates when they are going north or south an Y vica versa

      if(((theirCarX == myCarX) && (theirCarY > myCarY)) && (theirCarY < closestCar)){  //This means The Car is on the same road and they are infront but not directly therefore we must find if it is the car directly infront of you
          theirSpeed =  cars.at(i)->getSpeed();
          closestCar = theirCarY; //at the end of the for loop we will have the closest car as it will be the lowest Y co-ordinate that is bigger than yours
          foundCar = true;
          }
      }
      else{

          if(((theirCarY == myCarY) && (theirCarX > myCarX)) && (theirCarX < closestCar)){  //This means The Car is on the same road and they are infront but not directly therefore we must find if it is the car directly infront of you
              theirSpeed =  cars.at(i)->getSpeed();
              closestCar = theirCarX; //at the end of the for loop we will have the closest car as it will be the lowest Y co-ordinate that is bigger than yours
              foundCar = true;
              }
      }
   }


         int distance;
         cout<<"\nClosest Car is at Y position"<<closestCar<<"\n";
		 //fix
         if((direction == "North" || direction == "South") && foundCar == true){
          distance = closestCar - myCarY; //Distance Found between cars 2 is the height of a car so 4 should be enough to overtake as long as the car infront of the next car is more than 2 ahead
          cout <<"\nDistance between car infront of you is:"<<distance<<"\n";                                                                  //Nothing is found in front                                          Over 1.5 will break the speed limit
         }
		  //BUF FOUND IF IF ELSE< NO IF ELSE
         else if((direction == "East" || direction == "West") && foundCar == true){
          distance = closestCar - myCarX; //Distance Found between cars 2 is the height of a car so 4 should be enough to overtake as long as the car infront of the next car is more than 2 ahead
          cout <<"\nDistance between car infront of you is:"<<distance<<"\n";                                                                  //Nothing is found in front                                          Over 1.5 will break the speed limit
         }

         else{
             distance = 1000000;
         }
		                    //|| ((closestCar == 1000000 && myCarSpeed < speedLimit))                                                                                                              //NB MAY TAKE OUT
          if(((distance > 10) && (theirSpeed > myCarSpeed)) || distance >200 || (closestCar == 1000000 && driverAggression> 1.5)){ //Next car is far  away and moving therefore we can speed up for the time being or else the car is really far away therefore we can speed up for the time being, needs to be far ahead beause we dont want to accelerate too fast and end up rear ending them if they break
          return true;   //should increase speed
          }

          else{ //Next Car is too close, need to add in if car infront is slowing down then so do you i.e car in fronts speed is less than yours
              return false;
          }



  return decision;
}

void Behaviour::reduceSpeed(Vehicle *car, vector<Layout *> roads){ //Vector of roads to find out the speed limit for the current road
 double driverAggression = car->getAggression();
 int carSpeed = car->getSpeed();

 string direction = car->getDirection();
 //reduce speed according to car infront of you-----Needs to be done // for now I will decrease it depending on aggression

 int newSpeed = (carSpeed) - (carSpeed/driverAggression/10);  //lower the aggression the more decrease in speed

 car->setSpeed(newSpeed); //giving car new speed
 setNewCoOrdiantes(car,"Decrease",newSpeed);


}

//Working relatively ok
void Behaviour::increaseSpeed(Vehicle *car,vector<Layout *> roads){
  double driverAggression = car->getAggression();
  int carSpeed = car->getSpeed();

  int speedLimit;

  //Find speed Limit // not needed for slowDown unless we want to take into account the speed that other cars may be going at e.g. Car behind is going 100kmph and you slow down to 40 , the breaking distance may cause the car to rear end you
  for(int i=0; i<roads.size(); i++){
     bool onRoad = isOnThisRoad(car,roads.at(i));
     if(onRoad){
         speedLimit = roads.at(i)->getSpeedLimit();
       //  cout << speedLimit;
         break;
     }

  }

  int newSpeed =(carSpeed) + ((speedLimit /carSpeed) * (driverAggression)) * 8;  //High increases when aggression is high low increas when aggression is low
  cout << "NEW SPEED " << newSpeed << endl;
  car->setSpeed(newSpeed); //giving car new speed
  setNewCoOrdiantes(car,"Increase",newSpeed);
}


//ONLY FOR NOTH AND SOUTH FACING TRAFFIC, WILL IMPLEMENT EAST AND WEST LATER
bool Behaviour::isOnThisRoad(Vehicle *car, Layout *road){
    int carX = car->GetX();
    int carY = car->GetY();
    string direction = car->getDirection();
    int roadPositionX = road->GetX();
    int roadPositionY = road->GetY();
	int roadWidth = road->GetW();
	int roadHeight = road->GetH();

	//x coordiate to width / 2 is the left side of the road
	leftHandSideOfRoad = roadPositionX + (roadWidth/2) -10; //gets x and adds width divided by 2 to get the left most side of the road, maybe -10 to leave yellow lines in the missle
	rightHandSideOfRoad = roadPositionX + roadWidth; // this is the further most right part of the road
	middleForOvertaking = roadPositionX + (roadWidth/2) +10; //Leaves 20 in the middle for overtaking
	//North traffic on left hand side and South right hand side of road
    if((carX < leftHandSideOfRoad && (direction == "North")) ||  ((carX > middleForOvertaking && carX <=rightHandSideOfRoad) && direction =="South") || (carX == middleForOvertaking)){  //We are on the same X xo-ordinate therefore the same road
        return true;
    }
   // if(roadPositionY == carY && (direction == "East" || direction =="West")){  //We are on the same Y Co-ordiante
   //     return true;
   // }
    return false;

}



void Behaviour::setNewCoOrdiantes(Vehicle * car, string inc_dec, int newSpeed){//Addes this as there was duplication of code
    string direction = car->getDirection();
    int carX = car->GetX();
    int carY = car->GetY();


   // if(inc_dec == "Increase"){
        if(direction == "North"){    //Going north therefore we increase y axis
            car->SetY(carY - newSpeed/20);
        }
        if(direction == "South")   //Going south there fore we decrease y axis
        {
             car->SetY(carY + newSpeed/20);
        }
        if(direction == "East")
        {
             car->SetX(carX + newSpeed/20);
        }
        if(direction == "West")
        {
             car->SetX(carX - newSpeed/20);
        }
  //  }
   /* if(inc_dec == "Decrease"){
        if(direction == "North"){    //Going north therefore we decrease y axis
            car->setY(carY - newSpeed/20);
        }
        if(direction == "South")   //Going south there fore we increase y axis
        {
             car->setY(carY + newSpeed/20);
        }
        if(direction == "East")
        {
             car->setX(carX - newSpeed/20);
        }
        if(direction == "West")
        {
             car->setX(carX + newSpeed/20);
        }
    } */
 }


//Must add in conditions if the drivers aggressiveness is > 1.5 etc etc
bool Behaviour::scanOtherSide(std::vector<Vehicle*> cars , Layout *road , Vehicle * car){  //If mySide == false and other side == true;
	bool decision = false;
	//bool foundCar = foundCarInFront(cars,road,car);

	if(areCarsOnOppositeSide(cars,car) == false){
		return true;
	}

	else{
		
	for(int i=0; i< cars.size(); i++){
		if(oppositeDirection(car,cars.at(i),road)){ //Found car on the other side of the road, check every car and see how close they are or if empty then go
			if(cars.at(i)->getDirection() == "North" || cars.at(i)->getDirection() == "South" ){
				int distance = car->GetY() - cars.at(i)->GetY() ; // Positive number indicates it is closer to the top of the screen as SDL x & y axis start at the top left corner of the screen at (0,0)
				if(distance > 8){//3 car lengths{
					//return true;
					decision = true;
				}
				else{
					return false; //car too close
				}
			}

			}
			else{
				 int distance = car->GetX() - cars.at(i)->GetX()  ;
				 if(distance > 8){//3 car lengths{
					 //return true;
					 decision = true; //True only returned if it goes through all cars and it hasnt returned false
				 }
				 else{
					return false; //car too close
				}
			}
			}  
		

	return decision;
	
   }
}

void Behaviour::overTake(vector<Vehicle*> cars, Vehicle *car, Layout *road){

	int getRoadsWidth = road->GetW();
	int getRoadX = road->GetX();
	int getRoadY = road->GetY();
	string x ="";
	cout << car->GetX() <<endl;
	if(car->getDirection() == "North" || car->getDirection() == "South"){
	car->SetX(60);
	cout << car->GetX() <<endl;
	car->setSpeed(100);
	setNewCoOrdiantes(car,x,100);
	}
	else{
    // car->SetY(car->GetY() + 1);   //Depends which way we look at the roads, will discuss in meeting
	 car->setSpeed(100);
	 setNewCoOrdiantes(car,x,100);
	}
}


// This method checks if the car is on the same road and it is travelling in the opposite direction
bool Behaviour:: oppositeDirection(Vehicle *myCar,Vehicle *car,Layout *road){ 
	if(isOnThisRoad(car,road)){
		if((myCar->getDirection() == "North" && car->getDirection() == "South") || (myCar->getDirection() == "South" && car->getDirection() == "North")
			|| (myCar->getDirection() == "East" && car->getDirection() == "West") || (myCar->getDirection() == "West" && car->getDirection() == "East"))
			return true;
	}

}

//Very similar to oppsote direction except we check all cars and see is there any on the other side
//This will prevent further checks if no cars exist on the opposite side of the road
// Will be rewriting isOnRoad to do these checks but for now have to do this
//As cars are not part of layout
bool Behaviour:: areCarsOnOppositeSide(vector<Vehicle*> cars, Vehicle *car){
	string myCarsDirection = car->getDirection(); //So we can check oppsite direction
	return false;

}


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
  int myCarX = car->GetX();
  int myCarY = car->GetY();
  int myCarSpeed = car->getSpeed();
  int closestCar = 1000000;
  int theirSpeed;
  double driverAggression = car->getAggression();
  int speedLimit = road->getSpeedLimit();

   for(int i=0; i< cars.size(); i++){
	   int theirCarX = cars.at(i)->GetX();
	   int theirCarY = cars.at(i)->GetY();
      if(((theirCarX == myCarX) && (theirCarY > myCarY)) && (theirCarY < closestCar)){  //This means The Car is on the same road and they are infront but not directly therefore we must find if it is the car directly infront of you
          theirSpeed =  cars.at(i)->getSpeed();
          closestCar = theirCarY; //at the end of the for loop we will have the closest car as it will be the lowest Y co-ordinate that is bigger than yours
          }
   }
         cout<<"\nClosest Car is at Y position"<<closestCar<<"\n";
          int distance = closestCar - myCarY; //Distance Found between cars 2 is the height of a car so 4 should be enough to overtake as long as the car infront of the next car is more than 2 ahead
          cout <<"\nDistance between car infront of you is:"<<distance<<"\n";                                                                  //Nothing is found in front                                          Over 1.5 will break the speed limit
          if(((distance > 10) && (theirSpeed > myCarSpeed)) || distance >200 || ((closestCar == 1000000 && myCarSpeed < speedLimit)) || (closestCar == 1000000 && driverAggression> 1.5)){ //Next car is far  away and moving therefore we can speed up for the time being or else the car is really far away therefore we can speed up for the time being, needs to be far ahead beause we dont want to accelerate too fast and end up rear ending them if they break
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
 int carX = car->GetX();

 //reduce speed according to car infront of you-----Needs to be done // for now I will decrease it depending on aggression
 int newSpeed = (carSpeed) - (carSpeed/driverAggression/10);  //lower the aggression the more decrease in speed
 car->setSpeed(newSpeed); //giving car new speed
}

//Working relatively ok
void Behaviour::increaseSpeed(Vehicle *car,vector<Layout *> roads){
  double driverAggression = car->getAggression();
  int carSpeed = car->getSpeed();
  int carX = car->GetX();
  int speedLimit;
  //Find speed Limit // not needed for slowDown unless we want to take into account the speed that other cars may be going at e.g. Car behind is going 100kmph and you slow down to 40 , the breaking distance may cause the car to rear end you
  for(int i=0; i<roads.size(); i++){
      int roadPositionX = roads.at(i)->GetX();
      if(roadPositionX == carX){  //We are on the same X xo-ordinate therefore the same road
          speedLimit = roads.at(i)->getSpeedLimit();
      }

  }
  int newSpeed =(carSpeed) + ((speedLimit /carSpeed) * (driverAggression)) * 8;  //High increases when aggression is high low increas when aggression is low
  car->setSpeed(newSpeed); //giving car new speed

}


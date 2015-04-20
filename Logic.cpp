#include "Logic.h"
#include "Behaviour.h"
#include "Vehicle.h"
#include "Layout.h"
#include <vector>
<<<<<<< HEAD
#include<iostream>
=======
#include <iostream>

>>>>>>> origin/master
using namespace std;
 
Logic::Logic() {
}
<<<<<<< HEAD
 
Logic::Logic(vector<Vehicle*> cars, vector<Layout*> roads ){
    this->cars = cars;
    this->roads = roads;
       stop = false;
      
=======

Logic::Logic(vector<Vehicle*> cars, vector<Layout*> roads){
	this->cars = cars;
	this->roads = roads;
	stop = false;
>>>>>>> origin/master
}
 
Logic::~Logic() {
}
<<<<<<< HEAD
 
vector<Vehicle*> Logic:: getCars(){
    return cars;
}
 
void Logic:: setCars(vector<Vehicle*> cars){
    this->cars = cars;
}
 
vector<Layout*> Logic:: getRoads(){
    return roads;
=======

vector<Vehicle*> Logic::getCars(){
	return cars;
}

void Logic::setCars(vector<Vehicle*> cars){
	this->cars = cars;
}

vector<Layout*> Logic::getRoads(){
	return roads;
>>>>>>> origin/master
}
 
void Logic::setRoads(vector<Layout*> roads){
	this->roads = roads;
}
<<<<<<< HEAD
 
//scan all the vehicles on all the roads to adjust driver's behavior
=======

//scan all the vehicles on all the roads to adjust driver's behavior; also record average speed of all the cars
>>>>>>> origin/master
void Logic::scan(){
	stop = false;
	Behaviour *myBehaviour = new Behaviour();
	bool decision;
	//iterate through the vehicles on each road and help each car to increase/reduce speed when necessary

	int sumSpeed = 0, systemAverageSpeed = 0;
	
	vector<Vehicle*>::iterator c;
	vector<Layout*>::iterator r;
		for (r = roads.begin(); r != roads.end(); ++r)
		{
			for (c = cars.begin(); c != cars.end(); ++c)
			{
				decision = myBehaviour->scanYourSide(cars, *r, *c);
<<<<<<< HEAD
				 if(decision){
                           myBehaviour->increaseSpeed(*c, roads); 
				 }
                 else if((myBehaviour->scanOtherSide( cars,*r ,*c)) && (decision == false)){
                           myBehaviour->overTake(cars,*c,*r);  
                 }
				 else{
                           myBehaviour->reduceSpeed(*c, roads);
				}
			
				//get speeds of all cars and add them up
				sumSpeed += (*c)->getSpeed();
		}

			//calculate average speed at the system level
			systemAverageSpeed = sumSpeed / cars.size();
			//finish checking one road, check number of cars
			if (cars.size() < 0){//4 should be changed to 0 in the final cpp file
				stop = true;
			}
	}//closing bracket for outer for loop
}


=======
				if (decision){
					myBehaviour->increaseSpeed(*c, roads);
					//cout << (*r)->getName() << " " << (*c)->getName() << ": not too close to the car in the front! do increase speed" << endl;
					  cout << "Vehicle: not too close to the car in the front! do increase speed" << endl;
				}
				else{
					//when one is too close to the vehicle in the front and can't increase speed, he checks to see if it's possible to overtake - if not possible - slow down
					if (myBehaviour->scanOtherSide(cars, *r, *c)){
						cout << "\nOvertaking ************************************************"; 
					}
					else{
						myBehaviour->reduceSpeed(*c, roads);
						//cout << (*r)->getName() << " " << (*c)->getName() << ": too close to the car in the front! do reduce speed" << endl;
						  cout << "Vehicle: too close to the car in the front! do reduce speed" << endl;
					}
				}
				//get speeds of all cars and add them up
				sumSpeed += (*c)->getSpeed();
			}

			//calculate average speed at the system level
			systemAverageSpeed = sumSpeed / cars.size();
			cout << "system average speed: " << systemAverageSpeed << endl;
			//finish checking one road, check number of cars
			if (cars.size() < 0){//4 should be changed to 0 in the final cpp file
				cout << "number of cars on road(x-coordinate) " << (*r)->GetX() << " is: " << cars.size() << endl;
				stop = true;
				break;
			}
		}//closing bracket for outer for loop
}

>>>>>>> origin/master
bool Logic::simulationOver()
{
       return stop;
}
<<<<<<< HEAD
 
=======

>>>>>>> origin/master

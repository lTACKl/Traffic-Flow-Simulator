#include "Logic.h"
#include "Behaviour.h"
#include "Vehicle.h"
#include "Layout.h"
#include <vector>
#include<iostream>

using namespace std;

Logic::Logic() {
}

Logic::Logic(vector<Vehicle*> cars, vector<Layout*> roads ){
    this->cars = cars;
    this->roads = roads;
	stop = false;
	
}

Logic::~Logic() {
}

vector<Vehicle*> Logic:: getCars(){
    return cars;
}

void Logic:: setCars(vector<Vehicle*> cars){
    this->cars = cars;
}

vector<Layout*> Logic:: getRoads(){
    return roads;
}

void Logic::setRoads(vector<Layout*> roads){
    this->roads = roads;
}

//scan all the vehicles on all the roads to adjust driver's behavior
void Logic:: scan(){
    stop = false;
    Behaviour *myBehaviour = new Behaviour();
    bool decision;
    //iterate through the vehicles on each road and help each car to increase/reduce speed when necessary
    vector<Vehicle*>::iterator c;
    vector<Layout*>::iterator r;
    for(r=roads.begin(); r!=roads.end(); ++r)
    {
		for(c=cars.begin(); c!=cars.end(); ++c)
        {
			decision = myBehaviour->scanYourSide(cars, *r, *c);
            if(decision){
				myBehaviour->increaseSpeed(*c, roads);
				cout << "not too close! do increase speed" << endl;
            }
            else{
				myBehaviour->reduceSpeed(*c, roads);
				cout << "too close! do reduce speed" << endl;
            }
               
		}
        //finish checking one road, check number of cars
        if(cars.size() < 0){//4 should be changed to 0 in the final cpp file
			cout << "number of cars on road(x-coordinate) " << (*r)->GetX() << " is: " << cars.size() << endl;
			stop = true;
        }
   }
}
bool Logic::simulationOver()
{
	return stop;
}






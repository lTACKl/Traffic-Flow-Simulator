#include "Logic.h"
//#include "GUI.h"
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
    //GUI *gui = new GUI();
    bool stop = false;
    Behaviour *myBehaviour = 0;
    bool decision;
    int carX,roadPositionX;
    //condition for the while loop below: 1.there are still cars left on the road 2.the GUI stop button has not been pressed
    while(!stop){
         //iterate through the vehicles on each road and help each car to increase/reduce speed when necessary
         vector<Vehicle*>::iterator c;
         vector<Layout*>::iterator r;
         for(r=roads.begin(); r!=roads.end(); ++r)
        {
             for(c=cars.begin(); c!=cars.end(); ++c)
            {
                //check all the cars on the same road
                 carX = (*c)->getx();
                 roadPositionX = (*r)->getx();
                     if(roadPositionX == carX){  //"Collin: We are on the same X xo-ordinate therefore the same road"
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
            }
             //finish checking one road, check number of cars
             if(cars.size() < 4){//4 should be changed to 0 in the final cpp file
               cout << "number of cars on road(x-coordinate) " << (*r)->getx() << " is: " << cars.size() << endl;
               stop = true;
               //use goto statement to break out of the loop
               goto end;
             }
             //find out if the stop button has been pressed in the GUI or not
             //if(gui->stopButtonPressed()){
             //  stop = true;
             //  goto end;
             //}
         }
         end:
         cout << "game over: bool stop is true" << endl;
   }
}


#include "Logic.h"
#include "GUI.h"
#include <vector>

using namespace std;

Logic::Logic() {
}

Logic(vector<Vehicle*> cars, vector<Layout*> roads){
    this->cars = cars;
    this->roads = roads;
}

Logic::~Logic() {
}

vector<Vehicle*>::Logic getCars(){
    return cars;
}

void Logic:: setCars(vector<Vehicle*> cars){
    this->cars = cars;
}

vector<Layout*>::Logic getRoads(){
    return roads;
}

void Logic:: setRoads(vector<Layout*> roads){
    this->roads = roads;
}

//scan to adjust driver's behavior
void Logic:: scan(Layout *road){
    GUI *gui;
    boolean stop = false;
    Behavior *myBehavior;
    Vehicle *car;
    boolean tooClose;
    //condition for the while loop below: 1. the simulation is still running & 2. there are still cars left on the road
    while((!stop) && cars.size() > 0){
         //find out if the stop button has been pressed in the GUI or not
         stop = gui->stopButtonPressed();
         //iterate through the vehicles on the road and help each car to increase/reduce speed when necessary
         vector<Vehicle*>::iterator i;
         for(i=cars.begin(); i!=cars.end(); ++i)
        {
            car = i;
            tooClose = myBehavior->scanYourSide(cars, road, car);
            if(tooClose){
            myBehavior->reduceSpeed(car, roads);
            }
            else{
            myBehavior->increaseSpeed(car, roads);
            }
        }
   }
}


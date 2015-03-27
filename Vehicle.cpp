#include "vehicle.h"

Vehicle::Vehicle(){

}

Vehicle::Vehicle( int speed, double aggression, int x, int y, int w, int h, string direction){
    this->speed = speed;
    this->aggression = aggression;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->direction = direction;
}


void Vehicle::setSpeed(int speed){
    this->speed = speed;  //keith change speed = speed to this.speed = speed, same for aggression
}

void Vehicle::setAggression(double aggression){
    this->aggression = aggression;
}

int Vehicle::getSpeed(){
    return speed;
}

double Vehicle::getAggression(){
    return aggression;
}

int Vehicle::getx(){
 return x;
}


int Vehicle::gety(){
 return y;
}



int Vehicle::getw(){
 return w;
}



int Vehicle::geth(){
 return h;
}

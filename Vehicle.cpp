#include "stdafx.h"
#include "Vehicle.h"
#include "drawable.h"

Vehicle::Vehicle(){

}

Vehicle::Vehicle(SDL_Renderer *passed_Renderer, std::string filePath, int speed, double aggression, int x, int y, int w, int h):Drawable(passed_Renderer, filePath, x, y, w, h){
	this->speed = speed;
	this->aggression = aggression;
}


void Vehicle::setSpeed(int speed){
	speed = speed;
}	

void Vehicle::setAggression(double aggression){
	aggression = aggression;
}

int Vehicle::getSpeed(){
	return speed;	
}

double Vehicle::getAggression(){
	return aggression;
}



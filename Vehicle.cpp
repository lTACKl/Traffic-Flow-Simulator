#include "stdafx.h"
#include "Vehicle.h"
#include "drawable.h"

Vehicle::Vehicle()
{

}

Vehicle::Vehicle(SDL_Renderer *passed_Renderer, std::string filePath, int x, int y, int w, int h, int speed, double aggression, std::string direction):Drawable(passed_Renderer, filePath, x, y, w, h)
{
	this->speed = speed;
	this->aggression = aggression;
	this->direction = direction;
}


void Vehicle::setSpeed(int speed){
	speed = speed;
}	

void Vehicle::setAggression(double aggression)
{
	aggression = aggression;
}
void Vehicle::setDirection(std::string direction)
{
	direction = direction;
}

int Vehicle::getSpeed(){
	return speed;	
}

double Vehicle::getAggression(){
	return aggression;
}

std::string Vehicle::getDirection(){
    return this->direction;
}
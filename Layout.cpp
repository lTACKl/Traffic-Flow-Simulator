#include "stdafx.h"
#include "Layout.h"
#include "drawable.h"

Layout::Layout(){

}

Layout::Layout(SDL_Renderer *passed_Renderer, std::string filePath, int x, int y, int w, int h, int speedLimit):Drawable(passed_Renderer, filePath, x, y, w, h){
 this->speedLimit = speedLimit;
}

void Layout::setSpeedLimit(int speedLimit){
	speedLimit = speedLimit;
}	

int Layout::getSpeedLimit(){
	return speedLimit;
}


/*
void Layout::roadConditions(String conditions){
}

String Layout::getRoadConditions(){
	return roadConditions;
}
*/




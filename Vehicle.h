#pragma once
#include "stdafx.h"
#include "drawable.h"

class Vehicle : public Drawable{
	
	private:
		int speed;
		double aggression;
		
	public:
		Vehicle(void);
		Vehicle(SDL_Renderer *passed_Renderer, std::string filePath, int speed, double aggression, int x, int y, int w, int h);
		~Vehicle(void);
		
		void setSpeed(int speed);	
		void setAggression(double aggression);	

		int getSpeed();
		double getAggression();
		
};
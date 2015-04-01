#pragma once
#include "stdafx.h"
#include "drawable.h"
#include <string>

class Vehicle : public Drawable
{
	private:
		int speed;
		double aggression;
		std::string direction;
		
	public:
		Vehicle(void);
		Vehicle(SDL_Renderer *passed_Renderer, std::string filePath, int x, int y, int w, int h, int speed, double aggression, std::string direction);
		~Vehicle(void);
		
		void setSpeed(int speed);	
		void setAggression(double aggression);	
		void setDirection(std::string direction);

		int getSpeed();
		double getAggression();
		std::string getDirection();
};
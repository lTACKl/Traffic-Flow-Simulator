#pragma once
#include "stdafx.h"
#include "drawable.h"

class Layout : public Drawable{

	private:
		int speedLimit;
		
	public:
		Layout(void);
		Layout(SDL_Renderer *passed_Renderer, std::string filePath, int speedLimit, int x, int y, int w, int h);
		~Layout(void);

		void setSpeedLimit(int speedLimit);	
		
		int getSpeedLimit();

		/*
		void setRoadConditions(string roadConditions);
		string getRoadConditions();
		*/
	
};
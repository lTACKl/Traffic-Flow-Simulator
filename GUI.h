#pragma once
#include "stdafx.h"
#include <vector>
#include "Drawable.h"
#include "Vehicle.h"
#include "Layout.h"
#include "Logic.h"

class GUI
{
public:
	GUI(void);
	~GUI(void);

	SDL_Renderer *Get_Renderer(void);
	SDL_Event *Get_Main_Event(void);

private:
	// requirements to open window
	SDL_Window *main_Window;
	SDL_Renderer *main_Renderer;
	SDL_Event *main_Event;

	// requirements to keep system loop open
	bool quit_Loop;
	bool quit_Simulation;

	// main loop call
	void MainLoop();
	void displayImages();

	// hardcoding in vairables for first itteration
	Vehicle *car1;
	Vehicle *car2;

	Layout *road1;

	// need logic object to call the logic control class
	Logic *logic;

	// storage for all our drawable objects, used to itterate through them to draw to the screen
	std::vector<Drawable*> drawables;

	// storage for all Vehicle object
	std::vector<Vehicle*> vehicles;

	// storage for all Layout Objects
	std::vector<Layout*> roads;

};


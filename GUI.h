#pragma once
#include "stdafx.h"
#include <vector>
#include "Drawable.h"
#include "Vehicle.h"
#include "Layout.h"
#include "Logic.h"
#include "ButtonObject.h"
#include "GUIStates.h"
#include <sstream>
#include "Report.h"


class GUI
{
	friend class AbstractState;
public:
	GUI(void);
	~GUI(void);

	SDL_Renderer *Get_Renderer(void);
	SDL_Event *Get_Main_Event(void);
	std::vector<Vehicle*>& getVehicles();
	std::vector<Layout*>& getRoads();
	void handleEvents();
	void setRunSimulation(bool rSim);
	void sortDrawables();

	// State behaviour

	void addRoad();
	void addVehicle();
	void runSimulation();
	void stopSimulation();
	void viewReport();

	// Report
	void showMessage(const char* c);
	void showReport(const char* c);



private:
	// requirements to open window
	SDL_Window *main_Window;
	SDL_Renderer *main_Renderer;
	SDL_Event *main_Event;

	// requirements to keep system loop open
	bool quit_Loop;
	bool run_Simulation;

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

	// Buttons
	ButtonObject *roadButton;
	ButtonObject *vehicleButton;
	ButtonObject *runButton;
	ButtonObject *stopButton;
	ButtonObject *reportButton;

	int mousePointX;
	int mousePointY;
	int last_Time_Checked;

	// State behaviour
	AbstractState *mState;

	// Report

	string textMessage;

	Report *reportObj;


};


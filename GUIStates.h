#pragma once
#include "GUI.h"
#include "stdafx.h"
#include <exception>
#include <stdexcept>

//class GUIStates
//{
//public:
//	GUIStates(void);
//	~GUIStates(void);
//};

class GUI;

class AbstractState {
public:
	virtual void addRoad(GUI &gui ) = 0;
	virtual void addVehicle(GUI &gui ) = 0;
	virtual void runSimulation(GUI &gui ) = 0;
	virtual void stopSimulation(GUI &gui ) = 0;
	virtual void viewReport(GUI &gui ) = 0;
	virtual ~AbstractState();

protected:
	void setState(GUI &gui, AbstractState *state);
	// will have to add other methods such as draw in here

};

class Setup : public AbstractState {
public:
	virtual void addRoad(GUI &gui );
	virtual void addVehicle(GUI &gui );
	virtual void runSimulation(GUI &gui );
	virtual void stopSimulation(GUI &gui );
	virtual void viewReport(GUI &gui );
	virtual ~Setup();

};

class Simulation : public AbstractState {
public:
	virtual void addRoad(GUI &gui );
	virtual void addVehicle(GUI &gui );
	virtual void runSimulation(GUI &gui );
	virtual void stopSimulation(GUI &gui );
	virtual void viewReport(GUI &gui );
	virtual ~Simulation();

};

class ReportState : public AbstractState {
public:
	virtual void addRoad(GUI &gui );
	virtual void addVehicle(GUI &gui );
	virtual void runSimulation(GUI &gui );
	virtual void stopSimulation(GUI &gui );
	virtual void viewReport(GUI &gui );
	virtual ~ReportState();

};

#include "GUIStates.h"


//GUIStates::GUIStates(void)
//{
//}


//GUIStates::~GUIStates(void)
//{
//}

AbstractState::~AbstractState() 
{
}

void AbstractState::setState(GUI &gui, AbstractState *state)
{
	AbstractState *aux = gui.mState;
	gui.mState = state;
	delete aux;
}


Setup::~Setup()
{
}

void Setup::addRoad(GUI &gui)
{
	// code to add road here
	// check to see if any roads have been added before
	if(gui.getRoads().size() == 0) {
		Layout * temp = new Layout (gui.Get_Renderer(), "roadVertical.png",0,0,100,900,100); //x y w h speedlimit
		gui.getRoads().push_back(temp);
	}/*else {
		Layout * temp = new Layout (gui.Get_Renderer(), "roadEdit.png",5,5,30,1000,100); //x y w h speedlimit
		gui.getRoads().push_back(temp);
		std::cout<< "adding road " << std::endl;
		std::cout<< gui.getRoads().size() << std::endl;
	}
	*/
	
}

void Setup::addVehicle(GUI &gui)
{
	// code to add vehicle here
	// check to see if no of vehicles is under max(3)
	if(gui.getVehicles().size() < 4) {
		if(gui.getVehicles().size() == 0) {
			Vehicle * temp = new Vehicle(gui.Get_Renderer(), "carRedUp.png",10,860,30,30,20,0.1,"North"); 

			gui.getVehicles().push_back(temp);
		}else if(gui.getVehicles().size() == 1) {
			Vehicle * temp = new Vehicle(gui.Get_Renderer(), "carRedUp.png",10,(850 - (gui.getVehicles().size() * 45)),30,30,20,1.6,"North");

			gui.getVehicles().push_back(temp);
		}
		 else if(gui.getVehicles().size() == 2) {
			Vehicle * temp = new Vehicle(gui.Get_Renderer(), "carRedUp.png",10,(850 - (gui.getVehicles().size() * 45)),30,30,20,0.1,"North");

			gui.getVehicles().push_back(temp);
		}
		 else {
			Vehicle * temp = new Vehicle(gui.Get_Renderer(), "carRedDown.png",70,700,30,30,50,2.0,"South");

			gui.getVehicles().push_back(temp);
		}
	}

}

void Setup::runSimulation(GUI &gui)
{
	if((gui.getVehicles().size() >= 1) && (gui.getRoads().size() >= 1)) {
		std::cout<< "Running simulation " << std::endl;
		gui.setRunSimulation(true);
		setState(gui, new Simulation());
	}
	
}
void Setup::stopSimulation(GUI &gui)
{
	// throw error, Simulation is not running
	gui.showMessage("Simulation is not running");
	SDL_Delay(1000);	//we delay, so we can see the message

}
void Setup::viewReport(GUI &gui)
{
	// throw error, Simulation has not run
	gui.showMessage("Simulation has not run");
	SDL_Delay(1000);	
}




Simulation::~Simulation()
{
}

void Simulation::addRoad(GUI &gui)
{
	//throw error, Simulation is already running
	gui.showMessage("Simulation is already running");
	SDL_Delay(1000);

}

void Simulation::addVehicle(GUI &gui)
{
	// throw error, Simulation is already running
	gui.showMessage("Simulation is already running");
	SDL_Delay(1000);
}

void Simulation::runSimulation(GUI &gui)
{
	// throw error, Simulation is already running
	gui.showMessage("Simulation is already running");
	SDL_Delay(1000);

}

void Simulation::stopSimulation(GUI &gui)
{
	gui.setRunSimulation(false);
	std::cout<< "Stopping simulation " << std::endl;
	gui.showMessage("Stopping simulation");
	SDL_Delay(1000);
	setState(gui, new ReportState());
}

void Simulation::viewReport(GUI &gui)
{
	// throw error, Simulation is running, stop simulation first
	gui.showMessage("Simulation is running, stop simulation first");
	SDL_Delay(1000);
}




ReportState::~ReportState()
{
}

void ReportState::addRoad(GUI &gui)
{
	// display message that state is being changed to Setup, press the add road button again
	setState(gui, new Setup());
	gui.showMessage("State being changed to Setup, press the add road button again");
	SDL_Delay(1000);
}

void ReportState::addVehicle(GUI &gui)
{
	// display message that state is being changed to Setup, press the add vehicle button again
	setState(gui, new Setup());
	gui.showMessage("State being changed to Setup, press the add vehicle button again");
	SDL_Delay(1000);
}

void ReportState::runSimulation(GUI &gui)
{
	// message, Running simulation with same roards and cars
	gui.setRunSimulation(true);
	cout<<"Running same simulation "<< endl;
	setState(gui, new Simulation());
	gui.showMessage("Running simulation with same roards and cars");
	SDL_Delay(1000);
}

void ReportState::stopSimulation(GUI &gui)
{
	// throw error, Simulation not running
	gui.showMessage("Simulation not running");
	SDL_Delay(1000);
}
void ReportState::viewReport(GUI &gui)
{
	// code to view report goes in here
	gui.showReport("");
	SDL_Delay(5000);
}
#include "GUI.h"


GUI::GUI(void) : mState(new Setup()) //State behaviour, on start up state is set to Setup()
{
	SDL_Init(SDL_INIT_VIDEO);
	quit_Loop = false;
	run_Simulation = false;
	//create main window, set pointer to null then values 
	main_Window = NULL;
	main_Window = SDL_CreateWindow("Traffic Flow Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900, SDL_WINDOW_SHOWN);

	if(main_Window == NULL) {
		std::cout << "Window could not be created" << std::endl;
		quit_Loop = true;
	}

	//create main renderer, set pointer to null then values
	main_Renderer = NULL;
	main_Renderer = SDL_CreateRenderer(main_Window, -1, SDL_RENDERER_ACCELERATED);
	main_Event = new SDL_Event();

	last_Time_Checked = SDL_GetTicks();
		

	roadButton = NULL;
	vehicleButton = NULL;
	runButton = NULL;
	stopButton = NULL;
	reportButton = NULL;
	int x = 950, y = 0, w = 227, h = 40;
	roadButton = new ButtonObject(main_Renderer, "AddARoadBtn.png", x , 50 , w , h);
	vehicleButton = new ButtonObject(main_Renderer, "AddAVehicleBtn.png", x , 150 , w , h);
	runButton = new ButtonObject(main_Renderer, "RunSimulationBtn.png", x , 250 , w , h);
	stopButton = new ButtonObject(main_Renderer, "StopSimulationBtn.png", x , 350 , w , h);
	reportButton = new ButtonObject(main_Renderer, "ViewReportBtn.png", x , 450 , w , h);

	
	// initilise report
	reportObj = new Report();

	MainLoop();
}


GUI::~GUI(void)
{
	delete main_Event;
	delete mState;
	SDL_DestroyWindow(main_Window);
	SDL_DestroyRenderer(main_Renderer);
	SDL_Quit();
}

SDL_Renderer *GUI::Get_Renderer()
{
	return main_Renderer;
}
SDL_Event * GUI::Get_Main_Event()
{
	return main_Event;
}

void GUI::MainLoop()
{

	while(!quit_Loop && main_Event->type != SDL_QUIT) {
		//last_Time_Checked = SDL_GetTicks();
		displayImages();

		while(run_Simulation && main_Event->type != SDL_QUIT) {
			if ( (last_Time_Checked + 25) < SDL_GetTicks()) {
				logic = new Logic(vehicles, roads);
				logic->scan();
				//last_Time_Checked = SDL_GetTicks();
				displayImages();

				// this call will kill the simulation if the no of vehicals is 0
				// need to change the state here
				if(logic->simulationOver()) {
					run_Simulation = !logic->simulationOver();
				}
				//quit_Simulation = true;
				last_Time_Checked = SDL_GetTicks();
			}
		}

	}

}

void GUI::displayImages()
{

	if( SDL_PollEvent( main_Event ) )
    {
          //Handle button events
          handleEvents();
    }

	SDL_RenderClear(main_Renderer);
	sortDrawables();

	for(std::vector<Drawable*>::iterator i = drawables.begin(); i != drawables.end(); ++i) {
				(*i)->Draw();
	}
	
	SDL_RenderPresent(main_Renderer);

}

std::vector<Vehicle*>& GUI::getVehicles()
{
	return vehicles;
}
std::vector<Layout*>& GUI::getRoads()
{
	return roads;
}

void GUI::handleEvents()
{
	//buttonClicked
		if(main_Event->type == SDL_MOUSEBUTTONDOWN ) {
			// this will read left mouse clicks
			if(main_Event->button.button == SDL_BUTTON_LEFT) {
				//add vehicles
				// this gets the mouse point at a given time, In this case, when the left mouse button is clicked
				mousePointX = main_Event->button.x;
				mousePointY = main_Event->button.y;
				if(roadButton->posOverButton(mousePointX,mousePointY)) {
					// add a road button was pressed
					addRoad();
				}
				if(vehicleButton->posOverButton(mousePointX,mousePointY)) {
					// add a vehicle button was pressed
					addVehicle();
				}
				if(runButton->posOverButton(mousePointX,mousePointY)) {
					// run simulation button was pressed
					runSimulation();
				}
				if(stopButton->posOverButton(mousePointX,mousePointY)) {
					// stop simulation button was pressed
					stopSimulation();
				}
				if(reportButton->posOverButton(mousePointX,mousePointY)) {
					// report button was pressed
					viewReport();
				}
			}
		}

}

void GUI::setRunSimulation(bool rSim)
{
	run_Simulation = rSim;
}

void GUI::sortDrawables()
{
	drawables.clear();

	for(std::vector<Layout*>::iterator i = roads.begin(); i != roads.end(); ++i) {
		drawables.push_back((*i));
	}
	for(std::vector<Vehicle*>::iterator i = vehicles.begin(); i != vehicles.end(); ++i) {
		drawables.push_back((*i));
	}
	//Add buttons to drawables list
	drawables.push_back(roadButton);
	drawables.push_back(vehicleButton);
	drawables.push_back(runButton);
	drawables.push_back(stopButton);
	drawables.push_back(reportButton);

}

// State behaviour calls
void GUI::addRoad()
{
	mState->addRoad(*this);
}

void GUI::addVehicle()
{
	mState->addVehicle(*this);
}

void GUI::runSimulation()
{
	mState->runSimulation(*this);
}

void GUI::stopSimulation()
{
	mState->stopSimulation(*this);
}

void GUI::viewReport()
{
	mState->viewReport(*this);
}

void GUI::showMessage(const char* c)	//shows the message to the screen for a frame
{
	reportObj->showMessage(c, main_Renderer);

}

void GUI::showReport(const char* c)	
{
	reportObj->showReport( c, main_Renderer , roads.size() , vehicles.size() );

}
#include "GUI.h"


GUI::GUI(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	quit_Loop = false;
	quit_Simulation = false;
	//create main window, set pointer to null then values 
	main_Window = NULL;
	main_Window = SDL_CreateWindow("Traffic Flow Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500, SDL_WINDOW_SHOWN);

	if(main_Window == NULL) {
		std::cout << "Window could not be created" << std::endl;
		quit_Loop = true;
	}

	//create main renderer, set pointer to null then values
	main_Renderer = NULL;
	main_Renderer = SDL_CreateRenderer(main_Window, -1, SDL_RENDERER_ACCELERATED);
	main_Event = new SDL_Event();

	
	// add vehicles
	// put them in a vector
	// add layout
	// add vehicles and layout to drawable object vector
	// will move this code to inside the main loop in future itterations to accomidate button clicks
	road1 = new Layout(main_Renderer, "roadEdit.png", 0, 175, 700, 75, 50);
	car1 = new Vehicle(main_Renderer, "carRedLeft.png", 645, 213, 55, 35, 20, 1.2); 
	car2 = new Vehicle(main_Renderer, "carRedRight.png", 0, 175, 55, 35, 20, 1.2); 
	
	drawables.push_back(road1);
	drawables.push_back(car1);
	drawables.push_back(car2);
	

	vehicles.push_back(car1);
	vehicles.push_back(car2);


	MainLoop();
}


GUI::~GUI(void)
{
	delete main_Event;
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
		SDL_PollEvent(main_Event);
		SDL_RenderClear(main_Renderer);


		//if(main_Event->type == ) {
			//add vehicles
		//}//buttonClicked

		// TODO:: loop code such as draw goes in this space
		for(std::vector<Drawable*>::iterator i = drawables.begin(); i != drawables.end(); ++i) {
			(*i)->Draw();
		}

		//logic = new Logic (arguments);
		while(!quit_Simulation) {
			//logic->recordAvgSpeed();


			//if(main_Event->type == ) {
			//buttonClicked to stop simulation
		//}//buttonClicked
			quit_Simulation = true;

		}



		SDL_RenderPresent(main_Renderer);
	}

}

bool GUI::stopButtonPressed()
{
	return quit_Simulation;
}

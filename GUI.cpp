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
	//road1 = new Layout(main_Renderer, "roadEdit.png", 0, 175, 700, 75, 50);
	//car1 = new Vehicle(main_Renderer, "carRedLeft.png", 645, 213, 55, 35, 20, 1.2, "West"); 
	//car2 = new Vehicle(main_Renderer, "carRedRight.png", 0, 175, 55, 35, 20, 1.2, "East"); 

	Vehicle *  v1 = new Vehicle(main_Renderer, "carRedLeft.png",50,50,2,2,50,2.0,"East");  //Speed Aggressiveness x y w h direction
	Vehicle * v2 = new Vehicle(main_Renderer, "carRedLeft.png",70,50,2,2,100,0.2,"East");
	Vehicle * v3 = new Vehicle(main_Renderer, "carRedLeft.png",80,50,2,2,50,2.0,"East");  //Distance between v3 and v1 = 10 which is 5 car lengths ahead
	Layout * l1 = new Layout (main_Renderer, "roadEdit.png",50,50,30,1000,100); //x y w h speedlimit


	//Layout * l1 = new Layout (main_Renderer, "roadEdit.png",50,50,30,1000,100); //x y w h speedlimit
	//Vehicle * v1 = new Vehicle(main_Renderer, "carRedLeft.png",50,50,2,2,50,2.0,"South");  //Speed Aggressiveness x y w h direction
	//Vehicle * v2 = new Vehicle(main_Renderer, "carRedLeft.png",50,70,2,2,100,0.2,"South");
	//Vehicle * v3 = new Vehicle(main_Renderer, "carRedLeft.png",50,80,2,2,50,2.0,"South");
	
	//drawables.push_back(road1);
	//drawables.push_back(car1);
	//drawables.push_back(car2);
	
	drawables.push_back(l1);
	drawables.push_back(v1);
	drawables.push_back(v2);
	drawables.push_back(v3);

	//vehicles.push_back(car1);
	//vehicles.push_back(car2);
	vehicles.push_back(v1);
	vehicles.push_back(v2);
	vehicles.push_back(v3);

	//roads.push_back(road1);
	roads.push_back(l1);

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

		displayImages();

		//if(main_Event->type == ) {
			//add vehicles
		//}//buttonClicked


		while(!quit_Simulation && main_Event->type != SDL_QUIT) {
			logic = new Logic(vehicles, roads);
			logic->scan();

			displayImages();

			// this call will kill the simulation if the no of vehicals is 0
			quit_Simulation = logic->simulationOver();
			//quit_Simulation = true;
		}

	}

}

void GUI::displayImages()
{
	
	SDL_PollEvent(main_Event);
	SDL_RenderClear(main_Renderer);

	for(std::vector<Drawable*>::iterator i = drawables.begin(); i != drawables.end(); ++i) {
				(*i)->Draw();
	}

	SDL_RenderPresent(main_Renderer);
}


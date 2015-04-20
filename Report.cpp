#include "Report.h"


Report::Report()
{
}


Report::~Report()
{
}

void Report::showMessage(const char* c, SDL_Renderer *main_Renderer )	//shows the message to the screen for a frame
{

	//TTF_Init();
	if(TTF_Init() != 0){
		cerr << "TTF_Init() Failed: " << TTF_GetError() << endl;
		SDL_Quit();
		//exit(1);
	}
	TTF_Font *font;
    font = TTF_OpenFont("Tahoma.ttf", 24);
	if(font == NULL){
		cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
		TTF_Quit();
		SDL_Quit();
		//exit(1);
	}

	SDL_Color color = {255,0,0,0}; //red color
	SDL_Surface* surfaceMessage=TTF_RenderText_Solid(font,c,color); //just create the text
	SDL_Texture* Message = SDL_CreateTextureFromSurface(main_Renderer, surfaceMessage);
	SDL_Rect tmprect;//={screen->w/2 - text->w/2,20}; //to the centre in the x axis and 20 in the y
	tmprect.x = 350;  //controls the rect's x coordinate 
	tmprect.y = 600; // controls the rect's y coordinte
	tmprect.w = 100; // controls the width of the rect
	tmprect.h = 100;

	SDL_QueryTexture(Message, NULL, NULL, &tmprect.w, &tmprect.h);
	SDL_RenderCopy(main_Renderer, Message, NULL, &tmprect);	
	SDL_RenderPresent(main_Renderer);

	SDL_RenderPresent(main_Renderer);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(font);
	SDL_DestroyTexture(Message);
	SDL_FreeSurface(surfaceMessage);
}

void Report::showReport(const char* c, SDL_Renderer *main_Renderer, int roadsSize, int vehiclesSize)	
{

	//TTF_Init();
	if(TTF_Init() != 0){
		cerr << "TTF_Init() Failed: " << TTF_GetError() << endl;
		SDL_Quit();
		//exit(1);
	}
	TTF_Font *font;
    font = TTF_OpenFont("Tahoma.ttf", 32);
	if(font == NULL){
		cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
		TTF_Quit();
		SDL_Quit();
		//exit(1);
	}

	textMessage = " ";
	stringstream road;
	stringstream vehicle;
	road << roadsSize;
	vehicle << vehiclesSize;
	string r, v;
	road >> r;
	vehicle >> v;
	SDL_Color color = {0,0,250}; //blue color
	textMessage = "====Traffic Report====";
	textMessage += "     Total Roads                  :";
	textMessage += r; 
	textMessage += "     Total Vehicles               :";
	textMessage += v;
	textMessage += "     Total Accidents             :";
	textMessage += "0";
	textMessage += "     Average Delay              :";
	textMessage += "0";
	SDL_Surface* surfaceMessage=TTF_RenderText_Blended_Wrapped(font,textMessage.c_str(),color,445); //just create the text
	SDL_Texture* Message = SDL_CreateTextureFromSurface(main_Renderer, surfaceMessage);
	SDL_Rect tmprect;//={screen->w/2 - text->w/2,20}; //to the centre in the x axis and 20 in the y
	tmprect.x = 250;  //controls the rect's x coordinate 
	tmprect.y = 100; // controls the rect's y coordinte
	tmprect.w = 100; // controls the width of the rect
	tmprect.h = 100;

	SDL_QueryTexture(Message, NULL, NULL, &tmprect.w, &tmprect.h);
	SDL_RenderCopy(main_Renderer, Message, NULL, &tmprect);	
	SDL_RenderPresent(main_Renderer);

	SDL_RenderPresent(main_Renderer);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(font);
	SDL_DestroyTexture(Message);
	SDL_FreeSurface(surfaceMessage);
}
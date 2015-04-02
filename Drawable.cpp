#include "stdafx.h"
#include "Drawable.h"

Drawable::Drawable(void)
{

}


Drawable::Drawable(SDL_Renderer *passed_Renderer, std::string filePath, int x, int y, int w, int h)
{
	main_Renderer = NULL;
	main_Renderer = passed_Renderer;
	image = NULL;
	image = IMG_LoadTexture(main_Renderer, filePath.c_str());

	if(image == NULL) {
		std::cout << "Could not load " << filePath.c_str() << std::endl;
	}

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

}


Drawable::~Drawable(void)
{
	SDL_DestroyTexture(image);
}

void Drawable::Draw()
{

	SDL_RenderCopy(main_Renderer, image, NULL, &rect);

}

void Drawable::SetX(int x)
{
	rect.x = x;
}

void Drawable::SetY(int y)
{
	rect.y = y;
}

int Drawable::GetX()
{
	return rect.x;
}

int Drawable::GetY()
{
	return rect.y;
}

#include "ButtonObject.h"


ButtonObject::ButtonObject(SDL_Renderer *passed_Renderer, std::string filePath, int x, int y, int w, int h):Drawable(passed_Renderer, filePath, x, y, w, h)
{

}


ButtonObject::~ButtonObject(void)
{
}

int ButtonObject::GetW()
{
	return w;
}

int ButtonObject::GetH()
{
	return h;
}

bool ButtonObject::posOverButton(int passedX, int passedY)
{
	if((passedX > x) && (passedX < (x + w)) && (passedY > y) && (passedY < (y + h)) ) {
		return true;
	}
	return false;
}
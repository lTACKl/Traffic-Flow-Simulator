#pragma once
#include "stdafx.h"
#include "drawable.h"
class ButtonObject : public Drawable
{
public:
	ButtonObject(SDL_Renderer *passed_Renderer, std::string filePath, int x, int y, int w, int h):Drawable(passed_Renderer, filePath, x, y, w, h);
	~ButtonObject(void);
	int GetW();
	int GetH();
	bool posOverButton(int passedX, int passedY);

private:


};


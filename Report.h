#pragma once
#include "stdafx.h"
#include <sstream>

using namespace std;
class Report
{
public:
	Report();
	~Report();

	void showMessage(const char* c , SDL_Renderer *main_Renderer);
	void showReport(const char* c , SDL_Renderer *main_Renderer, int roadsSize, int vehiclesSize);

private:
	string textMessage;
};


#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
class MainGame
{
public:
	MainGame();
	void run();

	private:
		void initSystem();
		SDL_Window* wnd;
		int screenWidth;
		int screenHeight;
};


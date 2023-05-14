#include "MainGame.h"


MainGame::MainGame()
	:wnd(nullptr)
,screenWidth(1204)
,screenHeight(768)
{
}

void MainGame::run()
{
	initSystem();
}

void MainGame::initSystem()
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_EVERYTHING);
		wnd = SDL_CreateWindow("Cat eats grapics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight, SDL_WINDOW_OPENGL);
}
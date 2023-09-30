#include "MainGame.h"
#include <iostream>
#include <string>
#include<SDL_opengl.h>

using namespace std;
void fatalError(const string& s) {
	cerr << "FATAL ERROR" << s << endl;
	cerr << "Press any key to quit";
	char c;
	cin >> c;
	SDL_Quit();
}
MainGame::MainGame()
	:wnd(nullptr)
	, screenWidth(1204)
	, screenHeight(768)
	, state(GameState::PLAY)
{
}

void MainGame::run()
{
	initSystem();
	sprite.init(-0.8f, -0.8f, 0.8f, 0.8f);
	gameloop();
}

void MainGame::gameloop()
{
	while (state != GameState::EXIT) {
		processInput();
		draw();
	}
}


void MainGame::initSystem()
{
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_EVERYTHING);
		wnd = SDL_CreateWindow("Cat eats grapics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight, SDL_WINDOW_OPENGL);
		if (!wnd) {
			fatalError("cannot creat SDL window");
		}
		SDL_GLContext ctxt=SDL_GL_CreateContext(wnd);
		if (!ctxt) {
			fatalError("cannot creat SDL window");
		}
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		glClearColor(0.1f, 0.61f, 0.65f, 1.0f);
}

void MainGame::processInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			state = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << "M(" << e.motion.x << "," << e.motion.y << ")" << endl;;
		}
	}
}
void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sprite.draw();
	glEnd();
	SDL_GL_SwapWindow(wnd);
}

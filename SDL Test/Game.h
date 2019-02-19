#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init( const char* title,int xPos,int yPos,
		int width,int height,bool fullscreen );
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return( isRunning ); }
private:
	bool isRunning = false;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	// ------------------------------------------------- //
	int count = 0;
};
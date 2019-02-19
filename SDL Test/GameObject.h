#pragma once

#include "Game.h"

class GameObject
{
public:
	GameObject( const char* sprSheet,SDL_Renderer* ren,
		int x,int y );
	~GameObject();

	void Update();
	void Render();
private:
	int xPos;
	int yPos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	SDL_Renderer* renderer;
};
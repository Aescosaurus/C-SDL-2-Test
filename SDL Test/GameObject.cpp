#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject( const char* sprSheet,int x,int y )
{
	objTexture = TextureManager::LoadTexture( sprSheet );

	xPos = x;
	yPos = y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	++xPos;
	++yPos;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	dstRect.x = xPos;
	dstRect.y = yPos;
	dstRect.w = srcRect.w * 2;
	dstRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy( Game::renderer,objTexture,
		&srcRect,&dstRect );
}

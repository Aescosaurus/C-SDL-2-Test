#pragma once

#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"

class SpriteComponent
	:
	public Component
{
public:
	SpriteComponent() = default;
	SpriteComponent( const char* path )
	{
		setTex( path );
	}

	void init() override
	{
		transform = &( entity->getComponent<TransformComponent>() );

		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 32;
		srcRect.h = 32;

		dstRect.w = 64;
		dstRect.h = 64;
	}

	void update() override
	{
		dstRect.x = int( transform->position.x );
		dstRect.y = int( transform->position.y );
	}

	void draw() override
	{
		TextureManager::Draw( texture,srcRect,dstRect );
	}

	void setTex( const char* path )
	{
		texture = TextureManager::LoadTexture( path );
	}
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect dstRect;
};
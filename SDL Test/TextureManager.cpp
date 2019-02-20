#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::LoadTexture( const char* path )
{
	SDL_Surface* tempSurface = IMG_Load( path );
	SDL_Texture* tex = SDL_CreateTextureFromSurface(
		Game::renderer,tempSurface );
	SDL_FreeSurface( tempSurface );
	return( tex );
}

void TextureManager::Draw( SDL_Texture* tex,
	SDL_Rect src,SDL_Rect dst )
{
	SDL_RenderCopy( Game::renderer,tex,&src,&dst );
}

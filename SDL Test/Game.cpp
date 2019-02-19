#include "Game.h"

SDL_Texture* playerTex;
SDL_Rect srcRect;
SDL_Rect dstRect;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init( const char* title,int xPos,int yPos,
	int width,int height,bool fullscreen )
{
	int flags = 0;
	if( fullscreen ) flags = SDL_WINDOW_FULLSCREEN;

	if( SDL_Init( SDL_INIT_EVERYTHING ) == 0 )
	{
		std::cout << "(+) Subsystems initialized!"
			<< std::endl;

		window = SDL_CreateWindow( title,xPos,yPos,
			width,height,flags );
		if( window != nullptr )
		{
			std::cout << "(+) Window created!"
				<< std::endl;
		}

		renderer = SDL_CreateRenderer( window,-1,0 );
		if( renderer != nullptr )
		{
			SDL_SetRenderDrawColor( renderer,255,255,255,255 );
			std::cout << "(+) Renderer created!"
				<< std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	SDL_Surface* tempSurface = IMG_Load( "Images/Player.png" );
	playerTex = SDL_CreateTextureFromSurface( renderer,tempSurface );
	SDL_FreeSurface( tempSurface );
}

void Game::handleEvents()
{
	SDL_Event evt;
	SDL_PollEvent( &evt );

	switch( evt.type )
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}

void Game::update()
{
	++count;
	// std::cout << count << std::endl;

	dstRect.w = 64;
	dstRect.h = 64;
	dstRect.x = count;
}

void Game::render()
{
	SDL_RenderClear( renderer );
	// ------------------------------------------------- //
	SDL_RenderCopy( renderer,playerTex,NULL,&dstRect );
	// ------------------------------------------------- //
	SDL_RenderPresent( renderer );
}

void Game::clean()
{
	SDL_DestroyWindow( window );
	SDL_DestroyRenderer( renderer );

	SDL_Quit();
	std::cout << "(+) Game cleaned!" << std::endl;
}
#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "Components.h"
#include "Vector2D.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player( manager.addEntity() );

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

	map = new Map();

	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>( "Images/Player.png" );
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
	manager.refresh();
	manager.update();

	player.getComponent<TransformComponent>()
		.position.Add( Vector2D{ 5.0f,0.0f } );
}

void Game::render()
{
	SDL_RenderClear( renderer );
	// -----------------Do Drawing Here----------------- //
	map->DrawMap();
	manager.draw();
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
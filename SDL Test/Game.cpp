#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"

#include "ECS.h"
#include "Components.h"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer( manager.addEntity() );

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

	player = new GameObject( "Images/Player.png",0,0 );
	enemy = new GameObject( "Images/Enemy.png",50,50 );
	map = new Map();

	newPlayer.addComponent<PositionComponent>();
	newPlayer.getComponent<PositionComponent>().setPos( 500,500 );
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
	player->Update();
	enemy->Update();
	manager.update();
	std::cout << newPlayer.getComponent<PositionComponent>().x()
		<< ", " << newPlayer.getComponent<PositionComponent>().y()
		<< std::endl;
}

void Game::render()
{
	SDL_RenderClear( renderer );
	// ------------------------------------------------- //
	map->DrawMap();
	player->Render();
	enemy->Render();
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
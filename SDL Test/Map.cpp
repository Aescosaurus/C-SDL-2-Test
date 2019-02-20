#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] =
{
	{ 0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,1,2,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map()
{
	dirt = TextureManager::LoadTexture( "Images/Dirt.png" );
	grass = TextureManager::LoadTexture( "Images/Grass.png" );
	water = TextureManager::LoadTexture( "Images/Water.png" );

	LoadMap( lvl1 );

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	dstRect.x = 0;
	dstRect.y = 0;
	dstRect.w = 32;
	dstRect.h = 32;
}

Map::~Map()
{
}

void Map::LoadMap( int arr[20][25] )
{
	for( int row = 0; row < 20; ++row )
	{
		for( int col = 0; col < 25; ++col )
		{
			map[row][col] = arr[row][col];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;

	for( int row = 0; row < 20; ++row )
	{
		for( int col = 0; col < 25; ++col )
		{
			type = map[row][col];

			dstRect.x = col * 32;
			dstRect.y = row * 32;

			switch( type )
			{
			case 0:
				TextureManager::Draw( water,srcRect,dstRect );
				break;
			case 1:
				TextureManager::Draw( grass,srcRect,dstRect );
				break;
			case 2:
				TextureManager::Draw( dirt,srcRect,dstRect );
				break;
			}
		}
	}
}

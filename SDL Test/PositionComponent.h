#pragma once

#include "ECS.h"

class PositionComponent
	:
	public Component
{
public:
	PositionComponent()
	{
		xPos = 0;
		yPos = 0;
	}

	PositionComponent( int x,int y )
	{
		xPos = x;
		yPos = y;
	}

	void update() override
	{
		++xPos;
		++yPos;
	}

	void setPos( int x,int y )
	{
		xPos = x;
		yPos = y;
	}

	int x() { return( xPos ); }
	int y() { return( yPos ); }
private:
	int xPos;
	int yPos;
};
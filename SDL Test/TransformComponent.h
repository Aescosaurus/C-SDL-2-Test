#pragma once

#include "ECS.h"
#include "Vector2D.h"

class TransformComponent
	:
	public Component
{
public:
	TransformComponent()
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}

	TransformComponent( float x,float y )
	{
		position.x = x;
		position.y = y;
	}

	void update() override
	{}
public:
	Vector2D position;
};
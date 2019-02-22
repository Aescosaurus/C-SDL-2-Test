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

	void init() override
	{
		velocity.x = 0.0f;
		velocity.y = 0.0f;
	}

	void update() override
	{
		position.x += velocity.x * float( speed );
		position.y += velocity.y * float( speed );
	}
public:
	Vector2D position;
	Vector2D velocity;

	int speed = 3;
};
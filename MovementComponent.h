#pragma once

#include "Components.h"
#include "Actor.h"


class MovementComponent : public Components
{
public:
	MovementComponent(int windowWidthP, int windowHeightP, float xP, float yP, Actor* ownerP);
	~MovementComponent();
	void Update() override;
	void init() override;
	float getX() { return x; }
	float getY() { return y; }
	float getSpeedX() { return speed_x; }
	float getSpeedY() { return speed_y; }
	void setSpeed();
	
	float getRadius() { return radius; }

	void stop() 
	{
		speed_x = 0;
		speed_y = 0;
	}

	void allowed() { allowedToMove = true; }

	int convertBuffToKey(Vector2 buffer);

private:
	int windowWidth, windowHeight;
	float x, y;
	Vector2 previousPosition;
	float speed_x = 0;
	float speed_y = 0;
	float radius = 8;
	Actor* owner;
	bool allowedToMove = true;
	Vector2 buffer;
};


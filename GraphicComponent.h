#pragma once
#include "Components.h"
#include "MovementComponent.h"
#include "Actor.h"

class GraphicComponent : public Components
{
public:
	GraphicComponent(Actor* ownerP);
	GraphicComponent(Actor* ownerP, float xP, float yP, float radiusP);
	~GraphicComponent();
	void Update() override;
	void init() override;
	Vector2 getVecPosition() 
	{
		Vector2 vec;
		vec.x = x;
		vec.y = y;
		return vec;
	}

	float getRadius() { return radius; }

private:
	Actor* owner;
	float x = 0, y = 0, radius = 0;
};


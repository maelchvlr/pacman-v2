#include "Actor.h"
#include <memory>

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::Update()
{
	for (auto& component : components)
	{
		component->Update();
	}
}

bool Actor::willCollide(float speed_xP, float speed_yP)
{
	return false;
}

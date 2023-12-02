#include "CollisionComponent.h"
#include "GraphicComponent.h"
#include "MovementComponent.h"


CollisionComponent::CollisionComponent(Actor* ownerP)
{
	owner = ownerP;
	center.x = 0;
	center.y = 0;
	radius = 0;
}

CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::Update()
{
	auto graphicComponent = owner->getComponent<GraphicComponent>();
	center = graphicComponent->getVecPosition();
	radius = graphicComponent->getRadius();
}

bool CollisionComponent::isAboutToCollide(Rectangle rect)
{
	auto movement = owner->getComponent<MovementComponent>();
	float speed_x = movement->getSpeedX();
	float speed_y = movement->getSpeedY();
	Vector2 futureCenter;
	futureCenter.x = this->center.x + speed_x;
	futureCenter.y = this->center.y + speed_y;

	
	if (CheckCollisionCircleRec(futureCenter, radius, rect))
	{	
		return true;
	}
	else
	{
		return false;
	}
}

void CollisionComponent::keyCheck(Actor* actor, Map* map, int i, int j)
{
	if (map->map[i - 1][j] == 0)
	{
		allowedKeys[0] = false;
	}
	if (map->map[i+1][j] == 0)
	{
		allowedKeys[1] = false;
	}
	if (map->map[i][j-1] == 0)
	{
		allowedKeys[2] = false;
	}
	if (map->map[i][j+1] == 0)
	{
		allowedKeys[3] = false;
	}

}


#include "GraphicComponent.h"

GraphicComponent::GraphicComponent(Actor* ownerP)
{
    owner = ownerP;
}

GraphicComponent::GraphicComponent(Actor* ownerP, float xP, float yP, float radiusP)
{
    owner = ownerP;
    x = xP;
    y = yP;
    radius = radiusP;
}

GraphicComponent::~GraphicComponent()
{
}

void GraphicComponent::Update()
{
    auto movementComponent = owner->getComponent<MovementComponent>();
    if (movementComponent)
    {
        x = movementComponent->getX();
        y = movementComponent->getY();
        radius = movementComponent->getRadius();
        DrawCircle(x, y, radius, WHITE);
    }
    else
    {
        DrawCircle(x, y, radius, WHITE);
    }
}

void GraphicComponent::init()
{
}

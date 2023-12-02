#include "MovementComponent.h"
#include "CollisionComponent.h"
#include <iostream>

MovementComponent::MovementComponent(int windowWidthP, int windowHeightP, float xP, float yP, Actor* ownerP) :
    windowWidth(windowWidthP),
    windowHeight(windowHeightP),
    x(xP),
    y(yP)
{
    owner = ownerP;
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::init()
{
}

void MovementComponent::setSpeed()
{
    if (buffer.x != 0 || buffer.y != 0)
    {
        int key = convertBuffToKey(buffer);
        if (owner->getComponent<CollisionComponent>()->getAllowedKey(key))
        {
            std::cout << "changed speed, key = " << key << " \n";
            speed_x = buffer.x;
            speed_y = buffer.y;

            buffer.x = 0;
            buffer.y = 0;
        }

    }
}

int MovementComponent::convertBuffToKey(Vector2 buffer)
{
    if (buffer.y == -3) return 0;
    else if (buffer.y == 3) return 1;
    else if (buffer.x == -3) return 2;
    else if (buffer.x == 3) return 3;
}

void MovementComponent::Update()
{
    auto collision = owner->getComponent<CollisionComponent>();
    switch (GetKeyPressed())
    {
    case KEY_UP:
        buffer.x = 0;
        buffer.y = -3;
        break;

    case KEY_DOWN:
        buffer.x = 0;
        buffer.y = 3;
        break;

    case KEY_LEFT:
        buffer.x = -3;
        buffer.y = 0;
        break;

    case KEY_RIGHT:
        buffer.x = 3;
        buffer.y = 0;
        break;

    default:
        break;
    }

    if (collision->getAllowedKey(convertBuffToKey(buffer)) && allowedToMove)
    {
        allowedToMove = false;
        collision->clearKeys();
        speed_x = buffer.x;
        speed_y = buffer.y;
    }

    previousPosition.x = x;
    previousPosition.y = y;

    x += speed_x;
    y += speed_y;

    if (x + radius >= windowWidth || x - radius <= 0)
    {
        speed_x *= -1;
    }

    if (y + radius >= windowHeight || y - radius <= 0)
    {
        speed_y *= -1;
    }

}


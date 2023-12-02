#include <iostream>
#include <raylib.h>
#include <vector>
#include "Actor.h"
#include "Components.h"
#include "GraphicComponent.h"
#include "MovementComponent.h"
#include "CollisionComponent.h"
#include "Map.h"

using namespace std;

int main() {

    Color Dark_Green = Color{ 0, 0, 0, 255 };

    const int screenWidth = 560;
    const int screenHeight = 620;
    std::vector<Actor*> actors;
    std::vector<Rectangle> tiles;

    Actor* ball = new Actor();
    ball->addComponent<MovementComponent>(screenWidth, screenHeight, 280, 470, ball);
    ball->addComponent<GraphicComponent>(ball);
    ball->addComponent<CollisionComponent>(ball);
    actors.push_back(ball);

    
    Map* map = new Map();
 

    Rectangle rect;
    rect.width = 20;
    rect.height = 20;

    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 28; j++)
        {
            if (map->map[i][j] == 0)
            {
                rect.x = j * 20;
                rect.y = i * 20;
                tiles.push_back(rect);
            }
        }
    }


    cout << "Hello World" << endl;

    InitWindow(screenWidth, screenHeight, "bounce bounce modafuka");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(Dark_Green);
        for (auto actor : actors)
        {
            actor->Update();
        }
        for (auto tile : tiles)
        {
            DrawRectangle(tile.x,tile.y,tile.width,tile.height,DARKBLUE);
        }
        EndDrawing();

        for (auto tile : tiles)
        {
            int x = ball->getComponent<MovementComponent>()->getX();
            int y = ball->getComponent<MovementComponent>()->getY();
            int i, j;
            j = ((x) / 20);
            i = ((y) / 20);

            if (ball->getComponent<CollisionComponent>()->isAboutToCollide(tile))
            {
                std::cout << "ABOUT TO COLLIDE" << std::endl;
                ball->getComponent<MovementComponent>()->stop();
                ball->getComponent<CollisionComponent>()->clearKeys();
                ball->getComponent<CollisionComponent>()->keyCheck(ball, map, i, j);
                ball->getComponent<MovementComponent>()->allowed();
            }

            if ((map->map[i][j] == 5 || map->map[i][j] == 6) && (x%20 == 10 && y%20 == 10) )
            {
                ball->getComponent<CollisionComponent>()->clearKeys();
                ball->getComponent<CollisionComponent>()->keyCheck(ball, map, i, j);
                ball->getComponent<MovementComponent>()->setSpeed();
            }
            
            
        }
    }

    CloseWindow();
    return 0;
}
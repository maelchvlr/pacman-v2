#pragma once
#include "Components.h"
#include "Map.h"

class CollisionComponent : public Components
{
public:
	CollisionComponent(Actor* ownerP);
	~CollisionComponent();
	void Update() override;
	bool isAboutToCollide(Rectangle rect);
	void keyCheck(Actor* actor, Map* map, int i, int j);
	bool getAllowedKey(int key) { return allowedKeys[key]; }

	void clearKeys() 
	{ 
		for (int i = 0; i < 4; i++)
		{
			allowedKeys[i] = true;
		}
	}

private:
	bool allowedKeys[4] = { false, false, true, true };
	Actor* owner;
	Vector2 center;
	float radius;


};


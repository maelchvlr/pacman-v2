#pragma once

#include <iostream>
#include "raylib.h"
#include <vector>


class Actor;

class Components
{
public: 
	virtual void Update() = 0;
	virtual void init() {}
};


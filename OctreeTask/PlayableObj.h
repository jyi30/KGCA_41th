#pragma once
#include "Object.h"

class PlayableObj : public Object
{
public:
	void frame(float deltaTime, float gameTime);
};


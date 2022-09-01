#pragma once
#include <vector>
#include <queue>
#include "Vector.h"

struct Sphere
{
	Vector center;
	float radius;
	Sphere() {};
	Sphere(Vector vector, float radius)
	{
		center = vector;
		radius = radius;
	}
};

struct Box
{
	Vector min;
	Vector max;
	Vector size;
	Vector center;

	bool operator == (Box& box)
	{
		if (min == box.min)
		{
			if (size == box.size)
			{
				return true;
			}
		}
		return false;
	}

	Box() {};
	Box(Vector pos, Vector size)
	{
		set(pos, size);
	}

	void set(Vector pos, Vector size)
	{
		min = pos;
		this->size = size;
		max = min + size;
		center = (min + max) / 2.0f;
	}
};

class Collision
{
public:
	static bool boxCollision(Box& box1, Box& box2);
	static bool boxInCollision(Box& box1, Box& box2);
	static bool sphereCollision(Sphere& sphere1, Sphere& sphere2);
};


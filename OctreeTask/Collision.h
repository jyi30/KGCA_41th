#pragma once
#include <vector>
#include <queue>
#include "Vector.h"

enum CollisionResult
{
	RECT_OUT = 0,
	RECT_IN,
	RECT_OVERLAP,
};

struct Sphere
{
	Vector center;
	float radius;
	Sphere() {};
	Sphere(Vector vec, float rad)
	{
		center = vec;
		radius = rad;
	}
};

struct Box
{
	Vector min;
	Vector max;
	Vector size;
	Vector center;

	bool operator == (Box& nBox)
	{
		if (min == nBox.min)
		{
			if (size == nBox.size)
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
	static CollisionResult BoxCollision(Box& box1, Box& box2);
	static bool BoxInCollision(Box& box1, Box& box2);
	static bool SphereCollision(Sphere& sphere1, Sphere& sphere2);
};


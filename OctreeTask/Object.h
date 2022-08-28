#pragma once
#include <string>
#include "Collision.h"

class Object
{
public:
	std::string name;
	float friction;
	float mass;
	float speed;
	Vector direction;
	Box box;
	Sphere sphere;
	Vector acceleration;
	Vector velocity;
	Vector force;

public:
	virtual void init();
	virtual void frame(float deltaTime, float gameTime);
	void addForce(Vector v);
	void setSphere(Vector center, float radius);
	void setSphere(Box box);
	void setPosition(Vector pos, Vector size);
	Object();
	Object(std::string name);
};


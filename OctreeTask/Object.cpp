#include "Object.h"

void Object::init()
{
    //srand((unsigned int)time(NULL));

    Vector pos, size;
    pos.x = 10 + (rand() % 70);
    pos.y = 10 + (rand() % 70);
    pos.z = 10 + (rand() % 70);
    size.x = 5.0f + (rand() % 20);
    size.y = 5.0f + (rand() % 20);
    size.z = 5.0f + (rand() % 20);
    box.set(pos, size);
    setSphere(box);
    direction.x = cos(rand());
    direction.y = sin(rand());
    direction.z = 1.0f - cos(rand());
    speed = 15.0f;
    mass = 70.0f;
    friction = 1.0f;
}

void Object::addForce(Vector v)
{
    force += v;
}

void Object::setSphere(Vector center, float radius)
{
    sphere.center = center;
    sphere.radius = radius;
}

void Object::setSphere(Box box)
{
    sphere.center = box.center;
    sphere.radius = (box.size * 0.5f).length();
}

void Object::setPosition(Vector pos, Vector size)
{
    box.set(pos, size);
    setSphere(box);
}

Object::Object()
{
    init();
}
Object::Object(std::string name)
{
    init();
    this->name = name;
}
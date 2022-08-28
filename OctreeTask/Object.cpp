#include "Object.h"

void Object::init()
{
    Vector pos, size;
    pos.x = 20 + (rand() % 80);
    pos.y = 20 + (rand() % 80);
    pos.z = 20 + (rand() % 80);
    size.x = 5.0f + (rand() % 5);
    size.y = 5.0f + (rand() % 5);
    size.z = 5.0f + (rand() % 5);
    box.set(pos, size);
    setSphere(box);
    direction.x = cos(rand());
    direction.y = sin(rand());
    direction.z = 1.0f - cos(rand());
    direction.Normalized();
    friction = 0.0f;
    mass = 100.0f;
    speed = 10.0f;
}

void Object::frame(float deltaTime, float gameTime)
{

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
    sphere.radius = (box.size * 0.5f).Length();
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
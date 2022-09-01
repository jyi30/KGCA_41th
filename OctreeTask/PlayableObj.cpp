#include "PlayableObj.h"

void PlayableObj::frame(float deltaTime)
{
    speed = 30.0f;
    mass = 10.0f;
    Vector pos = box.min;
    Vector size = box.size;

    Vector vForce = direction * speed * deltaTime;
    addForce(vForce);

    acceleration = force / mass;
    Vector linear = acceleration;
    velocity += linear;

    pos = pos + velocity;

    if (
        fabs(velocity.length()) > Epsilon)
    {
        friction -= deltaTime;
        if (0 >= friction)
        {
            velocity = { 0,0,0 };
            friction = 1.0f;
        }
        velocity *= friction;
    }
    if (pos.x > 100.0f)
    {
        pos.x = 100.0f;
        force = Vector(0, 0, 0);
        velocity = Vector(0, 0, 0);
        direction *= -1.0f;
        friction = 1.0f;
    }
    if (pos.x < 0.0f)
    {
        pos.x = 0.0f;
        force = Vector(0, 0, 0);
        velocity = Vector(0, 0, 0);
        direction.x *= -1.0f;
        friction = 1.0f;
    }
    if (pos.y > 100.0f)
    {
        pos.y = 100.0f;
        force = Vector(0, 0, 0);
        direction.y *= -1.0f;
        friction = 1.0f;
    }
    if (pos.y < 0.0f)
    {
        pos.y = 0.0f;
        force = Vector(0, 0, 0);
        velocity = Vector(0, 0, 0);
        direction.y *= -1.0f;
        friction = 1.0f;
    }
    if (pos.z > 100.0f)
    {
        pos.z = 100.0f;
        force = Vector(0, 0, 0);
        direction.z *= -1.0f;
        friction = 1.0f;
    }
    if (pos.z < 0.0f)
    {
        pos.z = 0.0f;
        force = Vector(0, 0, 0);
        velocity = Vector(0, 0, 0);
        direction.z *= -1.0f;
        friction = 1.0f;
        
    }
    setPosition(pos, size);
}
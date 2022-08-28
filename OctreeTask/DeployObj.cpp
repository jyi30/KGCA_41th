#include "DeployObj.h"

void DeployObj::frame(float deltaTime, float gameTime)
{
	Vector pos = box.min;
	Vector size = box.size;

    velocity = direction * speed * deltaTime;
    pos = pos + velocity;
    friction = (deltaTime * speed * 0.1f);
    speed -= friction;
    if (0 >= speed)
    {
        speed = rand() % 10;
    }

    if (pos.x > 100.0f)
    {
        pos.x = 100.0f;
        direction.x *= -1.0f;
    }
    if (pos.x < 0.0f)
    {
        pos.x = 0.0f;
        direction.x *= -1.0f;
    }
    if (pos.y > 100.0f)
    {
        pos.y = 100.0f;
        direction.y *= -1.0f;
    }
    if (pos.y < 0.0f)
    {
        pos.y = 0.0f;
        direction.y *= -1.0f;
    }
    if (pos.z > 100.0f)
    {
        pos.z = 100.0f;
        direction.z *= -1.0f;
    }
    if (pos.z < 0.0f)
    {
        pos.z = 0.0f;
        direction.z *= -1.0f;
    }
    setPosition(pos, size);
}
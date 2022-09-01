#include "Collision.h"

bool Collision::boxCollision(Box& box1, Box& box2)
{
    float minX;
    float maxX;
    float minY;
    float maxY;
    float minZ;
    float maxZ;
    minX = box1.min.x < box2.min.x ? box1.min.x : box2.min.x;
    minY = box1.min.y < box2.min.y ? box1.min.y : box2.min.y;
    maxX = box1.max.x > box2.max.x ? box1.max.x : box2.max.x;
    maxY = box1.max.y > box2.max.y ? box1.max.y : box2.max.y;
    minZ = box1.min.z < box2.min.z ? box1.min.z : box2.min.z;
    maxZ = box1.max.z > box2.max.z ? box1.max.z : box2.max.z;

    if ((box1.size.x + box2.size.x) >= (maxX - minX))
    {
        if ((box1.size.y + box2.size.y) >= (maxY - minY))
        {
            if ((box1.size.z + box2.size.z) >= (maxZ - minZ))
            {
                Vector min, max;
                Box intersection;
                min.x = box1.min.x > box2.min.x ? box1.min.x : box2.min.x;
                min.y = box1.min.y > box2.min.y ? box1.min.y : box2.min.y;
                min.z = box1.min.z > box2.min.z ? box1.min.z : box2.min.z;

                max.x = box1.max.x < box2.max.x ? box1.max.x : box2.max.x;
                max.y = box1.max.y < box2.max.y ? box1.max.y : box2.max.y;
                max.z = box1.max.z < box2.max.z ? box1.max.z : box2.max.z;

                intersection.set(min, max - min);
                if (intersection == box1 || intersection == box2)
                {
                    return true;
                }
                return true;
            }
        }
    }
    return false;
}

bool Collision::boxInCollision(Box& box1, Box& box2)
{
    if (box1.min <= box2.min)
    {
        if (box1.max >= box2.max)
        {
            return true;
        }
    }
    return false;
}

bool Collision::sphereCollision(Sphere& sphere1, Sphere& sphere2)
{
    float sumRadius = sphere1.radius + sphere2.radius;
    Vector dir = sphere1.center - sphere2.center;
    float distance = dir.length();
    if (distance <= sumRadius)
    {
        return true;
    }

    return false;
}
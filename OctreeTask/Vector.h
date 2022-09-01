#pragma once
#include <iostream>
#include <cstdlib>
#include <math.h>

#define PI 3.141592f
#define DegreeToRadian(x)  (x *(PI / 180.0f))
#define RadianToDegree(x) (x *(180.0f / PI))
#define Epsilon 0.001f

struct Coordinate
{
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float v[3];
	};
};


class Vector : public Coordinate
{
public:
	float length();                
public:
	Vector operator + (Vector& v);
	Vector operator - (Vector& v);
	Vector operator * (float scala);
	Vector operator / (float scala);
	Vector operator += (Vector& v);
	Vector operator -= (Vector& v);
	Vector operator *= (float scala);
	bool operator == (Vector& v);
	bool operator <= (Vector& v);
	bool operator >= (Vector& v);
	Vector();
	Vector(const Vector& v);
	Vector(float x, float y, float z);

};


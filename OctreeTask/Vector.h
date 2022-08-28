#pragma once
#include <iostream>
#include <math.h>

#define PI 3.141592f
#define DegreeToRadian(x)  (x *(PI / 180.0f))
#define RadianToDegree(x) (x *(180.0f / PI))
#define Epsilon 0.001f

struct TFloat
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


class Vector : public TFloat
{
public:
	float LengthSquared();
	float Length();
	void Normalized();
	Vector Identity();
	float Angle(Vector& v);
public:
	Vector operator + (Vector& v);
	Vector operator - (Vector& v);
	Vector operator * (float scala);
	Vector operator / (float scala);
	Vector operator *= (float scala);
	Vector operator += (Vector& v);
	Vector operator -= (Vector& v);
	bool operator == (Vector& v);
	bool operator <= (Vector& v);
	bool operator >= (Vector& v);
	Vector();
	Vector(float x, float y, float z);
	Vector(const Vector& v);
};


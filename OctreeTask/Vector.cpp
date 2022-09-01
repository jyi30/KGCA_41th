#include "Vector.h"

Vector::Vector()
{
	x = 0.0f;
	y = x;
	z = y;
}

Vector::Vector(const Vector& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector::Vector(float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

Vector Vector::operator + (Vector& v)
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator - (Vector& v)
{
	return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator / (float scala)
{
	return Vector(x / scala, y / scala, z / scala);
}

Vector Vector::operator * (float scala)
{
	return Vector(x * scala, y * scala, z * scala);
}

Vector Vector::operator += (Vector& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector Vector::operator -= (Vector& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector Vector::operator *= (float scala)
{
	x *= scala;
	y *= scala;
	z *= scala;
	return *this;
}

bool Vector::operator == (Vector& v)
{
	if (fabs(x - v.x) < Epsilon)
	{
		if (fabs(y - v.y) < Epsilon)
		{
			if (fabs(z - v.z) < Epsilon)
			{
				return true;
			}
		}
	}
	return false;
}

bool Vector::operator <= (Vector& v)
{
	if (fabs(x - v.x) <= Epsilon)
	{
		if (fabs(y - v.y) <= Epsilon)
		{
			if (fabs(z - v.z) <= Epsilon)
			{
				return true;
			}
		}
	}
	return false;
}

bool Vector::operator >= (Vector& v)
{
	if (fabs(x - v.x) >= Epsilon)
	{
		if (fabs(y - v.y) >= Epsilon)
		{
			if (fabs(z - v.z) >= Epsilon)
			{
				return true;
			}
		}
	}
	return false;
}

float Vector::length()
{
	float rt = ((x * x) + (y * y) + (z * z));
	return sqrt(rt);
}

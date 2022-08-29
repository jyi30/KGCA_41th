#include "Vector.h"

Vector::Vector()
{
	x = 0.0f;
	y = x;
	z = y;
}

Vector::Vector(float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

Vector::Vector(const Vector& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector Vector::operator + (Vector& v)
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator - (Vector& v)
{
	return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::operator * (float scala)
{
	return Vector(x * scala, y * scala, z * scala);
}

Vector Vector::operator / (float scala)
{
	return Vector(x / scala, y / scala, z / scala);
}

Vector Vector::operator *= (float scala)
{
	x *= scala;
	y *= scala;
	z *= scala;
	return *this;
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

bool      Vector::operator <= (Vector& b)
{
	if (fabs(x - b.x) <= Epsilon)
	{
		if (fabs(y - b.y) <= Epsilon)
		{
			if (fabs(z - b.z) <= Epsilon)
			{
				return true;
			}
		}
	}
	return false;
}

bool Vector::operator >= (Vector& b)
{
	if (fabs(x - b.x) >= Epsilon)
	{
		if (fabs(y - b.y) >= Epsilon)
		{
			if (fabs(z - b.z) >= Epsilon)
			{
				return true;
			}
		}
	}
	return false;
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

float Vector::lengthRect()
{
	return (x * x + y * y + z * z);
}

float Vector::length()
{
	return sqrt(lengthRect());
}

void Vector::normalized() //정규화
{
	float fInvertLength = 1.0f / length();
	x = x * fInvertLength;
	y = y * fInvertLength;
	z = z * fInvertLength;
}

Vector Vector::identity() //단위벡터로 변환
{
	Vector ret = *this;
	float fInvertLength = 1.0f / length();
	ret.x = ret.x * fInvertLength;
	ret.y = ret.y * fInvertLength;
	ret.z = ret.z * fInvertLength;
	return ret;
}
float Vector::angle(Vector& v)
{
	float fCos = x * v.x + y * v.y + z * v.z;
	fCos = fCos / (length() * v.length());
	float fRadian = acos(fCos);
	float fDegree = RadianToDegree(fRadian);
	return fDegree;
}

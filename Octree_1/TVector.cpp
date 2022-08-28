#include "TVector.h"
///// 3d
TVector::TVector()
{
	x = y = z = 0.0f;
}
TVector::TVector(float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}
TVector::TVector(const TVector& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}
TVector TVector::operator + (TVector& v)
{
	return TVector(x + v.x, y + v.y, z+ v.z);
}
TVector TVector::operator - (TVector& v)
{
	return TVector(x - v.x, y - v.y, z - v.z);
}
TVector TVector::operator * (float scala)
{
	return TVector(x * scala, y * scala, z * scala);
}
TVector TVector::operator / (float scala)
{
	return TVector(x / scala, y / scala, z / scala);
}
TVector TVector::operator *= (float scala)
{
	x *= scala;
	y *= scala;
	z *= scala;
	return *this;
}
TVector TVector::operator += (TVector& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
TVector TVector::operator -= (TVector& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
bool      TVector::operator <= (TVector& b)
{
	if (fabs(x - b.x) <= T_Epsilon)
	{
		if (fabs(y - b.y) <= T_Epsilon)
		{
			if (fabs(z - b.z) <= T_Epsilon)
			{
				return true;
			}
		}
	}
	return false;
}
bool      TVector::operator >= (TVector& b)
{
	if (fabs(x - b.x) >= T_Epsilon)
	{
		if (fabs(y - b.y) >= T_Epsilon)
		{
			if (fabs(z - b.z) >= T_Epsilon)
			{
				return true;
			}
		}
	}
	return false;
}
bool      TVector::operator == (TVector& v)
{
	if (fabs(x - v.x) < T_Epsilon)
	{
		if (fabs(y - v.y) < T_Epsilon)
		{
			if (fabs(z - v.z) < T_Epsilon)
			{
				return true;
			}
		}
	}
	return false;
}

float TVector::LengthSquared()
{
	return (x * x + y * y + z*z);
}

float TVector::Length()
{
	return sqrt(LengthSquared());
}
// 정규화 -> 단위벡터(자신을) 계산
void TVector::Normalized()
{
	float fInvertLength = 1.0f / Length();
	x = x * fInvertLength;
	y = y * fInvertLength;
	z = z * fInvertLength;
}
// 단위벡터 반환
TVector TVector::Identity()
{
	TVector ret = *this;
	float fInvertLength = 1.0f / Length();
	ret.x = ret.x * fInvertLength;
	ret.y = ret.y * fInvertLength;
	ret.z = ret.z * fInvertLength;
	return ret;
}
float     TVector::Angle(TVector& v)
{
	float fCos = x * v.x + y * v.y + z * v.z;//내적
	fCos = fCos / (Length() * v.Length());
	float fRadian = acos(fCos);
	float fDegree = RadianToDegree(fRadian);
	return fDegree;
}


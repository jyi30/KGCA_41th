#include "TVector.h"
TVector2D::TVector2D()
{
	x = y = 0.0f;
}

TVector2D::TVector2D(float x, float y)
{
	v[0] = x;
	v[1] = y;
}

TVector2D::TVector2D(const TVector2D& v)
{
	x = v.x;
	y = v.y;
}
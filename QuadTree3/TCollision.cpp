#include "TCollision.h"
TCollisionType TCollision::rectToRect(TRect& a, TRect& b)
{
	// 0 : 완전 제외
	// 1 : 완전 포함(1) -> 걸쳐있는 상태(2)
	// a.x(10) -----(30)----- a.x2(40)
	//합집합
	float fMinX;
	float fMinY;
	float fMaxX;
	float fMaxY;
	fMinX = a.x1 < b.x1 ? a.x1 : b.x1;
	fMinY = a.y1 < b.y1 ? a.y1 : b.y1;
	fMaxX = a.x2 > b.x2 ? a.x2 : b.x2;
	fMaxY = a.y2 > b.y2 ? a.y2 : b.y2;

	//가로 판정
	if ((a.w + b.w) >= (fMaxX - fMinX))
	{
		//세로 판정
		if ((a.h + b.h) >= (fMaxY - fMinY))
		{
			float x, y, x2, y2;
			TRect Intersect;
			x = a.x1 > b.x1 ? a.x1 : b.y1;
			y = a.y1 > b.y1 ? a.y1 : b.y1;
			x2 = a.x2 < b.x2 ? a.x2 : b.x2;
			y2 = a.y2 < b.y2 ? a.y2 : b.y2;
			Intersect.Set(x, y, x2 - x, y2 - y);
			if (Intersect == a || Intersect == b)
			{
				return TCollisionType::RECT_IN;
			}
			return TCollisionType::RECT_OVERLAP;
		}
	}
	return TCollisionType::RECT_OUT;
}

bool TCollision::rectToInRect(TRect& a, TRect& b)
{
	if (a.x1 <= b.x1)
	{
		if ((a.x1 + a.w) >= b.x1 + b.w)
		{
			if (a.y1 <= b.y1)
			{
				if ((a.y1 + a.h) >= b.y1 + b.h)
				{
					return true;
				}
			}
		}
	}
	return false;
}
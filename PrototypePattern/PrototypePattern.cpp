#include <iostream>

class TGraphicObject
{
public:
	int* pData;
	int iData[100];
	virtual TGraphicObject* Clone() = 0;
public:
	TGraphicObject()
	{

	}
	TGraphicObject(const TGraphicObject& a)
	{
		for (int i = 0; i < 100; i++)
		{
			iData[i] = this->iData[i];
		}
	}
};

class TTriangle : public TGraphicObject
{
public:
	virtual TGraphicObject* NewObject()
	{
		return new TTriangle;
	}
	virtual TGraphicObject* Clone()
	{
		return new TTriangle(*this);
	}
};

int main()
{
	TTriangle* pTriObj = new TTriangle;
	for (int i = 0; i < 100; i++)
	{
		pTriObj->iData[i] = rand();
	}
	TTriangle t = *pTriObj;
	TGraphicObject* pObjA = new TTriangle;
	TGraphicObject* pObjB = pTriObj->Clone();
}
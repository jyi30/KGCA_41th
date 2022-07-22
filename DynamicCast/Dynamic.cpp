#pragma once
#include <iostream>
using namespace std;

class DynamicA
{
	virtual void f();
};

class DynamicB : public DynamicA
{
	virtual void f();
};

class DynamicC : public DynamicA
{
	virtual void f();
};

class DynamicD : public DynamicB, public DynamicC
{
	virtual void f();
};

void f()
{
	DynamicD* pd = new DynamicD;
	DynamicA* pa = dynamic_cast<DynamicA*>(pd);
	DynamicB* pb = dynamic_cast<DynamicB*>(pd);
	DynamicA* pa2 = dynamic_cast<DynamicA*>(pb);
}

int main(void)
{
	f();
}
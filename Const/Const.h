#pragma once
#include <iostream>
using namespace std;

class Const
{
private:
	int* a;
	int b;
public:
	const int* getA();
	void setB(int num) const;
};


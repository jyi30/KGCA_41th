#pragma once
#include <iostream>
#include <cstdio>
using namespace std;

class Cast
{
public:
	int num;
	void constCast(const int num);
	void reinterpretCast(int num);
};


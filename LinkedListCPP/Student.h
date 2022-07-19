#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

struct Student
{
	char name[20];
	int age;
	int score1;
	int score2;
	int score3;
	int total;
	Student* m_pNext;
	Student* m_pPrev;
	Student();
	~Student();
};

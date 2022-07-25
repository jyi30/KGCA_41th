#pragma once
#include <iostream>
using namespace std;

class Student
{
private:
	char name[20];
	int  age;
	int  score1;
	int  score2;
	int  score3;
	int  total;

public:
	Student* newStd();
	Student* newStd(char name[], int age, int score1, int score2, int score3);
	Student();
	~Student();
};
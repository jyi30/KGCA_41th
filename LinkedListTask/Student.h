#define _CRT_SECURE_NO_WARNINGS
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
	Student* newStd(char name[], int age, int score1, int score2, int score3, int total);
	const char* getName();
	void setName(char* name);
	const int getAge();
	void setAge(int age);
	const int getScore1();
	void setScore1(int score1);
	const int getScore2();
	void setScore2(int score2);
	const int getScore3();
	void setScore3(int score3);
	const int getTotal();
	void setTotal(int total);
	Student();
	~Student();
};
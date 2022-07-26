#include "Student.h"

Student::Student()
{
	fill_n(name, 20, 0);
	age = 0;
	score1 = 0;
	score2 = 0;
	score3 = 0;
	total = 0;
}

Student::~Student()
{
	
}

Student* Student::newStd()
{
	Student* student = new Student();

	cout << "이름 : ";
	cin >> student->name;
	cout << "나이 : ";
	cin >> student->age;
	cout << "점수1 :  ";
	cin >> student->score1;
	cout << "점수2 :  ";
	cin >> student->score2;
	cout << "점수3 :  ";
	cin >> student->score3;
	student->total = (student->score1) + (student->score2) + (student->score3);

	return student;
}

Student* Student::newStd(char name[], int age, int score1, int score2, int score3)
{
	Student* student = new Student();
	
	strcpy(student->name, name);
	student->age = age;
	student->score1 = score1;
	student->score2 = score2;
	student->score3 = score3;
	student->total = (student->score1) + (student->score2) + (student->score3);

	return student;
}

const char* Student::getName()
{
	return name;
}

void Student::setName(char name2[])
{
	strncpy(this->name, name2, strlen(name2) + 1);
}

const int Student::getAge()
{
	return age;
}

void Student::setAge(int age)
{
	this->age = age;
}

const int Student::getScore1()
{
	return score1;
}

void Student::setScore1(int score1)
{
	this->score1 = score1;
}

const int Student::getScore2()
{
	return score2;
}

void Student::setScore2(int score2)
{
	this->score2 = score2;
}

const int Student::getScore3()
{
	return score3;
}

void Student::setScore3(int score3)
{
	this->score3 = score3;
}

const int Student::getTotal()
{
	return total;
}

void Student::setTotal(int total)
{
	this->total = total;
}
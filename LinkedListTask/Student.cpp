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

	cout << "�̸� : ";
	cin >> student->name;
	cout << "���� : ";
	cin >> student->age;
	cout << "����1 :  ";
	cin >> student->score1;
	cout << "����2 :  ";
	cin >> student->score2;
	cout << "����3 :  ";
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
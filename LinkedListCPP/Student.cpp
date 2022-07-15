#include "Student.h"

Student::Student()
{
	name[0] = 0;
	age = 0;
	score1 = 0;
	score2 = 0;
	score3 = 0;
	total = 0;
	m_pNext = m_pPrev = nullptr;

}
Student::~Student()
{

}
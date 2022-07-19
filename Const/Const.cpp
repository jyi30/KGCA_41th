#include "Const.h"

const int* Const::getA()
{
	return Const::a;
}

void Const::setB(const int num) const
{
	//Const::b = num; //멤버 변수 수정 불가능
	//num = 30; // 인자 num의 값 수정 불가능
}

int main(void)
{
	Const con;
	//int* result = con.getA(); // const가 아닌 일반 변수로 반환값 대입 불가
	con.setB(30);
}

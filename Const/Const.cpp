#include "Const.h"

const int* Const::getA()
{
	return Const::a;
}

void Const::setB(const int num) const
{
	//Const::b = num; //��� ���� ���� �Ұ���
	//num = 30; // ���� num�� �� ���� �Ұ���
}

int main(void)
{
	Const con;
	//int* result = con.getA(); // const�� �ƴ� �Ϲ� ������ ��ȯ�� ���� �Ұ�
	con.setB(30);
}

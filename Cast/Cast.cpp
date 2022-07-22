#include "Cast.h"

void Cast::constCast(const int num)
{
	//num = 30; -> ���� �߻�

	int* num2 = const_cast<int*>(&num); //const_cast�� ������ �����ͳ� ���۷��� ���� ����Ѵ�.
	*num2 = 40;

	cout << "const_cast ���(���� : 30) : " << *num2 << endl;
}

void Cast::reinterpretCast(int num)
{
	/*int* num3 = reinterpret_cast<int*>(num); 
	cout << "reinterpret_cast(to int*) ���(������ : 30) : " << *num3 << endl;*/ 
	//int -> int * �� ĳ����. �Ҵ���� ���� �ּҸ� �����ϹǷ� ����
	int* ptr2 = &num;
	char* c;

	c = reinterpret_cast<char*>(ptr2);
	cout << "reinterpret_cast ���(int* to char*)(������ : 30) : " << *c << endl;
	printf("reinterpret_cast ���(int* to char* at C)(������ : 30) : %d\n", *c);
}

int main(void)
{
	int num = 30;

	Cast cast;

	cast.constCast(num);
	cast.reinterpretCast(num);

	return 0;
}

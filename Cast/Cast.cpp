#include "Cast.h"

void Cast::constCast(const int num)
{
	//num = 30; -> 예외 발생

	int* num2 = const_cast<int*>(&num); //const_cast는 무조건 포인터나 레퍼런스 간에 사용한다.
	*num2 = 40;

	cout << "const_cast 결과(기존 : 30) : " << *num2 << endl;
}

void Cast::reinterpretCast(int num)
{
	/*int* num3 = reinterpret_cast<int*>(num); 
	cout << "reinterpret_cast(to int*) 결과(기존값 : 30) : " << *num3 << endl;*/ 
	//int -> int * 로 캐스팅. 할당되지 않은 주소를 참조하므로 위험
	int* ptr2 = &num;
	char* c;

	c = reinterpret_cast<char*>(ptr2);
	cout << "reinterpret_cast 결과(int* to char*)(기존값 : 30) : " << *c << endl;
	printf("reinterpret_cast 결과(int* to char* at C)(기존값 : 30) : %d\n", *c);
}

int main(void)
{
	int num = 30;

	Cast cast;

	cast.constCast(num);
	cast.reinterpretCast(num);

	return 0;
}

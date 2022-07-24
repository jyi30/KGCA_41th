#include "LinkedList.h"

int main(void)
{
	TLinkedList<Student> link;
	link.init();
	int select = 0;

	cout << "======================================\n";
	cout << "            학생 관리 기록부           \n";
	cout << "======================================\n";
	cout << "1. 무작위 생성  2. 출력  3. 탐색  4. 추가  5. 삭제\n6. 전체 삭제  7. 저장  8. 불러오기  9. 정렬  0. 종료\n\n";
	cout << "입력 : ";

	cin >> select;

	switch (select)
	{
	case 1: //무작위 생성
	{
		int count = 0;
		cout << "무작위 생성 횟수 입력 : ";
		cin >> count;
		system("cls");
		link.create(count);
	}
	}
}
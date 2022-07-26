#include "DataManager.h"

int main(void)
{
	DataManager dMgr;

	dMgr.init();

	int select = 0;

	while (1)
	{
		cout << "======================================\n";
		cout << "            학생 관리 기록부           \n";
		cout << "======================================\n";
		cout << "1. 무작위 생성  2. 출력  3. 탐색  4. 추가  5. 삭제\n6. 전체 삭제  7. 파일관리  8. 정렬  0. 종료\n\n";
		cout << "입력 : ";

		cin >> select;

		switch (select)
		{
		case 1: //무작위 생성
		{
			if (!dMgr.isFull())
			{
				cout << "\n취소되었습니다.\n\n";
				continue;
			}

			int count = 0;
			cout << "무작위 생성 횟수 입력 : ";
			cin >> count;
			system("cls");

			dMgr.randomCreate(count);

			continue;
		}
		case 2: //전체 출력
		{
			system("cls");
			if (dMgr.isEmpty())
			{
				continue;
			}
			else
			{
				dMgr.print();
			}
			continue;
		}
		case 3: //탐색 후 결과 출력(개선 여지 : 동명이인 대응) -> 탐색 결과를 노드가 아닌 노드 타입 배열(포인터)로 반환하면 가능할 듯
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			char name[30];
			cout << "이름을 입력해주세요 : ";
			cin >> name;
			system("cls");

			dMgr.find(name);

			continue;
		}
		case 4: //추가
		{
			dMgr.insert();

			continue;
		}
		case 5: //삭제
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			char name[30] = { 0, };
			cout << "이름을 입력해주세요 : ";
			cin >> name;

			system("cls");
			dMgr.deleteNode(name);

			continue;
		}
		case 6: //전체 삭제
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			dMgr.deleteNode();

			system("cls");
			cout << "삭제 완료\n\n";

			continue;
		}
		case 7: //파일관리
		{
			int num = 0;
			
			cout << "1. 저장하기\n2. 불러오기\n\n입력 : ";
			cin >> num;

			dMgr.fileCtr(num);
			continue;
		}
		case 8: //정렬
		{
			int num = 0;
			cout << "1. 오름차순\n2. 내림차순\n\n입력 : ";
			cin >> num;

			dMgr.sort(num);
			continue;
		}
		case 0: //종료
		{
			cout << "\n프로그램을 종료합니다.\n\n";

			break;
		}
		default: //없는 메뉴 대응
		{
			system("cls");
			cout << "\n잘못된 입력입니다.\n\n";

			continue;
		}
		}
		break;
	}
}
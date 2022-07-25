#include "DataManager.h"

int main(void)
{
	DataManager dMgr;

	int select = 0;

	while (1)
	{
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

			if (name != NULL)
			{
				dMgr.print(name);
			}

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

			char name[30];
			cout << "이름을 입력해주세요 : ";
			cin >> name;
			dMgr.deleteNode(name);

			system("cls");
			cout << "\n\n삭제 완료!\n\n";

			continue;
		}
		case 6: //전체 삭제
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			//link.deleteNode();

			system("cls");
			cout << "삭제 완료\n\n";

			continue;
		}
		case 7: //저장
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			//link.saveFile();
			continue;
		}
		case 8: //불러오기
		{
			if (link.isFull(&link))
			{
				link.loadFile();
				link.allPrint();
				continue;
			}
			else
			{
				cout << "\n취소되었습니다.\n\n";
				continue;
			}
		}
		case 9: //정렬
		{
			link.sort();
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
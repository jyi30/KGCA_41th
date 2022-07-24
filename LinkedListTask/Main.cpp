#include "LinkedList.h"

int main(void)
{
	TLinkedList<Student> link;
	link.init();
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
			if (!link.isFull(&manage))
			{
				cout << "\n취소되었습니다.\n\n";
				continue;
			}

			int count = 0;
			cout << "무작위 생성 횟수 입력 : ";
			cin >> count;
			system("cls");
			link.create(count);

			continue;
		}
		case 2: //전체 출력
		{
			system("cls");
			manage.allPrint();

			continue;
		}
		case 3: //탐색 후 결과 출력(개선 여지 : 동명이인 대응) -> 탐색 결과를 노드가 아닌 노드 타입 배열(포인터)로 반환하면 가능할 듯
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				system("cls");
				cout << "데이터가 비었습니다!!\n\n";

				continue;
			}

			char name[30];
			cout << "이름을 입력해주세요 : ";
			cin >> name;
			system("cls");

			Student* result = manage.search(name);

			if (result != NULL)
			{
				manage.print(result);
			}

			continue;
		}
		case 4: //추가
		{
			int select = 0;

			cout << "\n1. 제일 앞에 삽입\n2. 제일 뒤에 삽입\n3. 특정 노드 전후에 삽입\n\n";
			cout << "선택 : ";
			cin >> select;


			if (select == 1)
			{
				manage.frontInsert(manage.newNode());
			}
			else if (select == 2)
			{
				manage.backInsert(manage.newNode());
			}
			else
			{
				if (manage.getHead()->m_pNext == manage.getTail())
				{
					system("cls");
					cout << "데이터가 비었습니다!!\n\n";

					continue;
				}

				system("cls");
				manage.allPrint();

				char name[30];
				int location = 0;
				cout << "삽입을 원하는 위치의 학생 이름을 입력해주세요 : ";
				cin >> name;

				Student* result = manage.search(name);

				if (result == NULL)
				{
					system("cls");
					cout << "\n 존재하지 않는 학생입니다.";

					continue;
				}

				while (1)
				{
					cout << "\n삽입 위치 선택(1. 전위, 2. 후위) : ";
					cin >> location;

					if (location < 1 || location > 2)
					{
						cout << "잘못된 입력입니다.";

						continue;
					}
					break;
				}

				manage.insert(manage.newNode(), result, location);
			}

			system("cls");
			manage.allPrint();
			cout << "\n\n삽입 완료!\n\n";

			continue;
		}
		case 5: //삭제
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				system("cls");
				cout << "데이터가 비었습니다!!\n\n";

				continue;
			}

			char name[30];
			cout << "이름을 입력해주세요 : ";
			cin >> name;
			delete(manage.search(name));

			system("cls");
			cout << "\n\n삭제 완료!\n\n";

			continue;
		}
		case 6: //전체 삭제
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				system("cls");
				cout << "데이터가 비었습니다!!\n\n";

				continue;
			}

			manage.deleteAll();

			system("cls");
			cout << "삭제 완료\n\n";

			continue;
		}
		case 7: //저장
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				cout << "저장할 데이터가 없습니다!!\n\n";
				continue;
			}

			manage.saveFile();
			continue;
		}
		case 8: //불러오기
		{
			if (manage.isFull(&manage))
			{
				manage.loadFile();
				manage.allPrint();
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
			manage.sort();
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
#include "listHeader.h"

int main(void){
	
	if (!init())
	{
		return 0;
	}

	int select = 0;

	while (1)
	{
		printf("======================================\n");
		printf("            학생 관리 기록부           \n");
		printf("======================================\n");
		printf("1. 무작위 생성  2. 출력  3. 탐색  4. 추가  5. 삭제\n6. 전체 삭제  7. 저장  8. 불러오기  9. 정렬  0. 종료\n\n");
		printf("입력 : ");

		scanf_s("%d", &select);

		switch (select)
		{
		case 1: //무작위 생성
		{
			if (!isFull())
			{
				printf("\n취소되었습니다.\n\n");
				continue;
			}

			int count = 0;
			printf("무작위 생성 횟수 입력 : ");
			scanf_s("%d", &count);
			system("cls");
			create(count);

			continue;
		}
		case 2: //전체 출력
		{
			system("cls");
			allPrint();

			continue;
		}
		case 3: //탐색 후 결과 출력(개선 여지 : 동명이인 대응) -> 탐색 결과를 노드가 아닌 노드 타입 배열(포인터)로 반환하면 가능할 듯
		{
			if (g_pHead->m_pNext == g_pTail)
			{
				system("cls");
				printf("데이터가 비었습니다!!\n\n");

				continue;
			}

			char name[30];
			printf("이름을 입력해주세요 : ");
			scanf_s("%s", name, sizeof(name));
			system("cls");
			
			StdNode* result = search(name);

			if (result != NULL)
			{
				print(result);
			}

			continue;
		}
		case 4: //추가
		{
			int select = 0;

			printf("\n1. 제일 앞에 삽입\n2. 제일 뒤에 삽입\n3. 특정 노드 전후에 삽입\n\n");
			printf("선택 : ");
			scanf_s("%d", &select);


			if (select == 1)
			{
				frontInsert(newNode());
			}
			else if(select == 2)
			{
				backInsert(newNode());
			}
			else
			{
				if (g_pHead->m_pNext == g_pTail)
				{
					system("cls");
					printf("데이터가 비었습니다!!\n\n");

					continue;
				}

				system("cls");
				allPrint();

				char name[30];
				int location = 0;
				printf("삽입을 원하는 위치의 학생 이름을 입력해주세요 : ");
				scanf_s("%s", name, sizeof(name));

				StdNode* result = search(name);

				if (result == NULL)
				{
					system("cls");
					printf("\n 존재하지 않는 학생입니다.");

					continue;
				}

				while (1)
				{
					printf("\n삽입 위치 선택(1. 전위, 2. 후위) : ");
					scanf_s("%d", &location);

					if (location < 1 || location > 2)
					{
						printf("잘못된 입력입니다.");

						continue;
					}
					break;
				}

				insert(newNode(), result, location);
			}

			system("cls");
			allPrint();
			printf("\n\n삽입 완료!\n\n");

			continue;
		}
		case 5: //삭제
		{
			if (g_pHead->m_pNext == g_pTail)
			{
				system("cls");
				printf("데이터가 비었습니다!!\n\n");

				continue; 
			}
			
			char name[30];
			printf("이름을 입력해주세요 : ");
			scanf_s("%s", name, sizeof(name));
			delete(search(name));

			system("cls");
			printf("\n\n삭제 완료!\n\n");

			continue;
		}
		case 6: //전체 삭제
		{
			if (g_pHead->m_pNext == g_pTail)
			{
				system("cls");
				printf("데이터가 비었습니다!!\n\n");

				continue;
			}

			deleteAll();

			system("cls");
			printf("삭제 완료\n\n");

			continue;
		}
		case 7: //저장
		{
			if (g_pHead->m_pNext == g_pTail)
			{
				printf("저장할 데이터가 없습니다!!\n\n");
				continue;
			}

			saveFile();
			continue;
		}
		case 8: //불러오기
		{
			if (isFull())
			{
				loadFile();
				allPrint();
				continue;
			}
			else
			{
				printf("\n취소되었습니다.\n\n");
				continue;
			}
		}
		case 9: //정렬
		{
			sort();
			continue;
		}
		case 0: //종료
		{
			printf("\n프로그램을 종료합니다.\n\n");

			break;
		}
		default: //없는 메뉴 대응
		{
			system("cls");
			printf("\n잘못된 입력입니다.\n\n");

			continue;
		}
		}
		break;
	}

	deleteAll();
	free(g_pCurrent);
	free(g_pHead);
	free(g_pTail);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //calloc
#include <time.h>
#include <string.h> //memset

typedef struct _StdNode
{
	char name[20];
	int age;
	int score1;
	int score2;
	int score3;
	int total;
	struct StdNode* m_pNext;
	struct StdNode* m_pPrev;

}StdNode;

StdNode* g_pHead = NULL;
StdNode* g_pTail = NULL;
StdNode* g_pCurrent = NULL;

void create(int count);
StdNode* newNode();
void allPrint();
StdNode* search(char name[]);
void delete(StdNode* delNode);
void deleteAll();
void insert(StdNode* newNode, StdNode* currentNode, int select);
void frontInsert(StdNode* student);
void backInsert(StdNode* student);
void saveFile();
void loadFile();

void init()
{
	g_pHead = (StdNode*)calloc(1, sizeof(StdNode));
	g_pTail = (StdNode*)calloc(1, sizeof(StdNode));
	g_pCurrent = (StdNode*)calloc(1, sizeof(StdNode));

	g_pHead->m_pNext = g_pTail;
	g_pTail->m_pPrev = g_pHead;
}

void create(int count) //입력 받은 수 만큼 무작위 데이터 생성
{
	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		StdNode* newNode = (StdNode*)calloc(1, sizeof(StdNode));
		for (int j = 0; j < 4; j++)
		{
			newNode->name[j] = 65 + rand() % 26;
		}
		newNode->age = rand() % 60;
		newNode->score1 = rand() % 101;
		newNode->score2 = rand() % 101;
		newNode->score3 = rand() % 101;
		newNode->total = (newNode->score1) + (newNode->score2) + (newNode->score3);

		backInsert(newNode);
	}

	allPrint();
}

StdNode* newNode() //새로운 노드 선언 후 반환
{
	StdNode* student = (StdNode*)calloc(1, sizeof(StdNode));

	printf("이름 : ");
	scanf_s("%s", student->name, sizeof(student->name));
	printf("나이 : ");
	scanf_s("%d", &(student->age));
	printf("점수1 :  ");
	scanf_s("%d", &(student->score1));
	printf("점수2 :  ");
	scanf_s("%d", &(student->score2));
	printf("점수3 :  ");
	scanf_s("%d", &(student->score3));
	student->total = (student->score1) + (student->score2) + (student->score3);

	return student;
}

void allPrint() //전체 연결 리스트 출력
{
	if (g_pHead->m_pNext == g_pTail)
	{
		printf("출력할 항목이 없습니다.\n\n");
		return;
	}

	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "이름", "나이", "점수1", "점수2", "점수3", "총점");
	printf("============================================================\n");
	for (StdNode* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		printf("%-10s %-10d %-10d %-10d %-10d %-10d\n\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	}
	printf("끝.\n\n");
}

void print(StdNode* node)
{
	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "이름", "나이", "점수1", "점수2", "점수3", "총점");
	printf("============================================================\n");
	printf("%-10s %-10d %-10d %-10d %-10d %-10d\n\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	printf("끝.\n\n");
}

StdNode* search(char name[]) //노드 탐색(순차 탐색)
{

	for (StdNode* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		if (strcmp(name, node->name) == 0)
		{
			return node;
		}
	}
	
	printf("찾는 값이 없습니다!\n\n");

	return NULL;
}

void delete(StdNode* delNode)
{
	StdNode* prevNode = delNode->m_pPrev;
	StdNode* nextNode = delNode->m_pNext;

	prevNode->m_pNext = nextNode;
	nextNode->m_pPrev = prevNode;
}

void deleteAll() // 전체삭제
{
	g_pCurrent = g_pHead->m_pNext;

	while (g_pCurrent != g_pTail)
	{
		StdNode* nextNode = g_pCurrent->m_pNext;

		free(g_pCurrent);
		g_pCurrent = nextNode;
	}

	g_pHead->m_pNext = g_pTail;
	g_pTail->m_pPrev = g_pHead;
}

//노드 추가기능 함수(1 : 전위, 2 : 후위)
void insert(StdNode* newNode, StdNode* currentNode, int select)
{
	if (select == 1)
	{
		StdNode* prevNode = currentNode->m_pPrev;

		newNode->m_pPrev = prevNode;
		newNode->m_pNext = currentNode;
		prevNode->m_pNext = newNode;
		currentNode->m_pPrev = newNode;

	}
	else
	{
		StdNode* nextNode = currentNode->m_pNext;

		newNode->m_pPrev = currentNode;
		newNode->m_pNext = nextNode;
		nextNode->m_pPrev = newNode;
		currentNode->m_pNext = newNode;

	}
}

void frontInsert(StdNode* newNode) //리스트 맨 앞에 삽입
{
	StdNode* nextNode = g_pHead->m_pNext;

	newNode->m_pNext = nextNode;
	newNode->m_pPrev = g_pHead;
	nextNode->m_pPrev = newNode;
	g_pHead->m_pNext = newNode;

}

void backInsert(StdNode* newNode) //리스트 맨 뒤에 삽입
{
	StdNode* prevNode = g_pTail->m_pPrev;

	newNode->m_pPrev = prevNode;
	newNode->m_pNext = g_pTail;
	prevNode->m_pNext = newNode;
	g_pTail->m_pPrev = newNode;

}

void saveFile()
{
	FILE* fp;
	errno_t err;
	char str;
	char fName[10] = { 0, };
	
	rewind(stdin);
	printf("저장할 파일명 : ");
	gets_s(fName, sizeof(fName));

	err = fopen_s(&fp, fName, "w+t");

	if (err != 0)
	{
		printf("파일 열기 실패!\n\n");
		return;
	}
	
	for (StdNode* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		fprintf(fp, "%s %d %d %d %d %d\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	}

	fclose(fp);
	printf("\n파일 저장 완료!!\n\n");

	return;
}


void loadFile()
{
	FILE* fp;
	errno_t err;
	char fName[10] = { 0, };

	printf("\n파일명을 입력해주세요 : ");
	rewind(stdin);
	gets_s(fName, sizeof(fName));

	err = fopen_s(&fp, fName, "r");

	if (err != 0)
	{
		system("cls");

		printf("\n파일 열기 실패!!\n\n");
		return;
	}

	system("cls");

	printf("\n파일 열기 성공!!\n\n");

	while (!feof(fp))
	{
		StdNode* student = (StdNode*)calloc(1, sizeof(StdNode));
		fscanf_s(fp, "%s %d %d %d %d %d\n", student->name, 20, &student->age, &student->score1, &student->score2, &student->score3, &student->total);
		backInsert(student);
	}

	fclose(fp);
	
}

int main(void){
	init();
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

			printf("1. 제일 앞에 삽입\n2. 제일 뒤에 삽입\n3. 특정 노드 전후에 삽입\n\n");
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
			if (g_pHead->m_pNext != g_pTail)
			{
				char select;
				printf("이미 리스트에 데이터가 존재합니다.\n기존 데이터를 삭제하고 불러오기를 진행할까요?\n");
				printf("(Y/N) : ");
				
				rewind(stdin);
				scanf_s("%c", &select, sizeof(select));

				if (select == 'y' || select == 'Y')
				{
					deleteAll();
				}
				else
				{
					printf("\n취소되었습니다.\n\n");
					continue;
				}
			}

			loadFile();
			allPrint();
			continue;
		}
		case 9: //정렬
		{
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

	free(g_pCurrent);
	free(g_pHead);
	free(g_pTail);
	return 0;
}
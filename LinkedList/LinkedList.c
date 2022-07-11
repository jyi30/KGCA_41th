#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _StdNode
{
	char name[20];
	int age;
	int score1;
	int score2;
	int score3;
	int total;
	struct StdNode* m_pNext;

}StdNode;

StdNode* g_pHead = NULL;
StdNode* g_pTail = NULL;
StdNode* g_pCurrent = NULL;

void create(int count);
void allPrint();
StdNode* search(char name[]);
void delete(char name[]);
void frontInsert(StdNode* student);
void backInsert(StdNode* student);

void init()
{
	g_pHead = (StdNode*)calloc(1, sizeof(StdNode));
	g_pTail = (StdNode*)calloc(1, sizeof(StdNode));
	g_pCurrent = (StdNode*)calloc(1, sizeof(StdNode));
}

void create(int count)
{
	for (int i = 0; i < count; i++)
	{
		StdNode* newNode = (StdNode*)calloc(1, sizeof(StdNode));
		for (int j = 0; j < 4; j++)
		{
			newNode->name[j] = 65 + rand() % 26;
		}
		newNode->age = count + rand() % 40;
		newNode->score1 = rand() % 101;
		newNode->score2 = rand() % 101;
		newNode->score3 = rand() % 101;
		newNode->total = (newNode->score1) + (newNode->score2) + (newNode->score3);

		backInsert(newNode);
	}

	allPrint();
}

void allPrint()
{
	if (g_pHead->m_pNext == NULL)
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

StdNode* search(char name[])
{
	for (StdNode* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		if (strcmp(name, node->name) == 0)
		{
			return node;
		}
	}
	
	printf("찾는 값이 없습니다!\n\n");

	return;
}

void delete(char name[])
{
	for (StdNode* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		if (strcmp(name, node->name) == 0)
		{
			
		}
	}
}

void frontInsert(StdNode* student)
{
	
}

void backInsert(StdNode* newNode)
{
	if (g_pHead->m_pNext == NULL)
	{
		g_pHead->m_pNext = newNode;
		newNode->m_pNext = g_pTail;
		g_pCurrent = newNode;
	}
	else
	{
		g_pCurrent->m_pNext = newNode;
		newNode->m_pNext = g_pTail;
		g_pCurrent = newNode;
	}
}

int main(void){
	init();

	int select = 0;
	while (1)
	{

		printf("======================================\n");
		printf("            학생 관리 기록부           \n");
		printf("======================================\n");
		printf("1. 생성  2. 출력  3. 탐색  4. 삽입  5. 삭제  6. 종료\n\n");
		printf("입력 : ");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
		{
			int count = 0;
			printf("생성 횟수 입력 : ");
			scanf_s("%d", &count);
			system("cls");
			create(count);

			continue;
		}
		case 2:
		{
			system("cls");
			allPrint();

			continue;
		}
		case 3:
		{
			if (g_pHead->m_pNext == NULL)
			{
				system("cls");
				printf("데이터가 비었습니다!!\n\n");

				continue;
			}

			char name[30];
			printf("이름을 입력해주세요 : ");
			scanf_s("%s", name, sizeof(name));
			system("cls");
			print(search(name));

			continue;
		}
		case 4:
		{
			int select = 0;

			printf("1. 제일 앞에 삽입\n2. 제일 뒤에 삽입\n\n");
			printf("선택 : ");
			scanf_s("%d", &select);

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

			if (select == 1)
			{
				frontInsert(student);
			}
			else
			{
				backInsert(student);
			}

			continue;
		}
		case 5:
		{
			if (g_pHead->m_pNext == NULL)
			{
				system("cls");
				printf("데이터가 비었습니다!!\n\n");

				continue;
			}
			
			char name[30];
			printf("이름을 입력해주세요 : ");
			scanf_s("%s", name, sizeof(name));
			delete(name);

			continue;
		}
		case 6:
		{
			printf("\n프로그램을 종료합니다.\n\n");

			break;
		}
		default:
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
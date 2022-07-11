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
void insert(StdNode* newNode);
void allPrint();
StdNode* search(char name[]);
void delete(char name[]);

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

		insert(newNode);
	}

	allPrint();
}

void insert(StdNode* newNode)
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

int main(void){
	init();

	int select = 0;
	while (1)
	{

		printf("======================================\n");
		printf("            학생 관리 기록부           \n");
		printf("======================================\n");
		printf("1. 생성  2. 출력  3. 탐색  4. 삭제  5. 종료\n\n");
		printf("입력 : ");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
		{
			int count = 0;
			printf("생성 횟수 입력 : ");
			scanf_s("%d", &count);
			create(count);

			break;
		}
		case 2:
		{
			allPrint();
			break;
		}
		case 3:
		{
			if (g_pHead->m_pNext == NULL)
			{
				printf("데이터가 비었습니다!!\n\n");
				break;
			}

			char name[30];
			printf("이름을 입력해주세요 : ");
			scanf_s("%s", name, sizeof(name));
			print(search(name));
			break;
		}
		case 4:
		{
			if (g_pHead->m_pNext == NULL)
			{
				printf("데이터가 비었습니다!!\n\n");
				break;
			}
			
			char name[30];
			printf("이름을 입력해주세요 : ");
			scanf_s("%s", name, sizeof(name));
			delete(name);
			break;
		}
		case 5:
		{
			printf("프로그램을 종료합니다.\n\n");
			break;
		}
		default:
		{
			printf("잘못된 입력입니다.\n\n");
			continue;
		}
		}
		
	}
	return 0;
}
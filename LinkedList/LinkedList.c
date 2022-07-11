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
		printf("����� �׸��� �����ϴ�.\n\n");
		return;
	}

	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "�̸�", "����", "����1", "����2", "����3", "����");
	printf("============================================================\n");
	for (StdNode* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		printf("%-10s %-10d %-10d %-10d %-10d %-10d\n\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	}
	printf("��.\n\n");
}

void print(StdNode* node)
{
	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "�̸�", "����", "����1", "����2", "����3", "����");
	printf("============================================================\n");
	printf("%-10s %-10d %-10d %-10d %-10d %-10d\n\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	printf("��.\n\n");
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
	
	printf("ã�� ���� �����ϴ�!\n\n");

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
		printf("            �л� ���� ��Ϻ�           \n");
		printf("======================================\n");
		printf("1. ����  2. ���  3. Ž��  4. ����  5. ����  6. ����\n\n");
		printf("�Է� : ");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
		{
			int count = 0;
			printf("���� Ƚ�� �Է� : ");
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
				printf("�����Ͱ� ������ϴ�!!\n\n");

				continue;
			}

			char name[30];
			printf("�̸��� �Է����ּ��� : ");
			scanf_s("%s", name, sizeof(name));
			system("cls");
			print(search(name));

			continue;
		}
		case 4:
		{
			int select = 0;

			printf("1. ���� �տ� ����\n2. ���� �ڿ� ����\n\n");
			printf("���� : ");
			scanf_s("%d", &select);

			StdNode* student = (StdNode*)calloc(1, sizeof(StdNode));

			printf("�̸� : ");
			scanf_s("%s", student->name, sizeof(student->name));
			printf("���� : ");
			scanf_s("%d", &(student->age));
			printf("����1 :  ");
			scanf_s("%d", &(student->score1));
			printf("����2 :  ");
			scanf_s("%d", &(student->score2));
			printf("����3 :  ");
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
				printf("�����Ͱ� ������ϴ�!!\n\n");

				continue;
			}
			
			char name[30];
			printf("�̸��� �Է����ּ��� : ");
			scanf_s("%s", name, sizeof(name));
			delete(name);

			continue;
		}
		case 6:
		{
			printf("\n���α׷��� �����մϴ�.\n\n");

			break;
		}
		default:
		{
			system("cls");
			printf("\n�߸��� �Է��Դϴ�.\n\n");

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
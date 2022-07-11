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

int main(void){
	init();

	int select = 0;
	while (1)
	{

		printf("======================================\n");
		printf("            �л� ���� ��Ϻ�           \n");
		printf("======================================\n");
		printf("1. ����  2. ���  3. Ž��  4. ����  5. ����\n\n");
		printf("�Է� : ");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
		{
			int count = 0;
			printf("���� Ƚ�� �Է� : ");
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
				printf("�����Ͱ� ������ϴ�!!\n\n");
				break;
			}

			char name[30];
			printf("�̸��� �Է����ּ��� : ");
			scanf_s("%s", name, sizeof(name));
			print(search(name));
			break;
		}
		case 4:
		{
			if (g_pHead->m_pNext == NULL)
			{
				printf("�����Ͱ� ������ϴ�!!\n\n");
				break;
			}
			
			char name[30];
			printf("�̸��� �Է����ּ��� : ");
			scanf_s("%s", name, sizeof(name));
			delete(name);
			break;
		}
		case 5:
		{
			printf("���α׷��� �����մϴ�.\n\n");
			break;
		}
		default:
		{
			printf("�߸��� �Է��Դϴ�.\n\n");
			continue;
		}
		}
		
	}
	return 0;
}
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
void insert(StdNode* newNode, StdNode* currentNode, int select);
void frontInsert(StdNode* student);
void backInsert(StdNode* student);

void init()
{
	g_pHead = (StdNode*)calloc(1, sizeof(StdNode));
	g_pTail = (StdNode*)calloc(1, sizeof(StdNode));
	g_pCurrent = (StdNode*)calloc(1, sizeof(StdNode));

	g_pHead->m_pNext = g_pTail;
	g_pTail->m_pPrev = g_pHead;
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

StdNode* newNode()
{
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

	return student;
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

	return NULL;
}

void delete(StdNode* delNode)
{
	StdNode* prevNode = delNode->m_pPrev;
	StdNode* nextNode = delNode->m_pNext;

	prevNode->m_pNext = nextNode;
	nextNode->m_pPrev = prevNode;
}

//��� �߰���� �Լ�(1 : ����, 2 : ����)
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

void frontInsert(StdNode* newNode)
{
	StdNode* nextNode = g_pHead->m_pNext;

	newNode->m_pNext = nextNode;
	newNode->m_pPrev = g_pHead;
	nextNode->m_pPrev = newNode;
	g_pHead->m_pNext = newNode;

}

void backInsert(StdNode* newNode)
{
	StdNode* prevNode = g_pTail->m_pPrev;

	newNode->m_pPrev = prevNode;
	newNode->m_pNext = g_pTail;
	prevNode->m_pNext = newNode;
	g_pTail->m_pPrev = newNode;

}

int main(void){
	init();

	int select = 0;
	while (1)
	{

		printf("======================================\n");
		printf("            �л� ���� ��Ϻ�           \n");
		printf("======================================\n");
		printf("1. ������ ����  2. ���  3. Ž��  4. �߰�  5. ����  6. ����  7. �ҷ�����  8. ����  0. ����\n\n");
		printf("�Է� : ");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1: //������ ����
		{
			int count = 0;
			printf("������ ���� Ƚ�� �Է� : ");
			scanf_s("%d", &count);
			system("cls");
			create(count);

			continue;
		}
		case 2: //��ü ���
		{
			system("cls");
			allPrint();

			continue;
		}
		case 3: //Ž�� �� ��� ���(���� ���� : �������� ������ ��) -> Ž�� ����� ��尡 �ƴ� �迭(������)�� ��ȯ�ϸ� ������ ��
		{
			if (g_pHead->m_pNext == g_pTail)
			{
				system("cls");
				printf("�����Ͱ� ������ϴ�!!\n\n");

				continue;
			}

			char name[30];
			printf("�̸��� �Է����ּ��� : ");
			scanf_s("%s", name, sizeof(name));
			system("cls");
			
			StdNode* result = search(name);

			if (result != NULL)
			{
				print(result);
			}

			continue;
		}
		case 4: //�߰�
		{
			int select = 0;

			printf("1. ���� �տ� ����\n2. ���� �ڿ� ����\n3. Ư�� ��� ���Ŀ� ����\n\n");
			printf("���� : ");
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
					printf("�����Ͱ� ������ϴ�!!\n\n");

					continue;
				}

				system("cls");
				allPrint();

				char name[30];
				int location = 0;
				printf("������ ���ϴ� ��ġ�� �л� �̸��� �Է����ּ��� : ");
				scanf_s("%s", name, sizeof(name));

				StdNode* result = search(name);

				if (result == NULL)
				{
					system("cls");
					printf("\n �������� �ʴ� �л��Դϴ�.");
					continue;
				}

				while (1)
				{
					printf("\n���� ��ġ ����(1. ����, 2. ����) : ");
					scanf_s("%d", &location);

					if (location < 1 || location > 2)
					{
						printf("�߸��� �Է��Դϴ�.");
						continue;
					}

					break;
				}

				insert(newNode(), result, location);
			}

			system("cls");
			printf("\n\n���� �Ϸ�!\n\n");
			continue;
		}
		case 5: //����
		{
			if (g_pHead->m_pNext == g_pTail)
			{
				system("cls");
				printf("�����Ͱ� ������ϴ�!!\n\n");

				continue; 
			}
			
			char name[30];
			printf("�̸��� �Է����ּ��� : ");
			scanf_s("%s", name, sizeof(name));
			delete(search(name));

			system("cls");
			printf("\n\n���� �Ϸ�!\n\n");

			continue;
		}
		case 0: //����
		{
			printf("\n���α׷��� �����մϴ�.\n\n");

			break;
		}
		default: //���� �޴� ����
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
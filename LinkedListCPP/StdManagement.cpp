#include "StdManagement.h"

StdManagement::StdManagement()
{

}

StdManagement::~StdManagement()
{

}


Student* StdManagement::newNode() //���ο� ��� ���� �� ��ȯ
{
	Student* student = (Student*)calloc(1, sizeof(Student));

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

int StdManagement::init()
{
	g_pHead = (Student*)calloc(1, sizeof(Student));
	g_pTail = (Student*)calloc(1, sizeof(Student));
	g_pCurrent = (Student*)calloc(1, sizeof(Student));

	if (g_pHead == NULL || g_pTail == NULL || g_pCurrent == NULL)
	{
		printf("�޸� �Ҵ翡 �����߽��ϴ�. �ٽ� �������ּ���.\n\n");
		return 0;
	}

	g_pHead->m_pNext = g_pTail;
	g_pTail->m_pPrev = g_pHead;

	return 1;
}

void StdManagement::create(int count) //�Է� ���� �� ��ŭ ������ ������ ����
{
	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		Student* newNode = (Student*)calloc(1, sizeof(Student));
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

void StdManagement::allPrint() //��ü ���� ����Ʈ ���
{
	if (g_pHead->m_pNext == g_pTail)
	{
		printf("����� �׸��� �����ϴ�.\n\n");
		return;
	}

	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "�̸�", "����", "����1", "����2", "����3", "����");
	printf("============================================================\n");
	for (Student* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		printf("%-10s %-10d %-10d %-10d %-10d %-10d\n\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	}
	printf("��.\n\n");
}

void StdManagement::print(Student* node)
{
	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "�̸�", "����", "����1", "����2", "����3", "����");
	printf("============================================================\n");
	printf("%-10s %-10d %-10d %-10d %-10d %-10d\n\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	printf("��.\n\n");
}

void StdManagement::saveFile()
{
	FILE* fp;
	errno_t err;
	char str;
	char fName[10] = { 0, };

	rewind(stdin);
	printf("������ ���ϸ� : ");
	gets_s(fName, sizeof(fName));

	err = fopen_s(&fp, fName, "w+t");

	if (err != 0)
	{
		printf("���� ���� ����!\n\n");
		return;
	}

	for (Student* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		fprintf(fp, "%s %d %d %d %d %d\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	}

	fclose(fp);

	system("cls");
	printf("\n���� ���� �Ϸ�!!\n\n");

	return;
}


void StdManagement::loadFile()
{
	FILE* fp;
	errno_t err;
	char fName[10] = { 0, };

	printf("\n���ϸ��� �Է����ּ��� : ");
	rewind(stdin);
	gets_s(fName, sizeof(fName));

	err = fopen_s(&fp, fName, "r");

	if (err != 0)
	{
		system("cls");

		printf("\n���� ���� ����!!\n\n");
		return;
	}

	system("cls");

	printf("\n���� ���� ����!!\n\n");

	while (!feof(fp))
	{
		Student* student = (Student*)calloc(1, sizeof(Student));
		fscanf_s(fp, "%s %d %d %d %d %d\n", student->name, 20, &student->age, &student->score1, &student->score2, &student->score3, &student->total);
		backInsert(student);
	}

	fclose(fp);
}
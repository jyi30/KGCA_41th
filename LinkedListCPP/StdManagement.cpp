#include "StdManagement.h"

StdManagement::StdManagement()
{

}

StdManagement::~StdManagement()
{

}


Student* StdManagement::newNode() //새로운 노드 선언 후 반환
{
	Student* student = (Student*)calloc(1, sizeof(Student));

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

int StdManagement::init()
{
	g_pHead = (Student*)calloc(1, sizeof(Student));
	g_pTail = (Student*)calloc(1, sizeof(Student));
	g_pCurrent = (Student*)calloc(1, sizeof(Student));

	if (g_pHead == NULL || g_pTail == NULL || g_pCurrent == NULL)
	{
		printf("메모리 할당에 실패했습니다. 다시 시작해주세요.\n\n");
		return 0;
	}

	g_pHead->m_pNext = g_pTail;
	g_pTail->m_pPrev = g_pHead;

	return 1;
}

void StdManagement::create(int count) //입력 받은 수 만큼 무작위 데이터 생성
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

void StdManagement::allPrint() //전체 연결 리스트 출력
{
	if (g_pHead->m_pNext == g_pTail)
	{
		printf("출력할 항목이 없습니다.\n\n");
		return;
	}

	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "이름", "나이", "점수1", "점수2", "점수3", "총점");
	printf("============================================================\n");
	for (Student* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		printf("%-10s %-10d %-10d %-10d %-10d %-10d\n\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	}
	printf("끝.\n\n");
}

void StdManagement::print(Student* node)
{
	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s\n", "이름", "나이", "점수1", "점수2", "점수3", "총점");
	printf("============================================================\n");
	printf("%-10s %-10d %-10d %-10d %-10d %-10d\n\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	printf("끝.\n\n");
}

void StdManagement::saveFile()
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

	for (Student* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		fprintf(fp, "%s %d %d %d %d %d\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	}

	fclose(fp);

	system("cls");
	printf("\n파일 저장 완료!!\n\n");

	return;
}


void StdManagement::loadFile()
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
		Student* student = (Student*)calloc(1, sizeof(Student));
		fscanf_s(fp, "%s %d %d %d %d %d\n", student->name, 20, &student->age, &student->score1, &student->score2, &student->score3, &student->total);
		backInsert(student);
	}

	fclose(fp);
}
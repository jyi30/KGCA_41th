#include "StdManagement.h"

StdManagement::StdManagement()
{

}

StdManagement::~StdManagement()
{

}


Student* StdManagement::newNode() //새로운 노드 선언 후 반환
{
	Student* student = new Student();

	cout << "이름 : ";
	cin >> student->name;
	cout << "나이 : ";
	cin >> student->age;
	cout << "점수1 :  ";
	cin >> student->score1;
	cout << "점수2 :  ";
	cin >> student->score2;
	cout << "점수3 :  ";
	cin >> student->score3;
	student->total = (student->score1) + (student->score2) + (student->score3);

	return student;
}

int StdManagement::init()
{
	g_pHead = new Student();
	g_pTail = new Student();
	g_pCurrent = new Student();

	if (g_pHead == NULL || g_pTail == NULL || g_pCurrent == NULL)
	{
		cout << "메모리 할당에 실패했습니다. 다시 시작해주세요.\n\n";
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
		Student* newNode = new Student();
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
		cout << "출력할 항목이 없습니다.\n\n";
		return;
	}

	cout.setf(ios::left);
	cout << setw(10) << "이름" << setw(10) <<  "나이" << setw(10) << "점수1" << setw(10) << "점수2" << setw(10) 
		<< "점수3" << setw(10) << "총점" << endl;
	cout << "============================================================\n";
	for (Student* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		cout << setw(10) << node->name << setw(10) << node->age << setw(10) << node->score1 << setw(10) 
			<< node->score2 << setw(10) << node->score3 << setw(10) << node->total << "\n\n";
	}
	cout << "끝.\n\n";
}

void StdManagement::print(Student* node)
{
	cout << "이름" << setw(10) << "나이" << setw(10) << "점수1" << setw(10) << "점수2" << setw(10) << "점수3" 
		<< setw(10) << "총점";
	cout << "============================================================\n";
	cout << node->name << setw(10) << node->age << setw(10) << node->score1 << setw(10) << node->score2 << setw(10) 
		<< node->score3 << setw(10) << node->total << "\n\n";
	cout << "끝.\n\n";
}

void StdManagement::saveFile()
{
	FILE* fp;
	errno_t err;
	char str;
	char fName[10] = { 0, };

	rewind(stdin);
	cout << "저장할 파일명 : ";
	cin >> fName;

	err = fopen_s(&fp, fName, "w+t");

	if (err != 0)
	{
		cout << "파일 열기 실패!\n\n";
		return;
	}

	for (Student* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		fprintf(fp, "%s %d %d %d %d %d\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	}

	fclose(fp);

	system("cls");
	cout << "\n파일 저장 완료!!\n\n";

	return;
}


void StdManagement::loadFile()
{
	FILE* fp;
	errno_t err;
	char fName[10] = { 0, };

	cout << "\n파일명을 입력해주세요 : ";
	rewind(stdin);
	cin >> fName;

	err = fopen_s(&fp, fName, "r");

	if (err != 0)
	{
		system("cls");

		cout << "\n파일 열기 실패!!\n\n";
		return;
	}

	system("cls");

	cout << "\n파일 열기 성공!!\n\n";

	while (!feof(fp))
	{
		Student* student = (Student*)calloc(1, sizeof(Student));
		fscanf_s(fp, "%s %d %d %d %d %d\n", student->name, 20, &student->age, &student->score1, &student->score2, &student->score3, &student->total);
		backInsert(student);
	}

	fclose(fp);
}
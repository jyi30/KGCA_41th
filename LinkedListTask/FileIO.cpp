#include "FileIO.h"

void FileIO::saveFile()
{
	FILE* fp;
	errno_t err;
	char str;
	char fName[10] = { 0, };

	rewind(stdin);
	cout << "������ ���ϸ� : ";
	cin >> fName;

	err = fopen_s(&fp, fName, "w+t");

	if (err != 0)
	{
		cout << "���� ���� ����!\n\n";
		return;
	}

	for (Student* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		fprintf(fp, "%s %d %d %d %d %d\n", node->name, node->age, node->score1, node->score2, node->score3, node->total);
	}

	fclose(fp);

	system("cls");
	cout << "\n���� ���� �Ϸ�!!\n\n";

	return;
}


void FileIO::loadFile()
{
	FILE* fp;
	errno_t err;
	char fName[10] = { 0, };

	cout << "\n���ϸ��� �Է����ּ��� : ";
	rewind(stdin);
	cin >> fName;

	err = fopen_s(&fp, fName, "r");

	if (err != 0)
	{
		system("cls");

		cout << "\n���� ���� ����!!\n\n";
		return;
	}

	system("cls");

	cout << "\n���� ���� ����!!\n\n";

	while (!feof(fp))
	{
		Student* student = new Student();
		fscanf_s(fp, "%s %d %d %d %d %d\n", student->name, 20, &student->age, &student->score1, &student->score2, &student->score3, &student->total);
		backInsert(student);
	}

	fclose(fp);
}

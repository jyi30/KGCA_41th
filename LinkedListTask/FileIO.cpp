#include "FileIO.h"

void FileIO::saveFile(TLinkedList<Student> link)
{
	ofs.open("students.txt", ios::out | ios::binary);

	if (ofs.fail())
	{
		cerr << "에러 발생!" << endl;
		return;
	}

	for (TNode<Student>* node = link.getHead()->m_pNext; node != link.getTail(); node = node->m_pNext)
	{
		Student student = node->Data;
		ofs << student.getName()<< " " << student.getAge() << " " <<  student.getScore1() << " " << student.getScore2() << " " << student.getScore3() << " " << student.getTotal() << endl;
	}

	cout << "저장 완료\n" << endl;
	ofs.close();

	//FILE* fp;
	//errno_t err;
	////char str;
	//char fName[10] = { 0, };

	//rewind(stdin);
	//cout << "저장할 파일명 : ";
	//cin >> fName;

	//err = fopen_s(&fp, fName, "w+t");

	//if (err != 0)
	//{
	//	cout << "파일 열기 실패!\n\n";
	//	return;
	//}

	//for (TNode<Student>* node = link.getHead()->m_pNext; node != link.getTail(); node = node->m_pNext)
	//{
	//	Student student = node->Data;
	//	fprintf(fp, "%s %d %d %d %d %d\n", student.getName(), student.getAge(), student.getScore1(), student.getScore2(), student.getScore3(), student.getTotal());
	//}

	//fclose(fp);

	//system("cls");
	//cout << "\n파일 저장 완료!!\n\n";

	//return;
}


void FileIO::loadFile(TLinkedList<Student> link)
{
	char name[20];
	int age;
	int score1;
	int score2;
	int score3;
	int total;
	
	ifs.open("students.txt", ios::in | ios::binary);

	if (ifs.fail())
	{
		cerr << "에러 발생!" << endl;
		return;
	}

	while (1)
	{
		Student* student = new Student();
		ifs >> name >> age >> score1 >> score2 >> score3 >> total;
		
		if (ifs.eof())
		{
			break;
		}

		link.backInsert(student->newStd(name, age, score1, score2, score3, total));
	}

	if (link.getHead()->m_pNext == link.getTail())
	{
		cout << "불러올 데이터가 없습니다." << endl;
		ifs.close();

		return;
	}

	cout << "불러오기 완료!\n" << endl;
	ifs.close();


	//FILE* fp;
	//errno_t err;
	//char fName[10] = { 0, };

	//cout << "\n파일명을 입력해주세요 : ";
	//rewind(stdin);
	//cin >> fName;

	//err = fopen_s(&fp, fName, "r");

	//if (err != 0)
	//{
	//	system("cls");

	//	cout << "\n파일 열기 실패!!\n\n";
	//	return;
	//}

	//system("cls");

	//cout << "\n파일 열기 성공!!\n\n";

	//while (!feof(fp))
	//{
	//	Student* student = new Student();
	//	fscanf_s(fp, "%s %d %d %d %d %d\n", student.setName(), 20, &student->age, &student->score1, &student->score2, &student->score3, &student->total);
	//	//fscanf_s(fp, "%s %d %d %d %d %d\n", student->name, 20, &student->age, &student->score1, &student->score2, &student->score3, &student->total);
	//	link.backInsert(*student);
	//}

	//fclose(fp);
}

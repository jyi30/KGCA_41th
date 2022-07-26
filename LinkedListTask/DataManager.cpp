#include "DataManager.h"

TLinkedList<Student> link;

DataManager::DataManager()
{
	
}

DataManager::~DataManager()
{
	link.deleteAll();
	delete(&link);
	delete(&fileio);

}

void DataManager::init()
{
	link.newList();
}

void DataManager::randomCreate(int count) //입력 받은 수 만큼 무작위 데이터 생성
{
	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		Student* newstd = new Student();
		char name[20] = { 0, };
		for (int j = 0; j < 4; j++)
		{
			name[j] = 65 + rand() % 26;
		}
		newstd->setName(name);
		newstd->setAge(rand() % 60);
		newstd->setScore1(rand() % 101);
		newstd->setScore2(rand() % 101);
		newstd->setScore3(rand() % 101);
		newstd->setTotal(newstd->getScore1() + newstd->getScore2() + newstd->getScore3());

		link.backInsert(newstd);
	}

	link.allPrint();
	cout << "생성 완료!" << endl;
}

void DataManager::insert()
{
	int select = 0;

	cout << "\n1. 제일 앞에 삽입\n2. 제일 뒤에 삽입\n3. 특정 노드 전후에 삽입\n\n";
	cout << "선택 : ";
	cin >> select;


	if (select == 1)
	{
		link.frontInsert(*student.newStd());
	}
	else if (select == 2)
	{
		link.backInsert(student.newStd());
	}
	else
	{
		if (isEmpty())
		{
			return;
		}

		system("cls");
		link.allPrint();

		char name[30];
		int location = 0;
		cout << "삽입을 원하는 위치의 학생 이름을 입력해주세요 : ";
		cin >> name;

		while (1)
		{
			cout << "\n삽입 위치 선택(1. 전위, 2. 후위) : ";
			cin >> location;

			if (location < 1 || location > 2)
			{
				cout << "잘못된 입력입니다.";

				continue;
			}
			break;
		}

		link.insert(*student.newStd(), link.search(name), location);
	}

	system("cls");
	link.allPrint();
	cout << "삽입 완료!\n\n";
}

void DataManager::deleteNode(char name[])
{
	if (link.search(name) == NULL)
	{
		cout << "찾는 값이 존재하지 않습니다.\n" << endl;
		return;
	}

	link.deleteNode(link.search(name));
	link.allPrint();
	cout << "삭제 완료!\n" << endl;
}

void DataManager::deleteNode()
{
	link.deleteAll();
}

int DataManager::isFull()
{
	if (link.getHead()->m_pNext != link.getTail())
	{
		char select;
		system("cls");
		cout << "이미 리스트에 데이터가 존재합니다.\n기존 데이터를 삭제하고 진행할까요?\n";
		cout << "(Y/N) : ";

		rewind(stdin);
		cin >> select;

		if (select == 'y' || select == 'Y')
		{
			link.deleteAll();
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

int DataManager::isEmpty()
{
	if (link.getHead()->m_pNext == link.getTail())
	{
		system("cls");
		cout << "데이터가 존재하지 않습니다.\n" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

void DataManager::find(char name[])
{
	if (link.search(name) == NULL)
	{
		cout << "찾는 값이 존재하지 않습니다.\n" << endl;
		return;
	}
	else
	{
		link.print(link.search(name));
	}
}


void DataManager::print()
{

	link.allPrint();

	return;
}

//void DataManager::print(char name[])
//{
//	link.print(link.search(name));
//}

void DataManager::fileCtr(int num)
{
	if (num == 1)
	{
		if (!isEmpty())
		{
			system("cls");
			fileio.saveFile(link);
		}
		else
		{
			return;
		}
	}
	else if (num == 2)
	{
		if (isFull())
		{
			system("cls");
			fileio.loadFile(link);
			link.allPrint();
		}
		else
		{
			cout << "\n취소되었습니다.\n\n";
			return;
		}
	}
}

void DataManager::sort(int type)
{
	if (isEmpty())
	{
		return;
	}

	system("cls");

	if (type == 1)
	{
		link.sortASC();
	}
	else if (type == 2)
	{
		link.sortDESC();
	}

	link.allPrint();

	cout << "정렬 완료!\n" << endl;
}




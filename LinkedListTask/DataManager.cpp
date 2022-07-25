#include "DataManager.h"

DataManager::DataManager()
{
	link.newList();
}

DataManager::~DataManager()
{
	link.deleteAll();
	delete(&link);
	delete(&fileio);

}

void DataManager::randomCreate(int count) //입력 받은 수 만큼 무작위 데이터 생성
{
	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		char name[20];
		for (int j = 0; j < 4; j++)
		{
			name[j] = 65 + rand() % 26;
		}
		int age = rand() % 60;
		int score1 = rand() % 101;
		int score2 = rand() % 101;
		int score3 = rand() % 101;

		Student* newstd = student.newStd(name, age, score1, score2, score3);

		link.backInsert(*newstd);
	}
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
		link.backInsert(*student.newStd());
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
	cout << "\n\n삽입 완료!\n\n";
}

void DataManager::deleteNode(char name[])
{

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
		cout << "데이터가 존재하지 않습니다." << endl;
		return 1;
	}
	else
	{
		return -1;
	}
}

void DataManager::print()
{
	if (isEmpty())
	{
		return;
	}
	else
	{
		link.allPrint();
	}

	return;
}

void DataManager::print(char name[])
{
	link.print(link.search(name));
}





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

void DataManager::randomCreate(int count) //�Է� ���� �� ��ŭ ������ ������ ����
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

	cout << "\n1. ���� �տ� ����\n2. ���� �ڿ� ����\n3. Ư�� ��� ���Ŀ� ����\n\n";
	cout << "���� : ";
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
		cout << "������ ���ϴ� ��ġ�� �л� �̸��� �Է����ּ��� : ";
		cin >> name;

		while (1)
		{
			cout << "\n���� ��ġ ����(1. ����, 2. ����) : ";
			cin >> location;

			if (location < 1 || location > 2)
			{
				cout << "�߸��� �Է��Դϴ�.";

				continue;
			}
			break;
		}

		link.insert(*student.newStd(), link.search(name), location);
	}

	system("cls");
	link.allPrint();
	cout << "\n\n���� �Ϸ�!\n\n";
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
		cout << "�̹� ����Ʈ�� �����Ͱ� �����մϴ�.\n���� �����͸� �����ϰ� �����ұ��?\n";
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
		cout << "�����Ͱ� �������� �ʽ��ϴ�." << endl;
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





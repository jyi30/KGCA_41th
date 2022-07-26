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

void DataManager::randomCreate(int count) //�Է� ���� �� ��ŭ ������ ������ ����
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
	cout << "���� �Ϸ�!" << endl;
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
	cout << "���� �Ϸ�!\n\n";
}

void DataManager::deleteNode(char name[])
{
	if (link.search(name) == NULL)
	{
		cout << "ã�� ���� �������� �ʽ��ϴ�.\n" << endl;
		return;
	}

	link.deleteNode(link.search(name));
	link.allPrint();
	cout << "���� �Ϸ�!\n" << endl;
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
		cout << "�����Ͱ� �������� �ʽ��ϴ�.\n" << endl;
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
		cout << "ã�� ���� �������� �ʽ��ϴ�.\n" << endl;
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
			cout << "\n��ҵǾ����ϴ�.\n\n";
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

	cout << "���� �Ϸ�!\n" << endl;
}




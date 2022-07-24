#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

struct Student
{
	char name[20];
	int age;
	int score1;
	int score2;
	int score3;
	int total;
};

template <class T>
class TNode
{
public:
	T Data;
	TNode* m_pPrev;
	TNode* m_pNext;
};

template <class T>
class TLinkedList
{
private:
	TNode<T>* m_pHead = NULL;
	TNode<T>* m_pTail = NULL;
	TNode<T>* m_pCurrent = NULL;

public:
	void create(int count); 
	void backInsert(T newNode);
	void init();
	void allPrint();
	void print(Student* node);
	Student* search(char name[]);
	int isFull(TLinkedList<Student> link);

public:
	//TLinkedList();
	//~TLinkedList();
	TNode<T>* getHead();
	TNode<T>* getTail();
	TNode<T>* getCurrent();
	void setHead(TNode<T>* head);
	void setTail(TNode<T>* tail);
	void setCurrent(TNode<T>* current);
};

template <class T>
void TLinkedList<T>::init()
{
	setHead(new TNode<T>);
	setTail(new TNode<T>);
	setCurrent(new TNode<T>);

	if (getHead() == NULL || getTail() == NULL || getCurrent() == NULL)
	{
		cout << "�޸� �Ҵ翡 �����߽��ϴ�. �ٽ� �������ּ���.\n\n";
		return 0;
	}

	getHead()->m_pNext = getTail();
	getTail()->m_pPrev = getHead();
}

template <class T>
void TLinkedList<T>::create(int count) //�Է� ���� �� ��ŭ ������ ������ ����
{
	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		Student* student = new Student();
		for (int j = 0; j < 4; j++)
		{
			student->name[j] = 65 + rand() % 26;
		}
		student->age = rand() % 60;
		student->score1 = rand() % 101;
		student->score2 = rand() % 101;
		student->score3 = rand() % 101;
		student->total = (student->score1) + (student->score2) + (student->score3);

		backInsert(*student);
	}
	allPrint();
}

template <class T>
void TLinkedList<T>::backInsert(T Student) //����Ʈ �� �ڿ� ����
{
	TNode<T>* newNode = new TNode<T>();
	newNode->Data = Student;

	TNode<T>* prevNode = getTail()->m_pPrev;

	newNode->m_pPrev = prevNode;
	newNode->m_pNext = getTail();
	prevNode->m_pNext = newNode;
	getTail()->m_pPrev = newNode;

}


template <class T>
void TLinkedList<T>::allPrint() //��ü ���� ����Ʈ ���
{
	if (getHead()->m_pNext == getTail())
	{
		cout << "����� �׸��� �����ϴ�.\n\n";
		return;
	}

	TNode<T> *node;
	Student* std;

	cout.setf(ios::left);
	cout << setw(10) << "�̸�" << setw(10) << "����" << setw(10) << "����1" << setw(10) << "����2" << setw(10)
		<< "����3" << setw(10) << "����" << endl;
	cout << "============================================================\n";
	for (node = getHead()->m_pNext; node != getTail(); node = node->m_pNext)
	{
		std = &node->Data;
		cout << setw(10) << std->name << setw(10) << std->age << setw(10) << std->score1 << setw(10)
			<< std->score2 << setw(10) << std->score3 << setw(10) << std->total << "\n\n";
	}
	cout << "��.\n\n";
}

template <class T>
void TLinkedList<T>::print(Student* node)
{
	cout << "�̸�" << setw(10) << "����" << setw(10) << "����1" << setw(10) << "����2" << setw(10) << "����3"
		<< setw(10) << "����";
	cout << "============================================================\n";
	cout << node->name << setw(10) << node->age << setw(10) << node->score1 << setw(10) << node->score2 << setw(10)
		<< node->score3 << setw(10) << node->total << "\n\n";
	cout << "��.\n\n";
}

template <class T>
Student* TLinkedList<T>::search(char name[]) //��� Ž��(���� Ž��)
{

	for (Student* node = g_pHead->m_pNext; node != g_pTail; node = node->m_pNext)
	{
		if (strcmp(name, node->name) == 0)
		{
			return node;
		}
	}

	printf("ã�� ���� �����ϴ�!\n\n");

	return NULL;
}

template <class T>
int TLinkedList<T>::isFull(TLinkedList<Student> link)
{
	if (getHead()->m_pNext != getTail())
	{
		char select;
		system("cls");
		cout << "�̹� ����Ʈ�� �����Ͱ� �����մϴ�.\n���� �����͸� �����ϰ� �����ұ��?\n";
		cout << "(Y/N) : ";

		rewind(stdin);
		cin >> select;

		if (select == 'y' || select == 'Y')
		{
			deleteAll();
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}















template <class T>
TNode<T>* TLinkedList<T>::getHead()
{
	return m_pHead;
}

template <class T>
TNode<T>* TLinkedList<T>::getTail()
{
	return m_pTail;
}

template <class T>
TNode<T>* TLinkedList<T>::getCurrent()
{
	return m_pCurrent;
}

template <class T>
void TLinkedList<T>::setHead(TNode<T>* head)
{
	this->m_pHead = head;
}

template <class T>
void TLinkedList<T>::setTail(TNode<T>* tail)
{
	this->m_pTail = tail;
}

template <class T>
void TLinkedList<T>::setCurrent(TNode<T>* current)
{
	this->m_pCurrent = current;
}

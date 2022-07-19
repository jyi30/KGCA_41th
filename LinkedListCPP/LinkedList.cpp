#include "LinkedList.h"
#include "StdManagement.h"

LinkedList::LinkedList()
{

}

LinkedList::~LinkedList()
{
	delete g_pCurrent;
	delete g_pHead;
	delete g_pTail;
}

StdManagement manage;

Student* LinkedList::getHead()
{
	return g_pHead;
}
Student* LinkedList::getTail()
{
	return g_pTail;
}
Student* LinkedList::getCurrent()
{
	return g_pCurrent;
}

Student* LinkedList::search(char name[]) //��� Ž��(���� Ž��)
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

void LinkedList::deleteNode(Student* delNode)
{
	Student* prevNode = delNode->m_pPrev;
	Student* nextNode = delNode->m_pNext;

	prevNode->m_pNext = nextNode;
	nextNode->m_pPrev = prevNode;
}

void LinkedList::deleteAll() // ��ü����
{
	g_pCurrent = g_pHead->m_pNext;

	while (g_pCurrent != g_pTail)
	{
		Student* nextNode = g_pCurrent->m_pNext;

		delete(g_pCurrent);
		g_pCurrent = nextNode;
	}

	g_pHead->m_pNext = g_pTail;
	g_pTail->m_pPrev = g_pHead;
}

//��� �߰���� �Լ�(1 : ����, 2 : ����)
void LinkedList::insert(Student* newNode, Student* currentNode, int select)
{
	if (select == 1)
	{
		Student* prevNode = currentNode->m_pPrev;

		newNode->m_pPrev = prevNode;
		newNode->m_pNext = currentNode;
		prevNode->m_pNext = newNode;
		currentNode->m_pPrev = newNode;

	}
	else
	{
		Student* nextNode = currentNode->m_pNext;

		newNode->m_pPrev = currentNode;
		newNode->m_pNext = nextNode;
		nextNode->m_pPrev = newNode;
		currentNode->m_pNext = newNode;

	}
}

void LinkedList::frontInsert(Student* newNode) //����Ʈ �� �տ� ����
{
	Student* nextNode = g_pHead->m_pNext;

	newNode->m_pNext = nextNode;
	newNode->m_pPrev = g_pHead;
	nextNode->m_pPrev = newNode;
	g_pHead->m_pNext = newNode;

}

void LinkedList::backInsert(Student* newNode) //����Ʈ �� �ڿ� ����
{
	Student* prevNode = g_pTail->m_pPrev;

	newNode->m_pPrev = prevNode;
	newNode->m_pNext = g_pTail;
	prevNode->m_pNext = newNode;
	g_pTail->m_pPrev = newNode;

}



void LinkedList::sort()
{
	Student* cmpNode = g_pHead->m_pNext;
	Student* nextNode;
	Student* prevNode;
	Student* cntNext;
	g_pCurrent = g_pHead;

	while (g_pCurrent != g_pTail->m_pPrev)
	{
		for (Student* node = cmpNode->m_pNext; node != g_pTail; node = node->m_pNext)
		{
			if (node->total < cmpNode->total)
			{
				cmpNode = node;
			}
		}

		if (g_pCurrent->m_pNext == cmpNode)
		{
			g_pCurrent = g_pCurrent->m_pNext;
			cmpNode = cmpNode->m_pNext;

			continue;
		}
		prevNode = cmpNode->m_pPrev;
		nextNode = cmpNode->m_pNext;
		cntNext = g_pCurrent->m_pNext;

		prevNode->m_pNext = nextNode;
		nextNode->m_pPrev = prevNode;
		g_pCurrent->m_pNext = cmpNode;
		cmpNode->m_pPrev = g_pCurrent;
		cmpNode->m_pNext = cntNext;
		cntNext->m_pPrev = cmpNode;

		g_pCurrent = g_pCurrent->m_pNext;
		cmpNode = cmpNode->m_pNext;
	}
}

int LinkedList::isFull(StdManagement *manage)
{
	if (g_pHead->m_pNext != g_pTail)
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



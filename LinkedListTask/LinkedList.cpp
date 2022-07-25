#include "LinkedList.h"

template <class T>
void TLinkedList<T>::newList()
{
	setHead(new TNode<T>);
	setTail(new TNode<T>);
	setCurrent(new TNode<T>);

	getHead()->m_pNext = getTail();
	getTail()->m_pPrev = getHead();
}

template <class T>
void TLinkedList<T>::frontInsert(T student) //����Ʈ �� �տ� ����
{
	TNode<T>* newNode = new TNode<T>();
	newNode->Data = student;

	TNode<T> nextNode = getHead()->m_pNext;

	newNode->m_pNext = nextNode;
	newNode->m_pPrev = getHead();
	nextNode->m_pPrev = newNode;
	getHead()->m_pNext = newNode;

}

template <class T>
void TLinkedList<T>::backInsert(T student) //����Ʈ �� �ڿ� ����
{
	TNode<T>* newNode = new TNode<T>();
	newNode->Data = student;

	TNode<T>* prevNode = getTail()->m_pPrev;

	newNode->m_pPrev = prevNode;
	newNode->m_pNext = getTail();
	prevNode->m_pNext = newNode;
	getTail()->m_pPrev = newNode;

}

//��� �߰���� �Լ�(1 : ����, 2 : ����)
template <class T>
void TLinkedList<T>::insert(T student, TNode<T> currentNode, int select)
{
	TNode<T>* newNode = new TNode<T>();
	newNode->Data = student;

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

template <class T>
void TLinkedList<T>::allPrint() //��ü ���� ����Ʈ ���
{
	if (getHead()->m_pNext == getTail())
	{
		cout << "����� �׸��� �����ϴ�.\n\n";
		return;
	}

	TNode<T>* node;
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
void TLinkedList<T>::print(TNode<T> node)
{
	Student* student = node->Data;

	cout << "�̸�" << setw(10) << "����" << setw(10) << "����1" << setw(10) << "����2" << setw(10) << "����3"
		<< setw(10) << "����";
	cout << "============================================================\n";
	cout << student->name << setw(10) << student->age << setw(10) << student->score1 << setw(10) << student->score2 << setw(10)
		<< student->score3 << setw(10) << student->total << "\n\n";
	cout << "��.\n\n";
}

template <class T>
void TLinkedList<T>::deleteAll() // ��ü����
{
	setCurrent(getHead()->m_pNext);

	while (getCurrent() != getTail())
	{
		TNode<T> nextNode = getCurrent()->m_pNext;

		delete(getCurrent());
		setCurrent(nextNode);
	}

	getHead()->m_pNext = getTail();
	getTail()->m_pPrev = getHead();
}

template <class T>
TNode<T> TLinkedList<T>::search(char name[]) //��� Ž��(���� Ž��)
{
	if (getHead()->m_pNext == getTail())
	{
		return;
	}
	for (TNode<T> node = getHead()->m_pNext; node != getTail(); node = node->m_pNext)
	{
		Student* student = &node->Data;
		if (strcmp(name, student->name) == 0)
		{
			return node;
		}
	}

	printf("ã�� ���� �����ϴ�!\n\n");

	return NULL;
}

template <class T>
void TLinkedList<T>::sort()
{
	TNode<T>* cmpNode = m_pHead->m_pNext;
	TNode<T>* nextNode;
	TNode<T>* prevNode;
	TNode<T>* cntNext;
	m_pCurrent = m_pHead;

	while (m_pCurrent != m_pTail->m_pPrev)
	{
		for (TNode<T> node = cmpNode->m_pNext; node != m_pTail; node = node->m_pNext)
		{
			Student student = node->data;
			if (node->total < cmpNode->total)
			{
				cmpNode = node;
			}
		}

		if (m_pCurrent->m_pNext == cmpNode)
		{
			m_pCurrent = m_pCurrent->m_pNext;
			cmpNode = cmpNode->m_pNext;

			continue;
		}
		prevNode = cmpNode->m_pPrev;
		nextNode = cmpNode->m_pNext;
		cntNext = m_pCurrent->m_pNext;

		prevNode->m_pNext = nextNode;
		nextNode->m_pPrev = prevNode;
		m_pCurrent->m_pNext = cmpNode;
		cmpNode->m_pPrev = m_pCurrent;
		cmpNode->m_pNext = cntNext;
		cntNext->m_pPrev = cmpNode;

		m_pCurrent = m_pCurrent->m_pNext;
		cmpNode = cmpNode->m_pNext;
	}
}




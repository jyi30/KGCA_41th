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
void TLinkedList<T>::frontInsert(T student) //리스트 맨 앞에 삽입
{
	TNode<T>* newNode = new TNode<T>();
	newNode->Data = student;

	TNode<T>* nextNode = getHead()->m_pNext;

	newNode->m_pNext = nextNode;
	newNode->m_pPrev = getHead();
	nextNode->m_pPrev = newNode;
	getHead()->m_pNext = newNode;

}

template <class T>
void TLinkedList<T>::backInsert(T* student) //리스트 맨 뒤에 삽입
{
	TNode<T>* newNode = new TNode<T>();
	newNode->Data = *student;

	TNode<T>* prevNode = getTail()->m_pPrev;

	newNode->m_pPrev = prevNode;
	newNode->m_pNext = getTail();
	prevNode->m_pNext = newNode;
	getTail()->m_pPrev = newNode;

}

//노드 추가기능 함수(1 : 전위, 2 : 후위)
template <class T>
void TLinkedList<T>::insert(T student, TNode<T>* currentNode, int select)
{
	TNode<T>* newNode = new TNode<T>();
	newNode->Data = student;

	if (select == 1)
	{
		TNode<T>* prevNode = currentNode->m_pPrev;

		newNode->m_pPrev = prevNode;
		newNode->m_pNext = currentNode;
		prevNode->m_pNext = newNode;
		currentNode->m_pPrev = newNode;

	}
	else
	{
		TNode<T>* nextNode = currentNode->m_pNext;

		newNode->m_pPrev = currentNode;
		newNode->m_pNext = nextNode;
		nextNode->m_pPrev = newNode;
		currentNode->m_pNext = newNode;

	}
}

template <class T>
void TLinkedList<T>::allPrint() //전체 연결 리스트 출력
{
	if (getHead()->m_pNext == getTail())
	{
		cout << "출력할 항목이 없습니다.\n\n";
		return;
	}

	TNode<T>* node;
	Student* student;

	cout.setf(ios::left);
	cout << setw(10) << "이름" << setw(10) << "나이" << setw(10) << "점수1" << setw(10) << "점수2" << setw(10)
		<< "점수3" << setw(10) << "총점" << endl;
	cout << "============================================================\n";
	for (node = getHead()->m_pNext; node != getTail(); node = node->m_pNext)
	{
		student = &node->Data;
		cout << setw(10) << student->getName() << setw(10) << student->getAge() << setw(10) << student->getScore1() << setw(10)
			<< student->getScore2() << setw(10) << student->getScore3() << setw(10) << student->getTotal() << "\n\n";
	}
	cout << "끝.\n\n";
}

template <class T>
void TLinkedList<T>::print(TNode<Student>* node)
{
	Student* student = &node->Data;

	cout.setf(ios::left);
	cout << setw(10) << "이름" << setw(10) << "나이" << setw(10) << "점수1" << setw(10) << "점수2" << setw(10) << "점수3"
		<< setw(10) << "총점" << endl;
	cout << "============================================================\n";
	cout << setw(10) << student->getName() << setw(10) << student->getAge() << setw(10) << student->getScore1() << setw(10) << student->getScore2() << setw(10)
		<< student->getScore3() << setw(10) << student->getTotal() << "\n\n";
	cout << "끝.\n\n";
}

template <class T>
void TLinkedList<T>::deleteNode(TNode<T>* delNode)
{
	TNode<T>* prevNode = delNode->m_pPrev;
	TNode<T>* nextNode = delNode->m_pNext;

	prevNode->m_pNext = nextNode;
	nextNode->m_pPrev = prevNode;
}

template <class T>
void TLinkedList<T>::deleteAll() // 전체삭제
{
	setCurrent(getHead()->m_pNext);

	while (getCurrent() != getTail())
	{
		TNode<T>* nextNode = getCurrent()->m_pNext;

		delete(getCurrent());
		setCurrent(nextNode);
	}

	getHead()->m_pNext = getTail();
	getTail()->m_pPrev = getHead();
}

template <class T>
TNode<T>* TLinkedList<T>::search(char name[]) //노드 탐색(순차 탐색)
{
	if (getHead()->m_pNext == getTail())
	{
		return NULL;
	}
	for (TNode<T>* node = getHead()->m_pNext; node != getTail(); node = node->m_pNext)
	{
		Student* student = &node->Data;
		if (strcmp(name, student->getName()) == 0)
		{
			return node;
		}
	}

	return NULL;
}

template <class T>
void TLinkedList<T>::sortASC()
{
	TNode<T>* cmpNode = getHead()->m_pNext;
	TNode<T>* nextNode;
	TNode<T>* prevNode;
	TNode<T>* cntNext;
	setCurrent(getHead());

	while (getCurrent() != getTail()->m_pPrev)
	{
		for (TNode<T>* node = cmpNode->m_pNext; node != getTail(); node = node->m_pNext)
		{
			Student* student = &node->Data;
			Student* cmpStd = &cmpNode->Data;
			if (student->getTotal() < cmpStd->getTotal())
			{
				cmpNode = node;
			}
		}

		if (getCurrent()->m_pNext == cmpNode)
		{
			setCurrent(getCurrent()->m_pNext);
			cmpNode = cmpNode->m_pNext;

			continue;
		}
		prevNode = cmpNode->m_pPrev;
		nextNode = cmpNode->m_pNext;
		cntNext = getCurrent()->m_pNext;

		prevNode->m_pNext = nextNode;
		nextNode->m_pPrev = prevNode;
		getCurrent()->m_pNext = cmpNode;
		cmpNode->m_pPrev = getCurrent();
		cmpNode->m_pNext = cntNext;
		cntNext->m_pPrev = cmpNode;

		setCurrent(getCurrent()->m_pNext);
		cmpNode = cmpNode->m_pNext;
	}
}

template <class T>
void TLinkedList<T>::sortDESC()
{
	TNode<T>* cmpNode = getHead()->m_pNext;
	TNode<T>* nextNode;
	TNode<T>* prevNode;
	TNode<T>* cntNext;
	setCurrent(getHead());

	while (getCurrent() != getTail()->m_pPrev)
	{
		for (TNode<T>* node = cmpNode->m_pNext; node != getTail(); node = node->m_pNext)
		{
			Student* student = &node->Data;
			Student* cmpStd = &cmpNode->Data;
			if (student->getTotal() > cmpStd->getTotal())
			{
				cmpNode = node;
			}
		}

		if (getCurrent()->m_pNext == cmpNode)
		{
			setCurrent(getCurrent()->m_pNext);
			cmpNode = cmpNode->m_pNext;

			continue;
		}
		prevNode = cmpNode->m_pPrev;
		nextNode = cmpNode->m_pNext;
		cntNext = getCurrent()->m_pNext;

		prevNode->m_pNext = nextNode;
		nextNode->m_pPrev = prevNode;
		getCurrent()->m_pNext = cmpNode;
		cmpNode->m_pPrev = getCurrent();
		cmpNode->m_pNext = cntNext;
		cntNext->m_pPrev = cmpNode;

		setCurrent(getCurrent()->m_pNext);
		cmpNode = cmpNode->m_pNext;
	}
}




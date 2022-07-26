#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
using namespace std;

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
	void newList();
	void backInsert(T* student);
	void frontInsert(T student);
	void insert(T student, TNode<T>* currentNode, int select);
	void print(TNode<Student>* node);
	void allPrint();
	void deleteNode(TNode<T>* delNode);
	void deleteAll(); 
	TNode<T>* search(char name[]);
	void sortASC();
	void sortDESC();

public:
	TNode<T>* getHead();
	TNode<T>* getTail();
	TNode<T>* getCurrent();
	void setHead(TNode<T>* head);
	void setTail(TNode<T>* tail);
	void setCurrent(TNode<T>* current);
};

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

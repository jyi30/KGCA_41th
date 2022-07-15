#pragma once
#include "Student.h"
class StdManagement;

class LinkedList
{
protected:
	Student* g_pHead = NULL;
	Student* g_pTail = NULL;
	Student* g_pCurrent = NULL;
	
public:
	Student* search(char name[]);
	Student* getHead();
	Student* getTail();
	Student* getCurrent();
	void deleteNode(Student* delNode);
	void deleteAll();
	void insert(Student* newNode, Student* currentNode, int select);
	void frontInsert(Student* student);
	void backInsert(Student* student);
	void sort();
	int isFull(StdManagement*);

public:
	LinkedList();
	~LinkedList();
};


#pragma once
#include <iostream>
#include "FileIO.h"
#include "LinkedList.h"
#include "Student.h"
using namespace std;

class DataManager
{
private:
	TLinkedList<Student> link;
	FileIO fileio;
	Student student;
public:
	DataManager();
	~DataManager();
	void init();
	void randomCreate(int count);
	void insert();
	//void deleteNode();
	//void deleteNode(char name[]);
	int isFull();
	int isEmpty();
	void print();
	void print(char name[]);
	void fileCtr(int num);
	
};


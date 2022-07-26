#pragma once
#include <iostream>
#include "FileIO.h"
#include "LinkedList.cpp"
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
	void deleteNode();
	void deleteNode(char name[]);
	int isFull();
	int isEmpty();
	void find(char name[]);
	void print();
	void print(char name[]);
	void sort(int num);
	void fileCtr(int num);
	
};


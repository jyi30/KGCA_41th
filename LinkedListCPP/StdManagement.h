#pragma once
#include "LinkedList.h"

class StdManagement : public LinkedList
{
public:
	Student* newNode();
	int init();
	void create(int count);
	void allPrint();
	void print(Student* node);
	void saveFile();
	void loadFile();
	StdManagement();
	~StdManagement();


};


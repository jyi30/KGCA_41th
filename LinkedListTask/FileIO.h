#pragma once
#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

class FileIO
{
private:
	ofstream ofs;
	ifstream ifs;
public:
	void saveFile(TLinkedList<Student> link);
	void loadFile(TLinkedList<Student> link);
};


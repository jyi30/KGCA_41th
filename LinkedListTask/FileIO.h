#pragma once
#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;

class FileIO
{
public:
	void saveFile(TLinkedList<Student> link);
	void loadFile(TLinkedList<Student> link);
};


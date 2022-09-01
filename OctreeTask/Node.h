#pragma once
#include <Windows.h>
#include <map>
#include "Collision.h"
#include "Object.h"

class Node
{
public:
	Box box;
	int depth;
	std::vector<Node*> child;
	std::vector<Object*> staticObject;
	std::vector<Object*> dynamicObject;
	Node* parent;
public:
	Node() {};
	Node(Node* parent, Vector pos, Vector size);
	~Node();
};


#pragma once
#include <iostream>
#include <map>
#include <queue>


class TNode
{
public:
	int depth;
	TNode* parents;
public:
	TNode();
	TNode(TNode* parents);
	~TNode();
};


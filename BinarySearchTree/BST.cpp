#include "BST.h"

class TNode
{
public:
	int depth;
	int index;
	TNode* parents;
	TNode* child[2];

	TNode() : depth(0), index(-1)
	{
		for (int iNode = 0; iNode < 2; iNode++)
		{
			child[iNode] = nullptr;
		}
		parents = nullptr;
	}
};


int g_iData[10] = { 5, 0, 4, 7, 8, 3, 9, 2, 6, 1 };
int g_pCounter = 0;

TNode* createNode(TNode* parentNode)
{
	TNode* newNode = new TNode;
	newNode->index = g_pCounter++;
	if (parentNode != nullptr)
	{
		newNode->parents = parentNode;
		newNode->depth = parentNode->depth + 1;
	}

	return newNode;
}



int main(void)
{

}

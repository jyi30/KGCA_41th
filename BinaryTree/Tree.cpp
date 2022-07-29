#include "Tree.h"

class TNode
{
public:
	int index;
	int depth;
	TNode* m_pParents;
	TNode* m_pChild[2];

	TNode() : index(-1), depth(0)
	{
		for (int iNode = 0; iNode < 2; iNode++)
		{
			m_pChild[iNode] = nullptr;
		}
		m_pParents = nullptr;
	}
	~TNode()
	{
		//std::cout << this->index << " ";
	}
};

TNode* g_pRootNode = nullptr;
int g_pMaxDepth = 3;
int g_pCounter = 0;
int maxNodeCount = pow(2.0f, g_pMaxDepth + 1) - 1;
TNode** g_pNodeArray = new TNode*[200];

TNode* createNode(TNode* pParents)
{
	TNode* newNode = new TNode;
	newNode->index = g_pCounter++;
	if (pParents != nullptr) //루트노드는 제외
	{
		newNode->m_pParents = pParents;
		newNode->depth = pParents->depth + 1;
	}

	return newNode;
}

void build(TNode* pParents)
{
	if (pParents->depth >= g_pMaxDepth)
	{
		return;
	}

	pParents->m_pChild[0] = createNode(pParents);
	pParents->m_pChild[1] = createNode(pParents);
	/*int iSelectLeft = 2 * pParents->index + 1;
	int iSelectRight = 2 * (pParents->index + 1);
	g_pNodeArray[iSelectLeft] = pParents->m_pChild[0];
	g_pNodeArray[iSelectRight] = pParents->m_pChild[1];*/
	build(pParents->m_pChild[0]);
	build(pParents->m_pChild[1]);
}

void print(TNode* pParent) //Postorder 방식
{
	if (pParent == nullptr)
	{
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		print(pParent->m_pChild[i]);
	}
	cout << " " << pParent->index;
}

void printTree()
{
	int nodeCount = 0;
	int count = 0;
	for (int i = g_pMaxDepth; i >= 0; i--)
	{
		count = 1;
		for (int tab = i; tab >= 0; tab--)
		{
			cout << "\t";
		}
		while (1)
		{
			TNode* node = g_pNodeArray[nodeCount];
			cout << node->index;
			if (count % 2 == 1)
			{
				cout << "\t\t";
			}
			count++;
			nodeCount++;
			if (count > pow(2.0f, g_pMaxDepth - i))
			{
				break;
			}
		}

		cout << endl;
	}
}

void deleteAll(TNode* pParent)
{
	if (pParent == nullptr)
	{
		return;
	}
	for (int i = 0; i < 2; i++)
	{
		deleteAll(pParent->m_pChild[i]);
	}
	delete pParent;
	pParent = nullptr;
}

int main(void)
{
	TNode* rootNode = createNode(nullptr);
	g_pNodeArray[0] = rootNode;

	build(rootNode);
	print(rootNode);
	cout << endl;
	deleteAll(rootNode);
}
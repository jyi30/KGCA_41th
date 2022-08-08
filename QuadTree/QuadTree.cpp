#include <iostream>
#include <vector>
#include <queue>

class TObject
{
public:
	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	TObject()
	{
		m_fX = rand() % 100;
		m_fY = rand() % 100;
		m_fWidth = 2.0f + (rand() % 10);
		m_fHeight = 2.0f + (rand() % 10);
	}
};

class TNode
{
public:
	float m_fX;
	float m_fY;
	float m_fWidth;
	float m_fHeight;
	int m_iDepth;
	std::vector<TObject*> m_ObjectList;
	TNode* m_pChild[4];
	TNode* m_pParent;
public:
	TNode(TNode* pParent, float x, float y, float w, float h)
	{
		m_fX = x;
		m_fY = y;
		m_fWidth = w;
		m_fHeight = h;
		m_iDepth = 0;
		m_pParent = nullptr;
		if (pParent != nullptr)
		{
			m_pParent = pParent;
			m_iDepth = pParent->m_iDepth + 1;
		}
	}
	~TNode()
	{
		delete m_pChild[0];
		delete m_pChild[1];
		delete m_pChild[2];
		delete m_pChild[3];
	}
};

std::queue<TNode*> g_Queue;
class TQuadTree
{
public:
	TNode* m_pRootNode;
public:
	void Create(float fWidth, float fHeight);
	TNode* CreateNode(TNode* pParent, float fPosX, float fPosY, float fWidth, float fHeight);
	void Buildtree(TNode* pNode);
	void AddObject(TObject* pObj);
	TNode* FindNode(TNode* pNode, TObject* pObj);
	bool RectToRect(TNode* pNode, TObject* pObj);
	~TQuadTree()
	{
		delete m_pRootNode;
	}
};

//루트노드 생성 후 쿼드 트리 빌디
void TQuadTree::Create(float fWidth, float fHeight) 
{
	//부모가 없고 좌표가 0, 0이며 크기가 fWidth, fHeight인 좌표계의 루트노드 생성
	m_pRootNode = CreateNode(nullptr, 0, 0, fWidth, fHeight); 
	Buildtree(m_pRootNode);
}

void TQuadTree::Buildtree(TNode* pNode)
{
	if (pNode->m_iDepth >= 2)
	{
		return;
	}

	if (pNode == nullptr)
	{
		return;
	}

	float x, y, w, h;
	x = pNode->m_fX;
	y = pNode->m_fY;
	w = pNode->m_fWidth / 2.0f;
	h = pNode->m_fHeight / 2.0f;
	pNode->m_pChild[0] = CreateNode(pNode, x, y, w, h);
	x = pNode->m_fX + w;
	y = pNode->m_fY;
	pNode->m_pChild[1] = CreateNode(pNode, x, y, w, h);
	x = pNode->m_fX;
	y = pNode->m_fY + h;
	pNode->m_pChild[2] = CreateNode(pNode, x, y, w, h);
	x = pNode->m_fX + w;
	y = pNode->m_fY + h;
	pNode->m_pChild[3] = CreateNode(pNode, x, y, w, h);

	for (int iChild = 0; iChild < 4; iChild++)
	{
		Buildtree(pNode->m_pChild[iChild]);
	}
}

TNode* TQuadTree::CreateNode(TNode* pParent, float x, float y, float w, float h)
{
	TNode* pNode = new TNode(pParent, x, y, w, h);
	return pNode;
}

void TQuadTree::AddObject(TObject* pObj)
{
	TNode* pFindNode = FindNode(m_pRootNode, pObj);
	if (pFindNode != nullptr)
	{
		pFindNode->m_ObjectList.push_back(pObj);
	}
}

TNode* TQuadTree::FindNode(TNode* pNode, TObject* pObj)
{
	do
	{
		for (int iNode = 0; iNode < 4; iNode++)
		{
			if (pNode->m_pChild[iNode] != nullptr)
			{
				bool bIn = RectToRect(pNode->m_pChild[iNode], pObj);
				if (bIn > 0)
				{
					g_Queue.push(pNode->m_pChild[iNode]);
					break;
				}
			}
		}
		if (g_Queue.empty())
		{
			break;
		}
		pNode = g_Queue.front();
		g_Queue.pop();
	} while (pNode);
	return pNode;
}

bool TQuadTree::RectToRect(TNode* pNode, TObject* pObj)
{
	if (pNode->m_fX <= pObj->m_fX)
	{
		if ((pNode->m_fX + pNode->m_fWidth) >= pObj->m_fX + pObj->m_fWidth)
		{
			if (pNode->m_fY <= pObj->m_fY)
			{
				if ((pNode->m_fY + pNode->m_fHeight) >= pObj->m_fY + pObj->m_fHeight)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	TQuadTree quadTree;

	quadTree.Create(100.0f, 100.0f);
	for (int iObj = 0; iObj < 10; iObj++)
	{
		TObject* pObj = new TObject;
		quadTree.AddObject(pObj);
	}
}
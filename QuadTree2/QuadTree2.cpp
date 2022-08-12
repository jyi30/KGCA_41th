//플레이어 오브젝트와 쿼드트리에 배치된 오브젝트 간의 충돌 관계

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
	void setPosition(float x, float y, float w, float h)
	{
		m_fX = x;
		m_fY = y;
		m_fWidth = w;
		m_fHeight = h;
	}
	TObject()
	{
		m_fX = 20 + (rand() % 80);
		m_fY = 20 + (rand() % 80);
		m_fWidth = 10.0f + (rand() % 10);
		m_fHeight = 10.0f + (rand() % 10);
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
	TNode* m_pChlid[4];
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
		delete m_pChlid[0];
		delete m_pChlid[1];
		delete m_pChlid[2];
		delete m_pChlid[3];
	}
};

std::queue<TNode*> g_Queue;
class TQuadTree
{
public:
	TNode* m_pRootNode;
public:
	std::vector<TObject*> collision(TObject* pObj);
	void create(float fWidth, float fHeight);
	TNode* createNode(TNode* pParent, float fPosX, float fPosY, float fWidth, float fHeight);
	void buildTree(TNode* pNode);
	void addObject(TObject* pObj);
	TNode* findNode(TNode* pNode, TObject* pObj);
	bool rectToInRect(TNode* pNode, TObject* pObj);
	int rectToRect(TNode* pNode, TObject* pObj);
	int rectToRect(TObject* pDestNode, TObject* pSrcObj);
	void getCollisionObject(TNode* pNode, TObject* obj, std::vector<TObject*>& list);

	~TQuadTree()
	{
		delete m_pRootNode;
	}
};

void TQuadTree::create(float fWidth, float fHeight)
{
	m_pRootNode = createNode(nullptr, 0, 0, fWidth, fHeight);
	buildTree(m_pRootNode);
}

TNode* TQuadTree::createNode(TNode* pParent, float x, float y, float w, float h)
{
	TNode* pNode = new TNode(pParent, x, y, w, h);
	return pNode;
}

void TQuadTree::buildTree(TNode* pNode)
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
	pNode->m_pChlid[0] = createNode(pNode, x, y, w, h);
	x = pNode->m_fX + w;
	y = pNode->m_fY;
	pNode->m_pChlid[1] = createNode(pNode, x, y, w, h);
	x = pNode->m_fX;
	y = pNode->m_fY + h;
	pNode->m_pChlid[2] = createNode(pNode, x, y, w, h);
	x = pNode->m_fX + w;
	y = pNode->m_fY + h;
	pNode->m_pChlid[3] = createNode(pNode, x, y, w, h);

	for (int iChild = 0; iChild < 4; iChild++)
	{
		buildTree(pNode->m_pChlid[iChild]);
	}
}

// 오브젝트를 노드에 추가하는 방법 선택지
// 1번 : 완전히 포함하는 노드에만 추가하자 (이번 코드에선 1번 선택)
// 2번 : 걸쳐만 있어도 노드에 추가하자
void TQuadTree::addObject(TObject* pObj)
{
	TNode* pFindNode = findNode(m_pRootNode, pObj);
	if (pFindNode != nullptr)
	{
		pFindNode->m_ObjectList.push_back(pObj);
	}
}

TNode* TQuadTree::findNode(TNode* pNode, TObject* pObj)
{
	do
	{
		for (int iNode = 0; iNode < 4; iNode++)
		{
			if (pNode->m_pChlid[iNode] != nullptr)
			{
				bool bIn = rectToInRect(pNode->m_pChlid[iNode], pObj);
				if (bIn > 0)
				{
					g_Queue.push(pNode->m_pChlid[iNode]);
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

bool TQuadTree::rectToInRect(TNode* pNode, TObject* pObj)
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

int TQuadTree::rectToRect(TNode* pNode, TObject* pObj)
{
	// 0 : 완전제외(0)
	// 1 : 완전포함(1) -> 걸쳐져 있는 상태(2)
	// x1(10)-------30-------x2(40)
	float x1 = pNode->m_fX;
	float y1 = pNode->m_fY;
	float x2 = pNode->m_fX + pNode->m_fWidth;
	float y2 = pNode->m_fY + pNode->m_fHeight;

	float z1 = pObj->m_fX;
	float w1 = pObj->m_fY;
	float z2 = pObj->m_fX + pObj->m_fWidth;
	float w2 = pObj->m_fY + pObj->m_fHeight;
	
	//합집합
	float fMinX;
	float fMinY;
	float fMaxX;
	float fMaxY;

	fMinX = x1 < z1 ? x1 : z1;
	fMinY = y1 < w1 ? y1 : w1;
	fMaxX = x2 < z2 ? x2 : z2;
	fMaxY = y2 < w2 ? y2 : w2;

	// 가로판정
	if ((pNode->m_fWidth + pObj->m_fWidth) >= (fMaxX - fMinX))
	{	//세로판정
		if ((pNode->m_fHeight + pObj->m_fHeight) >= (fMaxY - fMinY))
		{
			//교차한다. 교집합
			return 1;
		}
	}
	return 0;
}

int TQuadTree::rectToRect(TObject* pDestObj, TObject* pObj)
{
	// 0 : 완전제외(0)
	// 1 : 완전포함(1) -> 걸쳐져 있는 상태(2)
	// x1(10)-------30-------x2(40)
	float x1 = pDestObj->m_fX;
	float y1 = pDestObj->m_fY;
	float x2 = pDestObj->m_fX + pDestObj->m_fWidth;
	float y2 = pDestObj->m_fY + pDestObj->m_fHeight;

	float z1 = pObj->m_fX;
	float w1 = pObj->m_fY;
	float z2 = pObj->m_fX + pObj->m_fWidth;
	float w2 = pObj->m_fY + pObj->m_fHeight;

	//합집합
	float fMinX;
	float fMinY;
	float fMaxX;
	float fMaxY;

	fMinX = x1 < z1 ? x1 : z1;
	fMinY = y1 < w1 ? y1 : w1;
	fMaxX = x2 > z2 ? x2 : z2;
	fMaxY = y2 > w2 ? y2 : w2;

	// 가로판정
	if ((pDestObj->m_fWidth + pObj->m_fWidth) >= (fMaxX - fMinX))
	{	//세로판정
		if ((pDestObj->m_fHeight + pObj->m_fHeight) >= (fMaxY - fMinY))
		{
			//교차한다. 교집합
			return 1;
		}
	}
	return 0;
}



std::vector<TObject*> TQuadTree::collision(TObject* pObj)
{
	std::vector<TObject*> list;
	getCollisionObject(this->m_pRootNode, pObj, list);
	return list;
}

void TQuadTree::getCollisionObject(TNode* pNode, TObject* pObj, std::vector<TObject*>& list)
{
	if (pNode == nullptr)
	{
		return;
	}
	for (int iObj = 0; iObj < pNode->m_ObjectList.size(); iObj++)
	{
		if (rectToRect(pNode->m_ObjectList[iObj], pObj))
		{
			list.push_back(pNode->m_ObjectList[iObj]);
		}
	}
	if (pNode->m_pChlid[0] == nullptr)
	{
		for (int iChild = 0; iChild < 4; iChild++)
		{
			if (rectToRect(pNode->m_pChlid[iChild], pObj))
			{
				getCollisionObject(pNode->m_pChlid[iChild], pObj, list);
			}
		}
	}
}

int main()
{
	TObject player;
	player.setPosition(10, 10, 30, 30);
	TQuadTree quadTree;
	quadTree.create(100.0f, 100.0f);

	for (int iObj = 0; iObj < 100; iObj++)
	{
		TObject* pObj = new TObject;
		quadTree.addObject(pObj);
	}

	std::vector<TObject*> list = quadTree.collision(&player);
	if (!list.empty())
	{
		for (int iObj = 0; iObj < list.size(); iObj++)
		{
			std::cout << list[iObj]->m_fX << list[iObj]->m_fY << std::endl;
		}
	}

}
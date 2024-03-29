#include <Windows.h>
#include "TCollision.h"

class TObject
{
public:
	TRect m_rt;
	TCircle m_Circle;
	void SetCircle(float x, float y, float w, float h)
	{
		m_Circle.cx = x;
		m_Circle.cy = y;
		float x1 = w / 2.0f;
		float y1 = h / 2.0f;
		m_Circle.fRadius = sqrt(x1 * x1 + y1 * y1);
	}
	void SetPosition(float x, float y, float w, float h)
	{
		m_rt.Set(x, y, w, h);
		SetCircle(m_rt.cx, m_rt.cy, m_rt.w, m_rt.h);
	}
	TObject()
	{
		m_rt.Set(20 + (rand() % 80), 20 + (rand() % 80), 5.0f + (rand() % 5), 5.0f + (rand() % 5));
		SetCircle(m_rt.cx, m_rt.cy, m_rt.w, m_rt.h);
	}
};

class TNode
{
public:
	TRect m_rt;
	int m_iDepth;
	std::vector<TObject*> m_ObjectList;
	TNode* m_pChild[4];
	TNode* m_pParent;
public:
	TNode(TNode* pParent, float x, float y, float w, float h)
	{
		m_rt.Set(x, y, w, h);
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

class TQuadTree3
{
public:
	TNode* m_pRootNode;
public:
	std::vector<TObject*> Collision(TObject* pObj);
	void Create(float fWidth, float fHeight);
	TNode* CreateNode(TNode* pParent, float fPosX, float fPosY, float fWidth, float fHeight);
	void BuildTree(TNode* pNode);
	void AddObject(TObject* pObj);
	TNode* FindNode(TNode* pNode, TObject* pObj);
	void GetCollisionObject(TNode* pNode, TObject* obj, std::vector<TObject*>& list);

	~TQuadTree3()
	{
		delete m_pRootNode;
	}
};

void TQuadTree3::Create(float fWidth, float fHeight)
{
	m_pRootNode = CreateNode(nullptr, 0, 0, fWidth, fHeight);
	BuildTree(m_pRootNode);
}

TNode* TQuadTree3::CreateNode(TNode* pParent, float x, float y, float w, float h)
{
	TNode* pNode = new TNode(pParent, x, y, w, h);
	return pNode;
}

void TQuadTree3::BuildTree(TNode* pNode)
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
	x = pNode->m_rt.x1;
	y = pNode->m_rt.y1;
	w = pNode->m_rt.w / 2.0f;
	h = pNode->m_rt.h / 2.0f;
	pNode->m_pChild[0] = CreateNode(pNode, x, y, w, h);
	x = pNode->m_rt.x1 + w;
	y = pNode->m_rt.y1;
	pNode->m_pChild[1] = CreateNode(pNode, x, y, w, h);
	x = pNode->m_rt.x1;
	y = pNode->m_rt.y1 + h;
	pNode->m_pChild[2] = CreateNode(pNode, x, y, w, h);
	x = pNode->m_rt.x1 + w;
	y = pNode->m_rt.y1 + h;
	pNode->m_pChild[3] = CreateNode(pNode, x, y, w, h);

	for (int iChild = 0; iChild < 4; iChild++)
	{
		BuildTree(pNode->m_pChild[iChild]);
	}
}

void TQuadTree3::AddObject(TObject* pObj)
{
	TNode* pFindNode = FindNode(m_pRootNode, pObj);
	if (pFindNode != nullptr)
	{
		pFindNode->m_ObjectList.push_back(pObj);
	}
}

TNode* TQuadTree3::FindNode(TNode* pNode, TObject* pObj)
{
	do
	{
		for (int iNode = 0; iNode < 4; iNode++)
		{
			if (pNode->m_pChild[iNode] != nullptr)
			{
				bool bIn = TCollision::rectToInRect(pNode->m_pChild[iNode]->m_rt, pObj->m_rt);
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
	} while(pNode);
	return pNode;
}

std::vector<TObject*> TQuadTree3::Collision(TObject* pObj)
{
	std::vector<TObject*> list;
	GetCollisionObject(this->m_pRootNode, pObj, list);
	return list;
}

void TQuadTree3::GetCollisionObject(TNode* pNode, TObject* pSrcObject, std::vector<TObject*>& list)
{
	if (pNode == nullptr)
	{
		return;
	}
	for (int iObj = 0; iObj < pNode->m_ObjectList.size(); iObj++)
	{
		if (TCollision::CircleToCircle(pNode->m_ObjectList[iObj]->m_Circle, pSrcObject->m_Circle))
		{
			if (TCollision::rectToRect(pNode->m_ObjectList[iObj]->m_rt, pSrcObject->m_rt))
			{
				list.push_back(pNode->m_ObjectList[iObj]);
			}
		}
	}
	if (pNode->m_pChild[0] != nullptr)
	{
		for (int iChild = 0; iChild < 4; iChild++)
		{
			if (TCollision::rectToRect(pNode->m_pChild[iChild]->m_rt, pSrcObject->m_rt))
			{
				GetCollisionObject(pNode->m_pChild[iChild], pSrcObject, list);
			}
		}
	}
}

int main()
{
	TObject player;
	player.SetPosition(0, 100, 50, 50);
	TQuadTree3 quadTree;
	quadTree.Create(100.0f, 100.0f);
	float fDistance = 0.0f;
	for (int iObj = 0; iObj < 10; iObj++)
	{
		TObject* pObj = new TObject;
		quadTree.AddObject(pObj);
	}

	while (1)
	{
		std::vector<TObject*> list = quadTree.Collision(&player);
		std::cout << "player:"
			<< player.m_rt.x1 << "," << player.m_rt.y1 << ","
			<< player.m_rt.x2 << "," << player.m_rt.y2
			<< std::endl;
		if (!list.empty())
		{
			for (int iObj = 0; iObj < list.size(); iObj++)
			{
				std::cout << "object : "
					<< list[iObj]->m_rt.x1 << "," << list[iObj]->m_rt.y1 << ","
					<< list[iObj]->m_rt.x2 << "," << list[iObj]->m_rt.y2
					<< std::endl;
			}
		}
		static float fDirectionX = 10.0f;
		if (rand() % 2 == 0)
		{
			fDirectionX *= -1.0f;
		}
		static float fDirectionY = 10.0f;
		if (rand() % 2 == 0)
		{
			fDirectionY *= -1.0f;
		}
		player.m_rt.x1 = player.m_rt.x1 + fDirectionX;
		player.m_rt.y1 = player.m_rt.y1 + fDirectionY;

		player.m_rt.x1 = min(player.m_rt.x1, 100.0f);
		player.m_rt.x1 = max(player.m_rt.x1, 0);
		player.m_rt.y1 = min(player.m_rt.y1, 100.0f);
		player.m_rt.y1 = max(player.m_rt.y1, 0);

		player.SetPosition(player.m_rt.x1, player.m_rt.y1, 30, 30);

		Sleep(100);
		system("cls");
	}
}
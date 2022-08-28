#pragma once
#include "Node.h"
#include "Object.h"
static const int childNodeCount = 8;
class Octree
{
private:
	Node* rootNode;
public:
	Node* createNode(Node* parent, Vector pos, Vector size);
	void createTree(Vector pos, Vector size);
	void buildTree(Node* node);
	void addStaticObject(Object* sObj);
	void addDynamicObject(Object* dObj);
	Node* findNode(Node* node, Object* obj);
	bool nodeInObject(Node* pNode, Object* pObj);
	bool objectCollision(Object* pDest, Object* pSrc);
	bool nodeCollision(Node* pNode, Object* pSrc);
	void GetCollisitionObject(Node* pNode, Object* pSrcObject, std::vector<Object*>& list);
	std::vector<Object*> Collisionlist(Object* pObj);
	void DynamicReset(Node* pNode);
	void DynamicObjectReset();
};


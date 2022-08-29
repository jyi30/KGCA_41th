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
	bool nodeInObject(Node* node, Object* obj);
	bool objectCollision(Object* dest, Object* src);
	bool nodeCollision(Node* node, Object* src);
	void getCollisionObject(Node* node, Object* object, std::vector<Object*>& list);
	std::vector<Object*> collisionList(Object* obj);
	void dynamicReset(Node* Node);
	void dynamicObjectReset();
};


#include "Octree.h"

Node* Octree::createNode(Node* parent, Vector pos, Vector size)
{
	Node* node = new Node(parent, pos, size);
	node->child.resize(childNodeCount);

	return node;
}

void Octree::createTree(Vector pos, Vector size)
{
	rootNode = createNode(nullptr, pos, size);
	buildTree(rootNode);
}

void Octree::buildTree(Node* node)
{
    if (node->depth >= 3)
    {
        return;
    }

    if (node == nullptr)
    {
        return;
    }

    Vector pos;
    Vector size;

    pos = node->box.min;
    size = node->box.size / 2.0f;
    node->child[0] = createNode(node, pos, size);
    pos.x = node->box.min.x + size.x;
    node->child[1] = createNode(node, pos, size);
    pos.x = node->box.min.x;
    pos.y = node->box.min.y + size.y;
    node->child[2] = createNode(node, pos, size);
    pos.x = node->box.min.x + size.x;
    pos.y = node->box.min.y + size.y;
    node->child[3] = createNode(node, pos, size);
    pos.x = node->box.min.x;
    pos.y = node->box.min.y;
    pos.z = node->box.min.z + size.z;
    node->child[4] = createNode(node, pos, size);
    pos.x = node->box.min.x + size.x;
    pos.y = node->box.min.y;
    node->child[5] = createNode(node, pos, size);
    pos.x = node->box.min.x;
    pos.y = node->box.min.y + size.y;
    node->child[6] = createNode(node, pos, size);
    pos.x = node->box.min.x + size.x;
    pos.y = node->box.min.y + size.y;
    node->child[7] = createNode(node, pos, size);

    for (int i = 0; i < node->child.size(); i++)
    {
        buildTree(node->child[i]);
    }
}

void Octree::addStaticObject(Object* obj)
{
    Node* findNodeResult = findNode(rootNode, obj);
    if (findNode != nullptr)
    {
        findNodeResult->staticObject.push_back(obj);
    }
}

void Octree::addDynamicObject(Object* obj)
{
    Node* findNodeResult = findNode(rootNode, obj);
    if (findNode != nullptr)
    {
        findNodeResult->dynamicObject.push_back(obj);
    }
}

Node* Octree::findNode(Node* node, Object* obj)
{
    std::queue<Node*> g_Queue;
    do 
    {
        for (int i = 0; i < node->child.size(); i++)
        {
            if (node->child[i] != nullptr)
            {
                bool bIn = nodeInObject(node->child[i], obj);
                if (bIn)
                {
                    g_Queue.push(node->child[i]);
                    break;
                }
            }
        }
        if (g_Queue.empty())
        {
            break;
        }
        node = g_Queue.front();
        g_Queue.pop();
    } 
    while (node);

    return node;
}

bool Octree::nodeInObject(Node* node, Object* obj)
{
    return Collision::BoxInCollision(node->box, obj->box);
}

bool Octree::objectCollision(Object* Dest, Object* Src)
{
    if (Collision::SphereCollision(Dest->sphere, Src->sphere))
    {
        if (Collision::BoxCollision(Dest->box, Src->box))
        {
            return true;
        }
    }
    return false;
}

bool Octree::nodeCollision(Node* node, Object* pSrc)
{
    if (Collision::BoxCollision(node->box, pSrc->box))
    {
        return true;
    }
    return false;
}

void Octree::GetCollisitionObject(Node* node, Object* pSrcObject, std::vector<Object*>& list)
{
    if (node == nullptr)
    {
        return;
    }

    for (int i = 0; i < node->staticObject.size(); i++)
    {
        if (objectCollision(node->staticObject[i], pSrcObject))
        {
            list.push_back(node->staticObject[i]);
        }
    }
    for (int i = 0; i < node->dynamicObject.size(); i++)
    {
        if (objectCollision(node->dynamicObject[i], pSrcObject))
        {
            list.push_back(node->dynamicObject[i]);
        }
    }
    if (node->child[0] != nullptr)
    {
        for (int i = 0; i < node->child.size(); i++)
        {
            if (nodeCollision(node->child[i], pSrcObject))
            {
                GetCollisitionObject(node->child[i], pSrcObject, list);
            }
        }
    }
}

std::vector<Object*> Octree::Collisionlist(Object* obj)
{
    std::vector<Object*> list;
    GetCollisitionObject(rootNode, obj, list);
    return list;
};

void Octree::DynamicReset(Node* node)
{
    if (node == nullptr)
    {
        return;
    }
    node->dynamicObject.clear();
    for (int i = 0; i < node->child.size(); i++)
    {
        DynamicReset(node->child[i]);
    }
}

void Octree::DynamicObjectReset()
{
    DynamicReset(rootNode);
}
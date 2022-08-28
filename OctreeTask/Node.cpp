#include "Node.h"

Node::Node()
{

}
Node::Node(Node* parent, Vector pos, Vector size)
{
    box.set(pos, size);
    depth = 0;
    parent = nullptr;
    if (parent != nullptr)
    {
        this->parent = parent;
        this->depth = parent->depth + 1;
    }
}
Node::~Node()
{
    for (int i = 0; i < child.size(); i++)
    {
        delete child[i];
    }
}
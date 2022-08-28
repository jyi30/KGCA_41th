#pragma once
#include "TNode.h"
#include "TObject.h"

class TSpacePartition
{
protected:
	TNode*		m_pRootNode;
public:
	virtual void    DynamicObjectReset();
public:
	virtual void    Create(TVector vPos, TVector vSize);
public:
	virtual std::vector<TBaseObject*>   CollisionQuery(TBaseObject* pObj);		
	virtual void    AddStaticObject(TBaseObject* pObj);
	virtual void    AddDynamicObject(TBaseObject* pObj);
protected:
	virtual TNode*	FindNode(TNode* pNode, TBaseObject* pObj);
public:
	TSpacePartition();
	virtual ~TSpacePartition();
};


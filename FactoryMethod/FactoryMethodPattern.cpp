#include <iostream>
#include <vector>

class TBaseObject
{
public:
	TBaseObject() {};
	virtual ~TBaseObject() {};
};

class TObject3D : public TBaseObject
{
public:
	TObject3D() {};
};

class TObject2D : public TBaseObject
{
public:
	TObject2D() {};
};

class TSpaceDivision
{
public:
	std::vector<TBaseObject*> m_list;
public:
	virtual TBaseObject* newObject() = 0; //필수적인 구현 필요
	virtual void add(TBaseObject* obj)
	{
		m_list.push_back(obj);
	}
};

class TQuadTree : public TSpaceDivision
{
public:
	TBaseObject* newObject()
	{
		return new TObject2D;
	}
};

class TOctree : public TSpaceDivision
{
public:
	TBaseObject* newObject()
	{
		return new TObject3D;
	}
};


int main()
{
	TSpaceDivision* sd = new TQuadTree;
	//TSpaceDivision* sd = new TOctree;
	TBaseObject* obj = sd->newObject();
	//sd->add(sd->newObject());
	sd->add(obj);
	std::cout << "끝" << std::endl;
}
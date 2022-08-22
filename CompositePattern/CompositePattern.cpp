#include <iostream>
#include <vector>
#include <map>

class TGraphicObject
{
public:
	virtual TGraphicObject* Clone() = 0;
};

class TTriangle : public TGraphicObject
{
public:
	int* pDataTTriangle;
	int iDataTTriangle[100];
public:
	virtual TGraphicObject* Clone()
	{
		return new TTriangle(*this);
	}
};

class TRectangle : public TGraphicObject
{
public:
	int* pDataTRectangle;
	int iDataTRectangle[100];
public:
	virtual TGraphicObject* NewObject()
	{
		return new TRectangle;
	}
	virtual TGraphicObject* Clone()
	{
		return new TRectangle(*this);
	}
};

class TComposite : public TGraphicObject
{
public:
	std::vector<TGraphicObject*> component;
public:
	TComposite()
	{

	}
	virtual TGraphicObject* Clone()
	{
		TComposite* thisNew = new TComposite();
		for (TGraphicObject* data : component)
		{
			thisNew->component.push_back(data->Clone());
		}
		return thisNew;
	}
};

template<class T>
class TSingleton
{
public:
	static T& GetInstance()
	{
		static T instance;
		return instance;
	}
};

class TPaletteSingleton : public TSingleton<TPaletteSingleton>
{
	friend class TSingleton<TPaletteSingleton>;
public:
	std::map<int, TGraphicObject*> m_list;
	void RegisterNewGraphic(TGraphicObject* pNewGraphic)
	{
		m_list.insert(std::make_pair(m_list.size(), pNewGraphic));
	}
private:
	TPaletteSingleton()
	{
		TGraphicObject* a = new TTriangle;
		TGraphicObject* b = new TRectangle;
		m_list.insert(std::make_pair(0, a));
		m_list.insert(std::make_pair(1, b));
	}
public:
	~TPaletteSingleton()
	{
		for (std::pair<int, TGraphicObject*> data : m_list)
		{
			delete data.second;
		}
		m_list.clear();
	}
};

class TPalette
{
public:
	std::map<int, TGraphicObject*> m_list;
	static TPalette* g_pPalette;
	static TPalette* GetInstance()
	{
		if (g_pPalette == nullptr)
		{
			g_pPalette = new TPalette;
		}
		return g_pPalette;
	}
public:
	TPalette()
	{

	}
public:
	~TPalette()
	{
		for (auto data : m_list)
		{
			delete data.second;
		}
		m_list.clear();
	}
};

TPalette* TPalette::g_pPalette = nullptr;

int main()
{
	TPaletteSingleton paletteG = TPaletteSingleton::GetInstance();
	TPaletteSingleton paletteH = TPaletteSingleton::GetInstance();

	TComposite* pNewModel0 = new TComposite;
	pNewModel0->component.push_back(TPaletteSingleton::GetInstance().m_list[0]->Clone());
	pNewModel0->component.push_back(TPaletteSingleton::GetInstance().m_list[1]->Clone());
	TPaletteSingleton::GetInstance().RegisterNewGraphic(pNewModel0);

	TComposite* pNewModel1 = new TComposite;
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[0]->Clone());
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[1]->Clone());
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[2]->Clone());
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[2]->Clone());
	TPaletteSingleton::GetInstance().RegisterNewGraphic(pNewModel1);

	TComposite* pNewModel2 = new TComposite;
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[0]->Clone());
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[1]->Clone());
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[2]->Clone());
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[3]->Clone());
	TPaletteSingleton::GetInstance().RegisterNewGraphic(pNewModel2);

	TComposite* pNewModel3 = new TComposite;
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[4]->Clone());
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[4]->Clone());
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[4]->Clone());
	pNewModel1->component.push_back(TPaletteSingleton::GetInstance().m_list[4]->Clone());

	TPaletteSingleton::GetInstance().RegisterNewGraphic(pNewModel3);

	TPalette* paletteA = TPalette::GetInstance();
	TPalette* paletteB = TPalette::GetInstance();
	TPalette* paletteC = TPalette::GetInstance();
	TPalette* paletteD = TPalette::GetInstance();
}

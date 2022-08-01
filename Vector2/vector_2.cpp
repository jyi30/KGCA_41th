#include "vector_2.h"

class TItem
{
public:
	int iValue;
	bool operator == (const TItem& p)
	{
		return iValue == p.iValue;
	}
	TItem(int i) : iValue(i)
	{

	}
};

struct IsCmp
{
	int m_iValue;
	IsCmp(int value) : m_iValue(value) {}
	bool operator()(const TItem* item)
	{
		return (item->iValue == m_iValue);
	}
};

bool compareInt(const int& a, const int& b)
{
	return a < b;
}

bool compare(const TItem& a, const TItem& b)
{
	return a.iValue < b.iValue;
}

bool comparePtr(TItem* a, TItem* b)
{
	return a->iValue < b->iValue;
}
int g_iFindValue;
bool find_TItem(TItem* a)
{
	return a->iValue == g_iFindValue;
}

int main(void)
{
	vector<int> listInt;

	for (int i = 0; i < 20; i++)
	{
		listInt.push_back(i);
	}
	for (int i = 0; i < 5; i++)
	{
		listInt.insert(listInt.begin(), 10 + i);
	}
	for (int i = 0; i < 5; i++)
	{
		listInt.insert(listInt.end(), 20 + i);
	}
	int iValue1 = listInt.front();
	int iValue2 = listInt.back();
	listInt.pop_back();

	for (vector<int>::iterator iter = listInt.begin(); iter != listInt.end(); iter++)
	{
		std:; cout << " " << *iter;
	}
	cout << endl;
	for (int value : listInt)
	{
		value = 100;
		cout << " " << value;
	}
	cout << endl;

	sort(listInt.begin(), listInt.end(), compareInt);
	vector<int>::iterator iterint = std::find(listInt.begin(), listInt.end(), 17);
	if (iterint != listInt.end())
	{
		listInt.erase(iterint);
	}
	listInt.clear();

	vector<TItem> listItem;
	
	for (int i = 0; i < 20; i++)
	{
		TItem item(i);
		listItem.push_back(item);
	}

	for (int i = 0; i < 5; i++)
	{
		TItem item(10 + i);
		listItem.insert(listItem.begin(), item);
	}

	for (int i = 0; i < 5; i++)
	{
		TItem item(20 + i);
		listItem.insert(listItem.end(), item);
	}

	sort(listItem.begin(), listItem.end(), compare);
	vector<TItem>::iterator iterItem = find_if(listItem.begin(), listItem.end(), IsCmp(17));
}
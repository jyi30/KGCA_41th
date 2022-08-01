#include "vector_1.h"

int main(void)
{
	//Vector의 선언
	vector<int> list;
	vector<int> findlist;

	//Vector의 
	for (int i = 0; i < 20; i++)
	{
		list.push_back(i);
	}

	for (int i = 0; i < 5; i++)
	{
		list.insert(list.begin() + i, 10 + i);
	}

	for (int i = 0; i < 5; i++)
	{
		list.insert(list.end(), 20 + i);
	}

	sort(list.begin(), list.end());
	vector<int>::iterator iter = find(list.begin(), list.end(), 17);
	list.erase(iter);

	int iValue1 = list.front();
	int iValue2 = list.back();

	list.pop_back();

	for (int value : list)
	{
		value = 50;
		cout << " " << value;
	}
	cout << endl;

	for (int value : list)
	{
		value = 50;
		cout << " " << value;
	}
	cout << endl;

	for (vector<int>::iterator iter = list.begin(); iter != list.end(); iter++)
	{
		cout << " " << *iter;
	}
	cout << endl;

	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << " ";
	}

	list.clear();
}
#include "vector_2.h"

class TItem  //TItem 클래스
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

struct IsCmp //TItem 클래스 비교를 위한 연산자 오버로딩
{
	int m_iValue;
	IsCmp(int value) : m_iValue(value) {}
	bool operator()(const TItem* item)
	{
		return (item->iValue == m_iValue);
	}
};

struct IsCmp2 //TItem 클래스 비교를 위한 연산자 오버로딩
{
	int m_iValue;
	IsCmp2(int value) : m_iValue(value) {}
	bool operator()(const TItem& item)
	{
		return (item.iValue == m_iValue);
	}
	bool operator()(const TItem* item)
	{
		return (item->iValue == m_iValue);
	}
};

bool compareInt(const int& a, const int& b) //정렬을 위한 int 타입의 비교 조건 정의
{
	return a < b;
}

bool compare(const TItem& a, const TItem& b) //정렬을 위한 TItem 타입의 비교 조건 정의
{
	return a.iValue < b.iValue;
}

bool comparePtr(TItem* a, TItem* b) //정렬을 위한 TItem* 타입의 비교 조건 정의
{
	return a->iValue < b->iValue;
}
int g_iFindValue; 
bool find_TItem(TItem* a)  //TItem 클래스 탐색을 위한 조건 정의
{
	return a->iValue == g_iFindValue;
}

int main(void)
{
	vector<int> listIntA(20, 7);
	vector<int> listInt;

	listInt.resize(20);

	for (int i = 0; i < listInt.size(); i++)
	{
		listInt[i] = i;
	}
	
	vector<int> listIntB(listInt); //listint를 복사하여 listIntB 선언(완전 동일하지 않고 capacity 부분에서 차이가 남)
	vector<int> listIntC(listInt.begin(), listInt.end());//linkInt의 begin부터 end까지 복사하여 listIntC를 선언(차이점은 상동)

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

	for (vector<int>::iterator iter = listInt.begin(); iter!= listInt.end(); iter++)
	{
		cout << " " << *iter;
	}

	cout << endl;

	for (vector<int>::reverse_iterator iter = listInt.rbegin(); iter != listInt.rend(); iter++)
	{
		cout << " " << *iter;
	}

	cout << endl;

	for (auto iter = listInt.begin(); iter != listInt.end(); iter++)
	{
		cout << " " << *iter;
	}
	
	cout << endl;

	for (int i = 0; i < listInt.size(); i++)
	{
		cout << " " << listInt[i];
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
	vector<int>::iterator retiterint;

	if (iterint != listInt.end())
	{
		retiterint = listInt.erase(iterint);
	}

	vector<int> copyvector;
	copy(listInt.begin(), listInt.end(), back_inserter(copyvector));



	//vector<int> listInt;

	//for (int i = 0; i < 20; i++) //int 타입의 vector인 listInt에 0~20의 숫자를 뒤로 삽입
	//{
	//	listInt.push_back(i); 
	//}
	//for (int i = 0; i < 5; i++) //listInt에 10~14의 숫자를 앞으로 삽입
	//{
	//	listInt.insert(listInt.begin(), 10 + i);
	//}
	//for (int i = 0; i < 5; i++) //listInt에 20~24의 숫자를 뒤로 삽입
	//{
	//	listInt.insert(listInt.end(), 20 + i);
	//}
	//int iValue1 = listInt.front();
	//int iValue2 = listInt.back();
	//listInt.pop_back(); //listInt의 맨 뒤의 마지막 원소를 제거

	//for (vector<int>::iterator iter = listInt.begin(); iter != listInt.end(); iter++) 
	//{
	//	cout << " " << *iter;
	//}
	//cout << endl;
	//for (int value : listInt)
	//{
	//	value = 100;
	//	cout << " " << value;
	//}
	//cout << endl;

	//sort(listInt.begin(), listInt.end(), compareInt);
	//vector<int>::iterator iterint = std::find(listInt.begin(), listInt.end(), 17);
	//if (iterint != listInt.end())
	//{
	//	listInt.erase(iterint);
	//}
	//listInt.clear();

	//vector<TItem> listItem;
	//
	//for (int i = 0; i < 20; i++)
	//{
	//	TItem item(i);
	//	listItem.push_back(item);
	//}

	//for (int i = 0; i < 5; i++)
	//{
	//	TItem item(10 + i);
	//	listItem.insert(listItem.begin(), item);
	//}

	//for (int i = 0; i < 5; i++)
	//{
	//	TItem item(20 + i);
	//	listItem.insert(listItem.end(), item);
	//}

	//sort(listItem.begin(), listItem.end(), compare);
	//vector<TItem>::iterator iterItem = find_if(listItem.begin(), listItem.end(), IsCmp2(17));
}
#include "TryCatch.h"

void TryCatch::level1(void)
{
	try
	{
		TryCatch::level2();
		cout << "level1 - �Ϸ�" << endl;
	}
	catch (int exception)
	{
		cout << "level1 - ���ܹ߻�" << endl;
		throw;
	}
}

void TryCatch::level2(void)
{
	cout << "level2 - ���ܹ߻�" << endl;
	throw 0;
	cout << "level2 - �Ϸ�" << endl;
}

int main(void)
{
	TryCatch tc;
	try
	{
		tc.level1();
		cout << "main - �Ϸ�" << endl;
	}
	catch (int exception)
	{
		cout << "main - ���ܹ߻�" << endl;
	}

	return 0;
}

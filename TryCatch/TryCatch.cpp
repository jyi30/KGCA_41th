#include "TryCatch.h"

void TryCatch::level1(void)
{
	try
	{
		TryCatch::level2();
		cout << "level1 - 완료" << endl;
	}
	catch (int exception)
	{
		cout << "level1 - 예외발생" << endl;
		throw;
	}
}

void TryCatch::level2(void)
{
	cout << "level2 - 예외발생" << endl;
	throw 0;
	cout << "level2 - 완료" << endl;
}

int main(void)
{
	TryCatch tc;
	try
	{
		tc.level1();
		cout << "main - 완료" << endl;
	}
	catch (int exception)
	{
		cout << "main - 예외발생" << endl;
	}

	return 0;
}

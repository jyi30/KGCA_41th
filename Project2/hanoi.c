#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//n���� ������ ��������� �������� ��������

int count = 0;

void move(n, start, to)
{
	//printf("[%d]��° ���� : %c ���� %c �� �̵�\n", n, start, to);
	count++;
}

void hanoi(n, start, temp, to)
{
	//1. n-1���� ������ �������������� �������� �ű��. �̶� �������� ��ģ��
	//2. ������ �ϳ� ���� ������ �ٷ� ���������� �������� �ٷ� �ű��.
	//3. n-1���� ������ ���������� �������� �ű��. �̶� ������� ��ģ��.
	//�Լ� ���� hanoi(�Űܾ� �ϴ� ���� ����, �����, ������, ������) - �������� ������� ���� ����
	if (n == 1)
	{
		move(n, start, to);
	}
	else
	{
		hanoi(n - 1, start, to, temp);
		move(n, start, to);
		hanoi(n - 1, temp, to, start);
	}
}

int main(void)
{
	int top = 0;

	printf("ž�� ������ �? : ");
	scanf("%d", &top);

	hanoi(top, 1, 2, 3);

	printf("\n�� %d�� �̵��߽��ϴ�.\n", count);

	return 0;
 }

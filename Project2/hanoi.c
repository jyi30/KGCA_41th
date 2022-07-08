#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//n개의 원반을 출발지에서 목적지로 가져가라

int count = 0;

void move(n, start, to)
{
	//printf("[%d]번째 원반 : %c 에서 %c 로 이동\n", n, start, to);
	count++;
}

void hanoi(n, start, temp, to)
{
	//1. n-1개의 원반을 시작지에서에서 경유지로 옮긴다. 이때 목적지를 거친다
	//2. 마지막 하나 남은 원반은 바로 시작지에서 목적지로 바로 옮긴다.
	//3. n-1개의 원반을 경유지에서 목적지로 옮긴다. 이때 출발지를 거친다.
	//함수 형태 hanoi(옮겨야 하는 원반 갯수, 출발지, 경유지, 도착지) - 경유지가 없을경우 생략 가능
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

	printf("탑의 갯수는 몇개? : ");
	scanf("%d", &top);

	hanoi(top, 1, 2, 3);

	printf("\n총 %d번 이동했습니다.\n", count);

	return 0;
 }

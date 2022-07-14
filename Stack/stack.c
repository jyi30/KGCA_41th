#include <Stdio.h>
#include <stdlib.h>
#include <memory.h>

int top;
int* array;


void init()
{
	top = -1;
}

void create(int count)
{
	array = (int*)calloc(count, sizeof(int));

	system("cls");
	printf("스택 생성 완료\n\n");
}

void deleteArray()
{
	free(array);
}

void deleteAll()
{
	top = -1;
}

int isEmpty()
{
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(int count)
{
	if (top == count - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int num, int count)
{
		system("cls");
		array[++top] = num;
		printf("삽입 완료\n\n");
	
}

void pop()
{
	if (isEmpty())
	{
		system("cls");
		printf("스택이 비었습니다.\n\n");
	}
	else
	{
		system("cls");
		top--;
		printf("삭제 완료\n\n");
	}
}

void print(int count)
{
	system("cls");
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n\n");
}

int main(void)
{
	int num = 0;
	int count = 0;
	int select = 0;

	init();

	while (1)
	{
		printf("======================================\n");
		printf("               스택          \n");
		printf("======================================\n");
		printf("1. 스택 생성  2. 삽입  3. 삭제  4. 출력  5. 전체 삭제  6. 종료\n\n");
		printf("입력 : ");

		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
		{
			printf("몇 칸의 스택 생성? :");
			scanf_s("%d", &count);
			create(count);
			
			continue;
		}
		case 2:
		{
			if (isFull(count))
			{
				system("cls");
				printf("\n스택이 가득 찼습니다.\n\n");

				continue;
			}

			printf("어떤 숫자 삽입? :");
			scanf_s("%d", &num);
			push(num, count);

			continue;
		}
		case 3:
		{
			pop();

			continue;
		}
		case 4:
		{
			print(count);
			continue;
		}
		case 5:
		{
			system("cls");
			deleteAll();

			printf("스택 비워짐\n\n");
			continue;
		}
		case 6:
		{
			break;
		}
		default:
		{
			printf("잘못된 입력입니다.\n\n");
			continue;
		}
		}
		
		break;
	}

	deleteArray();

	return 0;
}





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
	printf("���� ���� �Ϸ�\n\n");
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
		printf("���� �Ϸ�\n\n");
	
}

void pop()
{
	if (isEmpty())
	{
		system("cls");
		printf("������ ������ϴ�.\n\n");
	}
	else
	{
		system("cls");
		top--;
		printf("���� �Ϸ�\n\n");
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
		printf("               ����          \n");
		printf("======================================\n");
		printf("1. ���� ����  2. ����  3. ����  4. ���  5. ��ü ����  6. ����\n\n");
		printf("�Է� : ");

		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
		{
			printf("�� ĭ�� ���� ����? :");
			scanf_s("%d", &count);
			create(count);
			
			continue;
		}
		case 2:
		{
			if (isFull(count))
			{
				system("cls");
				printf("\n������ ���� á���ϴ�.\n\n");

				continue;
			}

			printf("� ���� ����? :");
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

			printf("���� �����\n\n");
			continue;
		}
		case 6:
		{
			break;
		}
		default:
		{
			printf("�߸��� �Է��Դϴ�.\n\n");
			continue;
		}
		}
		
		break;
	}

	deleteArray();

	return 0;
}





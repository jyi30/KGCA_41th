#include <stdio.h>
#include <stdlib.h>

//�ȵǴ� �ٽ� ©��

int front = -1;
int rear = -1;
int* queue;

void create(int count);
int isEmpty(void);
int isFull(int count);
void addq(int value, int count);
int deleteq(int count);



void create(int num)
{
	int count = num + 1;
	queue = (int*)calloc(count, sizeof(int));
}

int isEmpty(void) {
	if (front == rear)//front�� rear�� ������ ť�� ����ִ� ���� 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull(int count) {
    int tmp = (rear + 1) % count;//���� ť���� rear+1�� MAX�� ���� ����������

	if (tmp == front)//front�� ������ ť�� ������ �ִ� ���� 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void addq(int value, int count) {
	if (isFull(count))
	{
		printf("Queue is Full.\n");
	}    
    else 
	{
        rear = (rear + 1) %	count;
        queue[rear] = value;
    }

}
int deleteq(int count) {
	if (isEmpty())
	{
		printf("Queue is Empty.\n");
	}
    else 
	{
        front = (front + 1) % count;
        return queue[front];
    }
}

int main(void) 
{

	int num = 0;
	int count = 0;
	int select = 0;

	while (1)
	{
		printf("======================================\n");
		printf("               ť          \n");
		printf("======================================\n");
		printf("1. ť ����  2. ����  3. ����  4. ���  5. ��ü ����  6. ����\n\n");
		printf("�Է� : ");

		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
		{
			printf("�� ĭ�� ť ����? :");
			scanf_s("%d", &count);
			create(count);

			continue;
		}
		case 2:
		{
			if (isFull(count))
			{
				system("cls");
				printf("\nť�� ���� á���ϴ�.\n\n");

				continue;
			}

			printf("� ���� ����? :");
			scanf_s("%d", &num);
			addq(num, count);

			continue;
		}
		case 3:
		{
			deleteq(count);
			printf("%d\n", deleteq(count));

			continue;
		}
		/*case 4:
		{
			print(count);
			continue;
		}*/
		/*case 5:
		{
			system("cls");
			deleteAll();

			printf("ť �����\n\n");
			continue;
		}*/
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
   /* addq(4);
    addq(7);
    addq(12);
    printf("%d\n", deleteq());
    printf("%d\n", deleteq());
    printf("%d\n", deleteq());
    deleteq();

    return 0;*/
}
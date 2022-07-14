#include <stdio.h>
#include <stdlib.h>

//안되니 다시 짤것

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
	if (front == rear)//front와 rear가 같으면 큐는 비어있는 상태 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull(int count) {
    int tmp = (rear + 1) % count;//원형 큐에서 rear+1을 MAX로 나눈 나머지값이

	if (tmp == front)//front와 같으면 큐는 가득차 있는 상태 
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
		printf("               큐          \n");
		printf("======================================\n");
		printf("1. 큐 생성  2. 삽입  3. 삭제  4. 출력  5. 전체 삭제  6. 종료\n\n");
		printf("입력 : ");

		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
		{
			printf("몇 칸의 큐 생성? :");
			scanf_s("%d", &count);
			create(count);

			continue;
		}
		case 2:
		{
			if (isFull(count))
			{
				system("cls");
				printf("\n큐가 가득 찼습니다.\n\n");

				continue;
			}

			printf("어떤 숫자 삽입? :");
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

			printf("큐 비워짐\n\n");
			continue;
		}*/
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
   /* addq(4);
    addq(7);
    addq(12);
    printf("%d\n", deleteq());
    printf("%d\n", deleteq());
    printf("%d\n", deleteq());
    deleteq();

    return 0;*/
}
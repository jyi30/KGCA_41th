#include <stdio.h>
#include <stdlib.h>

void create(int** arr, int size)
{
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = count;
			count++;
		}
	}
}

void swap(int** arr, int size)
{

}

void pOut(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int size = 0;
	
	while (1)
	{
		printf("마방진의 크기를 입력해주세요.(3~19) : ");
		scanf_s("%d", &size);
		if (size >= 3 && size <= 20)
		{
			break;
		}
	}

	int** arr = (int**)malloc(size);

	for (int i = 0; i <= size; i++)
	{
		arr[i] = (int*)calloc(size, sizeof(int));
	}

	if (size % 2 == 1)
	{
		int count = 1;
		int sRow = 0, sColumn = size / 2;

		arr[sRow][sColumn] = count;
		count++;

		for (int i = 0; i < (size * size); i++)
		{
			if (sRow - 1 < 0 && sColumn + 1 >= size)
			{
				sRow++;
			}
			else if (sRow - 1 < 0)
			{
				sRow = size - 1;
				sColumn++;
			}
			else if (sColumn + 1 >= size)
			{
				sColumn = 0;
				sRow--;
			}
			else if (arr[sRow - 1][sColumn + 1] != 0)
			{
				sRow++;
			}
			else
			{
				sRow--;
				sColumn++;
			}

			arr[sRow][sColumn] = count;
			count++;

		}
		pOut(arr, size);
	}
	else
	{

	}

	/*for (int i = size - 1; i >= 0; i--)
	{
		free(arr[i]);
	}
	free(arr);*/

	return 0;
}


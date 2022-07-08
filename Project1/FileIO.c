#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIMIT 4096;

int main(void)
{
	FILE* fp;
	FILE* fp2;
	int end = 0, fSize;
	char source[40] = { 0 }, target[40] = { 0 };
	char* ch;

	//printf("%d", _msize(source));

	printf("복사할 파일명 입력 : ");
	fgets(source, sizeof(source), stdin);
	source[strlen(source) - 1] = '\0';

	printf("어느 파일에 복사? : ");
	fgets(target, sizeof(source), stdin);
	target[strlen(target) - 1] = '\0';


	

	if (source[39] != '\0' || target[39] != '\0')
	{
		printf("\n파일명이 너무 깁니다!");
		source[0] = '\n';
		target[0] = '\n';

		return 0;
	}

	fopen_s(&fp, source, "r");
	fopen_s(&fp2, target, "w");

	
	if (fp == 0 || fp2 == 0)
	{
		printf("\n파일 일부에 문제가 생겼습니다!\n");
		
		return 0;
	}
	else if(fp != 0 && fp2 != 0)
	{
		printf("\n파일 열기 성공!\n");
	}

	fseek(fp, 0, SEEK_END);
	fSize = ftell(fp) + 1;

	ch = (char *)malloc(fSize);
	memset(ch, 0, fSize);

	fseek(fp, 0, SEEK_SET);

	while(1)
	{ 
		char* pStr = fgets(ch, fSize, fp);

		if (pStr == NULL)
		{
			break;
		}

		fputs(ch, fp2);
	}
	
	fclose(fp);
	fclose(fp2);
	free(ch);

	return 0;
}
//블럭단위 파일 입출력 실습하기

#include <stdio.h>

int main(void)
{
	FILE* fp;
	int size = 0;
	char fName[300];
	char str[300] = { 0 };
	char nStr[300] = { 0 };

	while (1)
	{
		printf("불러올 파일 명 입력 : ");
		fgets(fName, sizeof(fName), stdin);
		fName[strlen(fName) - 1] = '\0';

		fopen_s(&fp, fName, "rb");

		if (fp == 0)
		{
			printf("존재하지 않거나 열 수 없는 파일입니다.\n\n");
			continue;
		}
		else
		{
			printf("파일 열기 성공!\n\n");
			break;
		}
	}

	fseek(fp, 0, SEEK_END);
	size = ftell(fp) + 1;

	fseek(fp, 0, SEEK_SET);

	fread(str, sizeof(char), size, fp);
	printf("현재 파일의 용량 : %d 바이트\n", size -1);
	printf("현재 파일의 내용 : %s\n\n", str);

	while (1)
	{
		printf("현재 파일에 추가할 문자열 입력(0:끝내기) : ");
		nStr[0] = '\0';

		fgets(nStr, sizeof(nStr), stdin);
		nStr[strlen(nStr) - 1] = '\0';
		
		if (nStr[0] == '0')
		{
			break;
		}

		fwrite(nStr, sizeof(char), strlen(nStr) + 1, fp);
	}

	fclose(fp);
	return 0;

}
//������ ���� ����� �ǽ��ϱ�

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
		printf("�ҷ��� ���� �� �Է� : ");
		fgets(fName, sizeof(fName), stdin);
		fName[strlen(fName) - 1] = '\0';

		fopen_s(&fp, fName, "rb");

		if (fp == 0)
		{
			printf("�������� �ʰų� �� �� ���� �����Դϴ�.\n\n");
			continue;
		}
		else
		{
			printf("���� ���� ����!\n\n");
			break;
		}
	}

	fseek(fp, 0, SEEK_END);
	size = ftell(fp) + 1;

	fseek(fp, 0, SEEK_SET);

	fread(str, sizeof(char), size, fp);
	printf("���� ������ �뷮 : %d ����Ʈ\n", size -1);
	printf("���� ������ ���� : %s\n\n", str);

	while (1)
	{
		printf("���� ���Ͽ� �߰��� ���ڿ� �Է�(0:������) : ");
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
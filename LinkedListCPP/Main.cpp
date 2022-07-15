#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StdManagement.h"

int main(void) {

	StdManagement manage;

	if (!manage.init())
	{
		return 0;
	}

	int select = 0;

	while (1)
	{
		printf("======================================\n");
		printf("            �л� ���� ��Ϻ�           \n");
		printf("======================================\n");
		printf("1. ������ ����  2. ���  3. Ž��  4. �߰�  5. ����\n6. ��ü ����  7. ����  8. �ҷ�����  9. ����  0. ����\n\n");
		printf("�Է� : ");

		scanf_s("%d", &select);

		switch (select)
		{
		case 1: //������ ����
		{
			if (!manage.isFull(&manage))
			{
				printf("\n��ҵǾ����ϴ�.\n\n");
				continue;
			}

			int count = 0;
			printf("������ ���� Ƚ�� �Է� : ");
			scanf_s("%d", &count);
			system("cls");
			manage.create(count);

			continue;
		}
		case 2: //��ü ���
		{
			system("cls");
			manage.allPrint();

			continue;
		}
		case 3: //Ž�� �� ��� ���(���� ���� : �������� ����) -> Ž�� ����� ��尡 �ƴ� ��� Ÿ�� �迭(������)�� ��ȯ�ϸ� ������ ��
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				system("cls");
				printf("�����Ͱ� ������ϴ�!!\n\n");

				continue;
			}

			char name[30];
			printf("�̸��� �Է����ּ��� : ");
			scanf_s("%s", name, sizeof(name));
			system("cls");

			Student* result = manage.search(name);

			if (result != NULL)
			{
				manage.print(result);
			}

			continue;
		}
		case 4: //�߰�
		{
			int select = 0;

			printf("\n1. ���� �տ� ����\n2. ���� �ڿ� ����\n3. Ư�� ��� ���Ŀ� ����\n\n");
			printf("���� : ");
			scanf_s("%d", &select);


			if (select == 1)
			{
				manage.frontInsert(manage.newNode());
			}
			else if (select == 2)
			{
				manage.backInsert(manage.newNode());
			}
			else
			{
				if (manage.getHead()->m_pNext == manage.getTail())
				{
					system("cls");
					printf("�����Ͱ� ������ϴ�!!\n\n");

					continue;
				}

				system("cls");
				manage.allPrint();

				char name[30];
				int location = 0;
				printf("������ ���ϴ� ��ġ�� �л� �̸��� �Է����ּ��� : ");
				scanf_s("%s", name, sizeof(name));

				Student* result = manage.search(name);

				if (result == NULL)
				{
					system("cls");
					printf("\n �������� �ʴ� �л��Դϴ�.");

					continue;
				}

				while (1)
				{
					printf("\n���� ��ġ ����(1. ����, 2. ����) : ");
					scanf_s("%d", &location);

					if (location < 1 || location > 2)
					{
						printf("�߸��� �Է��Դϴ�.");

						continue;
					}
					break;
				}

				manage.insert(manage.newNode(), result, location);
			}

			system("cls");
			manage.allPrint();
			printf("\n\n���� �Ϸ�!\n\n");

			continue;
		}
		case 5: //����
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				system("cls");
				printf("�����Ͱ� ������ϴ�!!\n\n");

				continue;
			}

			char name[30];
			printf("�̸��� �Է����ּ��� : ");
			scanf_s("%s", name, sizeof(name));
			delete(manage.search(name));

			system("cls");
			printf("\n\n���� �Ϸ�!\n\n");

			continue;
		}
		case 6: //��ü ����
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				system("cls");
				printf("�����Ͱ� ������ϴ�!!\n\n");

				continue;
			}

			manage.deleteAll();

			system("cls");
			printf("���� �Ϸ�\n\n");

			continue;
		}
		case 7: //����
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				printf("������ �����Ͱ� �����ϴ�!!\n\n");
				continue;
			}

			manage.saveFile();
			continue;
		}
		case 8: //�ҷ�����
		{
			if (manage.isFull(&manage))
			{
				manage.loadFile();
				manage.allPrint();
				continue;
			}
			else
			{
				printf("\n��ҵǾ����ϴ�.\n\n");
				continue;
			}
		}
		case 9: //����
		{
			manage.sort();
			continue;
		}
		case 0: //����
		{
			printf("\n���α׷��� �����մϴ�.\n\n");

			break;
		}
		default: //���� �޴� ����
		{
			system("cls");
			printf("\n�߸��� �Է��Դϴ�.\n\n");

			continue;
		}
		}
		break;
	}

	manage.deleteAll();
	
	return 0;
}

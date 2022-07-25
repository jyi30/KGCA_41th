#include "DataManager.h"

int main(void)
{
	DataManager dMgr;

	int select = 0;

	while (1)
	{
		cout << "======================================\n";
		cout << "            �л� ���� ��Ϻ�           \n";
		cout << "======================================\n";
		cout << "1. ������ ����  2. ���  3. Ž��  4. �߰�  5. ����\n6. ��ü ����  7. ����  8. �ҷ�����  9. ����  0. ����\n\n";
		cout << "�Է� : ";

		cin >> select;

		switch (select)
		{
		case 1: //������ ����
		{
			if (!dMgr.isFull())
			{
				cout << "\n��ҵǾ����ϴ�.\n\n";
				continue;
			}

			int count = 0;
			cout << "������ ���� Ƚ�� �Է� : ";
			cin >> count;
			system("cls");

			dMgr.randomCreate(count);

			continue;
		}
		case 2: //��ü ���
		{
			system("cls");
			if (dMgr.isEmpty())
			{
				continue;
			}
			else
			{
				dMgr.print();
			}
			continue;
		}
		case 3: //Ž�� �� ��� ���(���� ���� : �������� ����) -> Ž�� ����� ��尡 �ƴ� ��� Ÿ�� �迭(������)�� ��ȯ�ϸ� ������ ��
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			char name[30];
			cout << "�̸��� �Է����ּ��� : ";
			cin >> name;
			system("cls");

			if (name != NULL)
			{
				dMgr.print(name);
			}

			continue;
		}
		case 4: //�߰�
		{
			dMgr.insert();

			continue;
		}
		case 5: //����
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			char name[30];
			cout << "�̸��� �Է����ּ��� : ";
			cin >> name;
			dMgr.deleteNode(name);

			system("cls");
			cout << "\n\n���� �Ϸ�!\n\n";

			continue;
		}
		case 6: //��ü ����
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			//link.deleteNode();

			system("cls");
			cout << "���� �Ϸ�\n\n";

			continue;
		}
		case 7: //����
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			//link.saveFile();
			continue;
		}
		case 8: //�ҷ�����
		{
			if (link.isFull(&link))
			{
				link.loadFile();
				link.allPrint();
				continue;
			}
			else
			{
				cout << "\n��ҵǾ����ϴ�.\n\n";
				continue;
			}
		}
		case 9: //����
		{
			link.sort();
			continue;
		}
		case 0: //����
		{
			cout << "\n���α׷��� �����մϴ�.\n\n";

			break;
		}
		default: //���� �޴� ����
		{
			system("cls");
			cout << "\n�߸��� �Է��Դϴ�.\n\n";

			continue;
		}
		}
		break;
	}
}
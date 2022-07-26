#include "DataManager.h"

int main(void)
{
	DataManager dMgr;

	dMgr.init();

	int select = 0;

	while (1)
	{
		cout << "======================================\n";
		cout << "            �л� ���� ��Ϻ�           \n";
		cout << "======================================\n";
		cout << "1. ������ ����  2. ���  3. Ž��  4. �߰�  5. ����\n6. ��ü ����  7. ���ϰ���  8. ����  0. ����\n\n";
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

			dMgr.find(name);

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

			char name[30] = { 0, };
			cout << "�̸��� �Է����ּ��� : ";
			cin >> name;

			system("cls");
			dMgr.deleteNode(name);

			continue;
		}
		case 6: //��ü ����
		{
			if (dMgr.isEmpty())
			{
				continue;
			}

			dMgr.deleteNode();

			system("cls");
			cout << "���� �Ϸ�\n\n";

			continue;
		}
		case 7: //���ϰ���
		{
			int num = 0;
			
			cout << "1. �����ϱ�\n2. �ҷ�����\n\n�Է� : ";
			cin >> num;

			dMgr.fileCtr(num);
			continue;
		}
		case 8: //����
		{
			int num = 0;
			cout << "1. ��������\n2. ��������\n\n�Է� : ";
			cin >> num;

			dMgr.sort(num);
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
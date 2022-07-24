#include "LinkedList.h"

int main(void)
{
	TLinkedList<Student> link;
	link.init();
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
			if (!link.isFull(&manage))
			{
				cout << "\n��ҵǾ����ϴ�.\n\n";
				continue;
			}

			int count = 0;
			cout << "������ ���� Ƚ�� �Է� : ";
			cin >> count;
			system("cls");
			link.create(count);

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
				cout << "�����Ͱ� ������ϴ�!!\n\n";

				continue;
			}

			char name[30];
			cout << "�̸��� �Է����ּ��� : ";
			cin >> name;
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

			cout << "\n1. ���� �տ� ����\n2. ���� �ڿ� ����\n3. Ư�� ��� ���Ŀ� ����\n\n";
			cout << "���� : ";
			cin >> select;


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
					cout << "�����Ͱ� ������ϴ�!!\n\n";

					continue;
				}

				system("cls");
				manage.allPrint();

				char name[30];
				int location = 0;
				cout << "������ ���ϴ� ��ġ�� �л� �̸��� �Է����ּ��� : ";
				cin >> name;

				Student* result = manage.search(name);

				if (result == NULL)
				{
					system("cls");
					cout << "\n �������� �ʴ� �л��Դϴ�.";

					continue;
				}

				while (1)
				{
					cout << "\n���� ��ġ ����(1. ����, 2. ����) : ";
					cin >> location;

					if (location < 1 || location > 2)
					{
						cout << "�߸��� �Է��Դϴ�.";

						continue;
					}
					break;
				}

				manage.insert(manage.newNode(), result, location);
			}

			system("cls");
			manage.allPrint();
			cout << "\n\n���� �Ϸ�!\n\n";

			continue;
		}
		case 5: //����
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				system("cls");
				cout << "�����Ͱ� ������ϴ�!!\n\n";

				continue;
			}

			char name[30];
			cout << "�̸��� �Է����ּ��� : ";
			cin >> name;
			delete(manage.search(name));

			system("cls");
			cout << "\n\n���� �Ϸ�!\n\n";

			continue;
		}
		case 6: //��ü ����
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				system("cls");
				cout << "�����Ͱ� ������ϴ�!!\n\n";

				continue;
			}

			manage.deleteAll();

			system("cls");
			cout << "���� �Ϸ�\n\n";

			continue;
		}
		case 7: //����
		{
			if (manage.getHead()->m_pNext == manage.getTail())
			{
				cout << "������ �����Ͱ� �����ϴ�!!\n\n";
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
				cout << "\n��ҵǾ����ϴ�.\n\n";
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
		int count = 0;
		cout << "������ ���� Ƚ�� �Է� : ";
		cin >> count;
		system("cls");
		link.create(count);
	}
	}
}
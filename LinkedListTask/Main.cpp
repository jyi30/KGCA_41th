#include "LinkedList.h"

int main(void)
{
	TLinkedList<Student> link;
	link.init();
	int select = 0;

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
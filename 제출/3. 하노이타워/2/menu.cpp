#include"Move.h"

void main()
{
	Move *movemanager;
	int num;

	while (true)
	{
		system("cls");
		cout << "Ÿ���� ���̸� �Է� �ϼ��� : ";
		cin >> num;
		if (num < 1)
		{
			cout << "1 �̻��� ������ �Է� �ϼ���" << endl;
			system("pause");
			continue;
		}
		movemanager = new Move(num);
		system("pause");
		delete movemanager;
	}
}
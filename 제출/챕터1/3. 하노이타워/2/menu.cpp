#include"Move.h"

void main()
{
	Move *movemanager;
	int num;

	while (true)
	{
		system("cls");
		cout << "타워의 높이를 입력 하세요 : ";
		cin >> num;
		if (num < 1)
		{
			cout << "1 이상의 정수를 입력 하세요" << endl;
			system("pause");
			continue;
		}
		movemanager = new Move(num);
		system("pause");
		delete movemanager;
	}
}
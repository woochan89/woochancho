#include"func.h"

void main()
{
	func<int> F;
	int num1, num2, num3;
	cout << "1. ���� ���� ���� 1 ���� �����ִ� ���ø� �Լ��� ����ÿ�" << endl;
	cout << "�Է� : ";
	cin >> num1;
	F.Quiz1(num1);
	cout << "2. �� ���� �Է� �޾� �ּҰ��� ���ϴ� ���ø� �Լ��� ����ÿ�" << endl;
	cout << "�Է� : ";
	cin >> num1>>num2;
	F.Quiz2(num1,num2);
	cout << "3. �� ���� �Է� �޾� �ִ밪�� ���ϴ� ���ø� �Լ��� ����ÿ�" << endl;
	cout << "�Է� : ";
	cin >> num1>>num2>>num3;
	F.Quiz3(num1,num2,num3);
}
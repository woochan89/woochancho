#include"func.h"

void main()
{
	func<int> F;
	int num1, num2, num3;
	cout << "1. 전달 받은 값을 1 증가 시켜주는 템플릿 함수를 만드시오" << endl;
	cout << "입력 : ";
	cin >> num1;
	F.Quiz1(num1);
	cout << "2. 두 수를 입력 받아 최소값을 구하는 템플릿 함수를 만드시오" << endl;
	cout << "입력 : ";
	cin >> num1>>num2;
	F.Quiz2(num1,num2);
	cout << "3. 세 수를 입력 받아 최대값을 구하는 템플릿 함수를 만드시오" << endl;
	cout << "입력 : ";
	cin >> num1>>num2>>num3;
	F.Quiz3(num1,num2,num3);
}
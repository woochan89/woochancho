#include"NameCard.h"

void main()
{
	char Name[30];
	char Number[30];

	for (int i = 0; i < 3; i++)
	{
		cout << "이름을 입력해주세요 : ";
		cin >> Name;
		cout << "휴대폰 번호를 입력해주세요 : ";
		cin >> Number;
		*MakeNameCard(Name, Number);
	}
}
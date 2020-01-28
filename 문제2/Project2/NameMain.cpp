#include"NameCard.h"

void main()
{
	char Name[30];
	char Number[30];
	int People;

	NameCard **Card;
	int sel;
	bool flag;
	
	cout << "몇명의 카드 정보를 입력하시겠습니까?" << endl;
	cin >> People;
	Card = new NameCard*[People];
	for (int i = 0; i < People; i++)
	{
		system("cls");
		cout <<i+1 <<"번째 카드의 이름을 입력해주세요 : ";
		cin >> Name;
		cout <<i+1<< "번째 카드의 휴대폰 번호를 입력해주세요 : ";
		cin >> Number;
		Card[i] = MakeNameCard(Name, Number);
	}
	
	while (true)
	{
		system("cls");
		cout << "1. 정보 출력" << endl;
		cout << "2. 번호 변경 " << endl;
		cout << "3. 정보 삭제" << endl;
		cout << "4.종료" << endl;
		cout << "입력 : " << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			for (int i = 0; i < People; i++)
			{
				if (Card[i] == NULL)
					continue;
				ShowNameCardInfo(Card[i]);
			}
			system("pause");
			break;

		case 2:
			flag = false;
			cout << "번호를 변경할 이름을 입력해주십시오" << endl;
			cin >> Name;
			for (int i = 0; i < People; i++)
			{
				if (NameCompare(Card[i], Name))
				{
					cout << "변경할 번호를 입력하세요" << endl;
					cin >> Number;
					ChangePhoneNum(Card[i], Number);
					flag = true;
				}
			}
			if(flag==false)
			{
				cout << "해당 이름의 카드가 존재하지 않습니다" << endl;
				system("pause");
			}
			break;

		case 3:
			flag = false;
			cout << "삭제 할 카드의 이름을 입력해주십시오" << endl;
			cin >> Name;
			for (int i = 0; i < People; i++)
			{
				if (NameCompare(Card[i], Name))
				{
					DeleteData(Card[i]);
					Card[i] = NULL;
					flag = true;
					cout << Name << "의 카드를 삭제했습니다" << endl;
					system("pause");
				}
			}
			if(flag==false)
			{
				cout << "해당 이름의 카드가 존재하지 않습니다" << endl;
				system("pause");
			}
			break;

		case 4:
			return;
		}
	}
}
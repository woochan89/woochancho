#include<iostream>
#include<string>
using namespace std;

int i = 1;
struct word
{
	int Num1;//입력받은 숫자
	int Num2;//번째 숫자
	word *next = NULL;
};

void Input(word *test)
{
	word *add;
	word *tmp = test;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	system("cls");
	if (i == 1)
	{
		cout << i << "번째 숫자" << endl;
		cout << "숫자 입력 : ";
		cin >> tmp->Num1;
		tmp->Num2 = i++;
	}
	else
	{
		add = new word;
		cout << i << "번째 숫자" << endl;
		cout << "숫자 입력 : ";
		cin >> add->Num1;
		add->Num2 = i++;
		tmp->next = add;
	}
}

void Show(word *test)
{
	system("cls");
	word *tmp = test;
	if (!(tmp->Num2 > 0 && tmp->Num2 < 100))
	{
		cout << "입력된 숫자가 없습니다";
		system("pause");
		return;
	}
	while (1)
	{
		cout << tmp->Num2 << "번째 숫자는 " << tmp->Num1 << endl;
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	system("pause");
}

int Erase(word *test)
{
	word *tmp = test;
	word *tmp2;//넥스트 데이터 임시 저장
	word *tmp3;
	int select;
	int tmpNum;
	system("cls");
	cout << "몇번째 데이터를 지우시겠습니까?" << endl;
	cin >> select;
	if (select == 1)
		return 1;
	if (select > i || select < 0)
		return 0;
	while (1)
	{
		if (select == tmp->Num2)
		{
			tmpNum = tmp->Num2;
			tmp2 = tmp->next;
			delete tmp;
			tmp = test;
			while (1)
			{
				if (tmp->next != NULL)//next가 NULL이 아닐때
				{
					tmp3 = tmp->next;
					if (tmp3->Num2 > 0 && tmp3->Num2 < 100)//next Num2가 0초과 100미만이면 정상늘림
					{
						tmp = tmp->next;
						continue;
					}
					else//쓰레기값이면 break
						break;
				}
				tmp = tmp->next;
			}
			tmp->next = tmp2;
			if (tmp->next != NULL)//next가 NULL이 아닐때만 실행
			{
				while (1)//번째 숫자 하나씩 줄이기
				{
					tmp = tmp->next;
					tmp->Num2--;
					if (tmp->next == NULL)
						break;
				}
			}
			cout << tmpNum << "번째 삭제완료!";
			i--;
			system("pause");
			return 0;
		}
		tmp = tmp->next;
	}
}

void main()
{
	int select;
	word *test;
	word *tmp3;
	test = new word;
	while (1)
	{
		system("cls");
		cout << "1. 입력" << endl;
		cout << "2. 표시" << endl;
		cout << "3. 삭제" << endl;
		cout << "4. 종료" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			Input(test);
			break;
		case 2:
			Show(test);
			break;
		case 3:
			if (Erase(test))
			{
				tmp3 = test;
				test = test->next;
				delete tmp3;
				i--;
			}
			break;
		case 4:
			return;
		}
	}
}
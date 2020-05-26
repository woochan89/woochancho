#include "Gamemanager.h"



Gamemanager::Gamemanager()
{
}

void Gamemanager::drawitem(Item* shop,Item* player)
{
	int buyflag=0;
	Item* tmp;
	int sel;
	int item_max;
	item_max= shop->View();
	sel=controlcursor(item_max);
	tmp= shop->finditem(sel);
	tmp->View();
	while (buyflag!=0)
	{
		cout << "를 구매 하시겠습니까?(YES : 1   NO : 2)" << endl;
		cin >> buyflag;
	}
	player->AddItem(tmp);
	shop->RemoveItem(tmp);
}

int Gamemanager::controlcursor(int item_max)
{
	int y = 4;
	int item_num = 1;
	char ch;
	gotoxy(2, y + item_num*2);
	cout << "▷";
	while (true)
	{
		ch = getch();
		gotoxy(2, y + item_num * 2);
		cout << "  ";
		switch (ch)
		{
		case 'w':
			item_num--;
			break;
		case 's':
			item_num++;
			break;
		case 13:
			return y;
		}
		gotoxy(2, y + item_num * 2);
		cout << "▷";
	}
}


Gamemanager::~Gamemanager()
{
}

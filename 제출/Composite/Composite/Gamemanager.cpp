#include "Gamemanager.h"



Gamemanager::Gamemanager()
{
}

void Gamemanager::ShopInterface(Item* shop,Item* player)
{
	int buyflag=0;
	Item* tmp;
	int sel;
	int item_max;

	system("cls");
	gotoxy(3, 4);
	item_max= shop->View();
	sel=controlcursor(item_max);
	tmp= shop->finditem(sel);
	tmp->View();
	while (1)
	{
		cout << "를 구매 하시겠습니까?(YES : 1   NO : 2)" << endl;
		cin >> buyflag;
		switch (buyflag)
		{
		case 1:
			player->AddItem(tmp);
			shop->RemoveItem(tmp);
			break;
		case 2:
			break;
		case 3:
			continue;
		}
		return;
	}
}

void Gamemanager::ShowPlayerInventory(Item* player)
{
	player->View();
	system("pause");
}


int Gamemanager::controlcursor(int item_max)
{
	int y = 3;
	int item_num = 1;
	char ch;
	gotoxy(0, y + item_num);
	cout << "▷";
	while (true)
	{
		ch = getch();
		gotoxy(0, y + item_num);
		cout << "  ";
		switch (ch)
		{
		case 'w':
			if(item_num>1)
				item_num--;
			break;
		case 's':
			if (item_num < item_max)
				item_num++;
			break;
		case 13:
			return y;
		}
		gotoxy(0, y + item_num);
		cout << "▷";
	}
}


Gamemanager::~Gamemanager()
{
}

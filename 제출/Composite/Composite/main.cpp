#include"Item.h"
#include"Bag.h"
#include"Weapon.h"
#include"Gamemanager.h"


int main()
{
	Gamemanager Game;
	int select;
	Item* shopbag = new Bag("상점주인 가방");
	Item* playerbag = new Bag("플레이어 가방");

	Item* item1 = new Weapon("단검", 2, 0);
	Item* item2 = new Weapon("롱소드", 4, 0);
	Item* item3 = new Weapon("대검", 8, 0);

	shopbag->AddItem(item1);
	shopbag->AddItem(item2);
	shopbag->AddItem(item3);

	while (true)
	{
		system("cls");
		cout << "1. 상점" << endl;
		cout << "2. 플레이어 인벤토리" << endl;
		cout << "3. 종료" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			Game.ShopInterface(shopbag, playerbag);
			break;
		case 2:
			Game.ShowPlayerInventory(playerbag);
			break;
		case 3:

			return 0;
		}
	}



	cout << setw(30) << setfill('=')<<'='<<endl;


	return 1;
}
#include"Item.h"
#include"Bag.h"
#include"Weapon.h"
#include"Gamemanager.h"


int main()
{
	Gamemanager Game;
	int select;
	Item* shopbag = new Bag("�������� ����");
	Item* playerbag = new Bag("�÷��̾� ����");

	Item* item1 = new Weapon("�ܰ�", 2, 0);
	Item* item2 = new Weapon("�ռҵ�", 4, 0);
	Item* item3 = new Weapon("���", 8, 0);

	shopbag->AddItem(item1);
	shopbag->AddItem(item2);
	shopbag->AddItem(item3);

	while (true)
	{
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. �÷��̾� �κ��丮" << endl;
		cout << "3. ����" << endl;
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
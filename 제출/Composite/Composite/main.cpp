#include"Inventory.h"
#include"Bag.h"
#include"Weapon.h"


int main()
{

	Inventory* shop = new Bag("����",0,0);

	Inventory* item1 = new Weapon("�ܰ�", 2, 0);
	Inventory* item2 = new Weapon("�ռҵ�", 4, 0);
	Inventory* item3 = new Weapon("���", 8, 0);

	shop->AddInventory(item1);


	return 1;
}
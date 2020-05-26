#include"Inventory.h"
#include"Bag.h"
#include"Weapon.h"


int main()
{

	Inventory* shop = new Bag("가방",0,0);

	Inventory* item1 = new Weapon("단검", 2, 0);
	Inventory* item2 = new Weapon("롱소드", 4, 0);
	Inventory* item3 = new Weapon("대검", 8, 0);

	shop->AddInventory(item1);


	return 1;
}
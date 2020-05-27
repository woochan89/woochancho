#pragma once
#include"Armor.h"
#include"Bag.h"
#include"Weapon.h"
#include"Ring.h"
#include"Mecro.h"

class Gamemanager
{
public:
	void ShopInterface(Item* shop, Item* player);
	void ShowPlayerInventory(Item* player);
	int controlcursor(int item_max);
	Gamemanager();
	~Gamemanager();
};


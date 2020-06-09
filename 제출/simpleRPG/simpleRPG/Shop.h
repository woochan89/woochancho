#pragma once
#include"Mecro.h"
#include"Item.h"


class Shop
{
private:
public:
	list<Item*> WeaponList;
	list<Item*> ArmorList;
	list<Item*> AccessoryList;

	int GetWeaponMax() { return WeaponList.size(); }
	int GetArmorMax() { return ArmorList.size(); }
	int GetAccessoryMax() { return AccessoryList.size(); }
};


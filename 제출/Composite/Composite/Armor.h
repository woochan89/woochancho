#pragma once
#include"Item.h"
#include"Mecro.h"


class Armor :public Item
{
	int m_iDef;
public:
	int View();
	void AddItem(Item* inventory) {};
	void RemoveItem(Item* inventory) {};
	Item* finditem(int num) { return NULL; };

	Armor(string name,int def);
	~Armor();
};


#pragma once
#include"Item.h"
#include"Mecro.h"

class Weapon :public Item
{
private:
	int m_iATK;
	int m_iInt;

public:
	int View();
	void AddItem(Item* inventory) {};
	void RemoveItem(Item* inventory) {};
	Item* finditem(int num) { return NULL; };

	Weapon(string name, int atk, int Int);
	~Weapon();
};


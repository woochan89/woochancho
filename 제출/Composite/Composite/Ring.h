#pragma once
#include"Item.h"
#include"Mecro.h"

class Ring:public Item
{
	int m_iInt;
public:
	int View();
	void AddItem(Item* item) {};
	void RemoveItem(Item* item) {};
	Item* finditem(int num) { return NULL; };

	Ring(string name,int Int);
	~Ring();
};


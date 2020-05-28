#pragma once
#include"Item.h"
#include"Mecro.h"


class Bag :public Item
{
private:
	list<Item*> ItemList;
public:
	 int View();
	 void AddItem(Item* _item);
	 void RemoveItem(Item* _item);
	 Item* finditem(int num);

	Bag(string name);
	~Bag();
};


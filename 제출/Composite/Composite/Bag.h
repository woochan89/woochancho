#pragma once
#include"Inventory.h"
#include"Mecro.h"


class Bag :public Inventory
{
private:
	vector<Inventory*> inventoryList;
public:
	 void View();
	 void AddInventory(Inventory* inventory);
	 void RemoveInventory(Inventory* inventory);

	Bag(string name,string stat);
	~Bag();
};


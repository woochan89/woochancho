#pragma once
#include"Inventory.h"
#include"Mecro.h"

class Weapon :public Inventory
{
public:
	void View();
	void AddInventory(Inventory* inventory) {};
	void RemoveInventory(Inventory* inventory) {};

	Weapon(string name,string stat);
	~Weapon();
};


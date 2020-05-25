#include "Bag.h"
#include<vector>
#include<iostream>
#include <iomanip>

using namespace std;



Bag::Bag(string name, string stat):Inventory(name, stat)
{
}

void Bag::View()
{
	cout << setiosflags(ios::right) << setw(GetSize());
	cout << setfill(' ') << GetName().c_str() << " - Bag" << endl;

	vector<Inventory*>::iterator begin = inventoryList.begin();
	vector<Inventory*>::iterator end = inventoryList.end();

	while (begin != end)
	{
		(*begin)->View();
		begin++;
	}
}

void Bag::AddInventory(Inventory* inventory)
{
	inventory->SetParent(this);
	inventoryList.push_back(inventory);
}

void Bag::RemoveInventory(Inventory* inventory)
{
	vector<Inventory*>::iterator remove = find(inventoryList.begin(), inventoryList.end(), inventory);

	if (remove != inventoryList.end())
	{
		inventoryList.erase(remove);
	}
}

Bag::~Bag()
{
}

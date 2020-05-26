#pragma once
#include<string>
using namespace std;

typedef struct _item {
	string name;
	int atk;
	int def;
}item;

class Inventory
{
	Inventory *parent;
	item m_sItem;
public:
	virtual void View()=0;
	virtual void AddInventory(Inventory* inventory) = 0;
	virtual void RemoveInventory(Inventory* inventory) = 0;
	void SetParent(Inventory* _parent);
	Inventory* GetParent();
	item GetItem();
	int Getlevel();
	Inventory(string name,int atk, int def);
	~Inventory();
protected:
	int GetSize();
};


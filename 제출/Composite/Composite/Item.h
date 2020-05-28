#pragma once
#include"Mecro.h"
#include<string>
using namespace std;


class Item
{
	Item *parent;
	item_type m_eType;
	const string m_sName;
public:
	virtual int View() = 0;
	virtual void AddItem(Item* _item) = 0;
	virtual void RemoveItem(Item* _item) = 0;
	virtual	Item* finditem(int num) = 0;
	void SetParent(Item* _parent);
	Item* GetParent();
	string GetName();
	int Getlevel();
	Item(string name,item_type type);
	~Item();
protected:
	int GetSize();
};


#include "Inventory.h"



Inventory::Inventory(string name,int atk,int def)
{
	m_sItem.name = name;
	m_sItem.atk = atk;
	m_sItem.def = def;
	parent = NULL;
}

void Inventory::SetParent(Inventory* _parent)
{
	parent = _parent;
}
Inventory* Inventory::GetParent()
{
	return parent;
}
item Inventory::GetItem()
{
	return m_sItem;
}

int Inventory::Getlevel()
{
	
}


Inventory::~Inventory()
{
}

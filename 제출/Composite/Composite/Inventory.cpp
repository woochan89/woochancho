#include "Inventory.h"



Inventory::Inventory(string name,string stat):m_sName(name),m_sStat(stat)
{
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
string Inventory::GetName()
{
	return m_sName;
}

int Inventory::Getlevel()
{
	
}


Inventory::~Inventory()
{
}

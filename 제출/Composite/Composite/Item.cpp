#include "Item.h"



Item::Item(string name) :m_sName(name)
{
	parent = NULL;
}

void Item::SetParent(Item* _parent)
{
	parent = _parent;
}
Item* Item::GetParent()
{
	return parent;
}
string Item::GetName()
{
	return m_sName;
}

int Item::Getlevel()
{
	return 1;
}


Item::~Item()
{
}

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
	int level = 0;

	Item* _item = GetParent();

	while (_item != NULL)
	{
		level++;
		_item = _item->GetParent();
	}

	return level;
}

int Item::GetSize()
{
	return m_sName.size() + Getlevel() * 2;
}


Item::~Item()
{
}

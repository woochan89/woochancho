#include "Item.h"


Weapon::Weapon(string name, int atk, int def, int hp, int mp):Item(name,WEAPON)
{
	m_Atk = atk;
	m_Def = def;
	m_Hp = hp;
	m_Mp = mp;
}

Weapon::~Weapon()
{

}


Armor::Armor(string name, int atk, int def, int hp, int mp):Item(name,ARMOR)
{
	m_Atk = atk;
	m_Def = def;
	m_Hp = hp;
	m_Mp = mp;

}

Armor::~Armor()
{

}


Accessory::Accessory(string name, int atk, int def, int hp, int mp) :Item(name, ACCESSORY)
{
	m_Atk = atk;
	m_Def = def;
	m_Hp = hp;
	m_Mp = mp;

}

Accessory::~Accessory()
{

}


Etc::Etc(string name) :Item(name, ETC)
{

}

Etc::~Etc()
{

}
#include "Item.h"


Weapon::Weapon(string name):Item(name,SWORD)
{

}

Weapon::~Weapon()
{

}


Armor::Armor(string name):Item(name,ARMOR)
{

}

Armor::~Armor()
{

}


Accessory::Accessory(string name) :Item(name, ACCESSORY)
{

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
#pragma once
#include"Mecro.h"
enum ItemType{
	SWORD,
	DAGGER,
	WAND,
	ARMOR,
	RING,
	NECKLACE
};

class Item
{
private:
	const string m_sName;
	const ItemType m_eType;
protected:
	int m_iAtk;
	int m_iDef;
	int m_iHp;
	int m_iMp;
public:
	Item(string name, ItemType type) :m_sName(name),m_eType(type) {}
	~Item() {}
};

class Weapon :public Item
{
public:
	Weapon(string name);
	~Weapon();
};

class Armor :public Item
{

};

class Accessory :public Item
{

};

class ETC :public Item
{

};
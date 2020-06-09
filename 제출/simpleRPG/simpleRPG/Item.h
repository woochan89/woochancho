#pragma once
#include"Mecro.h"
enum ItemType{
	SWORD,
	DAGGER,
	WAND,
	WEAPON,
	ARMOR,
	ACCESSORY,
	ETC
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
	string GetName() { return m_sName; }
	ItemType GetType(){ return m_eType; }
	int GetAtk() { return m_iAtk; }
	int GetDef() { return m_iDef; }
	int GetHp() { return m_iHp; }
	int GetMp() { return m_iMp; }
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
	Armor(string name);
	~Armor();
};

class Accessory :public Item
{
	Accessory(string name);
	~Accessory();
};

class Etc :public Item
{
	Etc(string name);
	~Etc();
};
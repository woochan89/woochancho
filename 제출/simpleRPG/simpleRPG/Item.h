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
	const string m_Name;
	const ItemType m_Type;
protected:
	int m_Atk;
	int m_Def;
	int m_Hp;
	int m_Mp;
public:
	string GetName() { return m_Name; }
	ItemType GetType(){ return m_Type; }
	int GetAtk() { return m_Atk; }
	int GetDef() { return m_Def; }
	int GetHp() { return m_Hp; }
	int GetMp() { return m_Mp; }
	Item(string name, ItemType type) :m_Name(name),m_Type(type) {}
	~Item() {}
};

class Weapon :public Item
{
public:
	Weapon(string name,int atk,int def, int hp, int mp);
	~Weapon();
};

class Armor :public Item
{
public:
	Armor(string name, int atk, int def, int hp, int mp);
	~Armor();
};

class Accessory :public Item
{
public:
	Accessory(string name, int atk, int def, int hp, int mp);
	~Accessory();
};

class Etc :public Item
{
	Etc(string name);
	~Etc();
};
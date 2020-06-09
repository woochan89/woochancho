#pragma once
#include"Player.h"
#include"Monster.h"
#include"Mecro.h"
#include"Draw.h"
#include"Shop.h"

class GameManager
{
	Player* m_Player;
	Monster* m_Monster;
	Shop m_Shop;
public:
	void showMain(Player* player);
	void dungeon(int num);
	void battle(Monster* monster);
	void showStat();
	void showInventory(list<Item*> Target, string name="인벤토리");
	void Shop();
	void wearEquipment(list<Item*> inventory,int target);
	void offEquipment(ItemType type);
	void buySomething(list<Item*>fromlist, list<Item*>tolist, int fromtarget);
	GameManager();
	~GameManager();
};


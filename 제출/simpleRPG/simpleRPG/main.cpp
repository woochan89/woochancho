#include"Monster.h"
#include"Player.h"



ObjectStat* MakeStat(string name, int atk = 0, int def = 0, int hp = 0, int mp = 0)
{
	ObjectStat* tmp = new ObjectStat();
	tmp->Name = name;
	tmp->Atk = atk;
	tmp->Def = def;
	tmp->Hp = hp;
	tmp->Mp = mp;
	return tmp;
}

int main()
{
	string name;
	Player* player1 = new Player(MakeStat("¿ìÂù"));
	Player* player2 = new Player(MakeStat("¾ÆÅÙÃ÷"));
	Player* player3 = new Player(MakeStat("¾ÆÄ«µ¥¹Ì"));

	Monster* Monster1 = new Monster(MakeStat("½ºÄÌ·¹Åæ"));
	Monster* Monster2 = new Monster(MakeStat("µå·¡°ï"));

	Monster1->AddObserver(player1);
	Monster1->AddObserver(player2);
	Monster1->AddObserver(player3);

	Monster2->AddObserver(player1);
	Monster2->AddObserver(player3);

	player1->AlarmControl(false);

	

	return 0;
}
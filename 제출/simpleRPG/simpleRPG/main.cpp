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
	Player* player1 = new Player(MakeStat("����"));
	Player* player2 = new Player(MakeStat("������"));
	Player* player3 = new Player(MakeStat("��ī����"));

	Monster* Monster1 = new Monster(MakeStat("���̷���"));
	Monster* Monster2 = new Monster(MakeStat("�巡��"));

	Monster1->AddObserver(player1);
	Monster1->AddObserver(player2);
	Monster1->AddObserver(player3);

	Monster2->AddObserver(player1);
	Monster2->AddObserver(player3);

	player1->AlarmControl(false);

	

	return 0;
}
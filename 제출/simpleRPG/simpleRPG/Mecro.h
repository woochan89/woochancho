#include<iostream>
#include<string>
#include<vector>
using namespace std;



typedef struct objectstat {
	string Name;
	int Atk;
	int Def;
	int Hp;
	int Mp;
}ObjectStat;


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
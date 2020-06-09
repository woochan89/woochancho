#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<map>
using namespace std;
#define ONE_ENEMY false
#define ALL_ENEMY true


enum Condition {
	NOMAL = 0,
	POSION,
	SLEEP
};
typedef struct _objectstat {
	string Name;
	int Lv;
	int Atk;
	int Def;
	int MaxHp;
	int Hp;
	int MaxMp;
	int Mp;
}ObjectStat;

typedef struct _skill
{
	string Name;
	int GetLevel;
	float Dmg;
	int MpConsumtion;
	int Target;
	Condition condition;
}ObjectSkill;

#pragma once
#include"Mecro.h"
#include"Singleton.h"
#include"Skill.h"
#include"Windows.h"
#define BASELINE 30
#define WIDTH 30
#define HEIGHT 30

class Draw:public Singleton<Draw>
{
private:

public:
	void showStat(ObjectStat* stat);
	void showSkill(vector<Skill*> skill);
	void showEquipment(string name,int atk,int def,int hp,int mp);
	int Cursor(int Max, int x = 0, int y = 0);
	void drawText(string text, int Ypos = BASELINE);
	void drawBattleInterface(ObjectStat* playerStat, ObjectStat* monsterStat);

	void gotoxy(int x, int y)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	Draw();
	~Draw();
};


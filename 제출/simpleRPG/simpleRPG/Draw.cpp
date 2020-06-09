#include "Draw.h"
#include<conio.h>

Draw* Draw::m_hThis = NULL;

Draw::Draw()
{
}

void Draw::showStat(ObjectStat* stat)
{
	cout << " " << stat->Name << "  레벨 : " << stat->Lv << endl;
	cout << " 공격력 : " << stat->Atk/*<<"  주문력 : "<< stat ->*/ << "  방어력 : " << stat->Def << endl;
	cout << " HP : " << stat->Hp << "/" << stat->MaxHp << "  MP" << stat->Mp << "/" << stat->MaxMp << endl;
}

void Draw::showSkill(vector<Skill*> skill)
{
	vector<Skill*>::iterator iter = skill.begin();
	

	while (iter != skill.end()) 
	{
		Skill* tmp = *iter;

		cout << " " << tmp->GetSkill()->Name << "  데미지 : " << tmp->GetSkill()->Dmg;
		cout << " 소모MP : " << tmp->GetSkill()->MpConsumtion << "타겟 : ";
		if (tmp->GetSkill()->Target == ONE_ENEMY)
			cout << "단일" << endl;
		else if (tmp->GetSkill()->Target == ALL_ENEMY)
			cout << "전체" << endl;
		iter++;
	}
}

void Draw::showEquipment(string name, int atk, int def, int hp, int mp)
{
	cout << " " << name;
	if (atk)
		cout << "  공격력 : " << atk;
	if (def)
		cout << "  방어력 : " << def;
	if (hp)
		cout << "  HP : " << hp;
	if (mp)
		cout << "  MP : " << mp;
}

int Draw::Cursor(int Max, int x, int y)
{
	char ch;
	int ypos=1;
	gotoxy(x, y);
	cout << "▷";
	while (true)
	{
		ch = getch();
		switch (ch)
		{
		case 'w':
			if (ypos != 1)
			{
				ypos--;
				gotoxy(x, y + ypos);
				cout << "▷";
			}
			break;
		case 's':
			if (ypos != Max)
			{
				ypos++;
				gotoxy(x, y + ypos);
				cout << "▷";
			}

			break;
		case 13:
			return ypos;
		}
	}
}

void Draw::drawText(string text, int Ypos)
{
	gotoxy(3, Ypos);
	cout << text;
}

void Draw::drawBattleInterface(ObjectStat* playerStat, ObjectStat* monsterStat)
{
	system("cls");
	gotoxy(3, 3);
	showStat(playerStat);
	gotoxy(3, 10);
	showStat(monsterStat);
}


Draw::~Draw()
{
}

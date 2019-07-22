#include "Dungeon.h"



Dungeon::Dungeon()
{
}

void Dungeon::Menu(Character *CharacterList[])
{
	int Select;
	while (true)
	{
		system("cls");
		DrawManager.DrawBox();
		for (int i=-3;i<=3;i++)
		{
			if (i == -3)
				DrawManager.DrawMidText("< 던 전 >", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -2)
				DrawManager.DrawMidText("고블린 소굴(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -1)
				DrawManager.DrawMidText("고블린 소굴(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 0)
				DrawManager.DrawMidText("고블린 소굴(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 1)
				DrawManager.DrawMidText("고블린 소굴(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 2)
				DrawManager.DrawMidText("고블린 소굴(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else
				DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 2 * i);
		}
		Select = DrawManager.DrawCursor(6, WIDTH*0.5 - 7, HEIGHT*0.5 - 4);
		switch (Select)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			Battle(Select,CharacterList);
			break;
		case 6:
			return;
		}
	}
}

void Dungeon::Battle(int Floor, Character *CharacterList[])
{
	int DmgToPlayer[3];
	int DmgToEnemy[3];
	for (int i = 0; i < 3; i++)
	{
		MonsterList[i] = new Monster();
		MonsterList[i]->InputData(Floor,i);
	}
	while (1)
	{
		for (int i = P1; i <= P3; i++)//데미지 확인
		{
			CharacterList[i]->DealToEnemy(DmgToEnemy);
			MonsterList[i]->DealToEnemy(DmgToPlayer);
		}
		for (int i = P1; i <= P3; i++)//데미지 적용
		{
			CharacterList[i]->GetDmg(DmgToPlayer,i);
			MonsterList[i]->GetDmg(DmgToEnemy,i);
		}
		for (int i = P1; i <= P3; i++)//전투상태창 표시
		{
			CharacterList[i]->ShowBattleStat(PLAYER);
			MonsterList[i]->ShowBattleStat(MONSTER);
		}
		if (MonsterList[0]->WinCheck() && MonsterList[0]->WinCheck() && MonsterList[0]->WinCheck())//승리확인
		{
			//레벨업
			//다음층 진행 여부확인
		}
		Sleep(1000);
	}
	for (int i = 0; i < 3; i++)
	{
		delete MonsterList[i];
	}
}

void Dungeon::InputMonsterData()
{

}

Dungeon::~Dungeon()
{
}

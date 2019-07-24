#include "Dungeon.h"



Dungeon::Dungeon()
{
}

bool Dungeon::Menu(Character *CharacterList[],int *Money)
{
	int Select;
	bool AssemblyFlag = false;
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
				DrawManager.DrawMidText("오크 군락(Lv 11~20)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 0)
				DrawManager.DrawMidText("저주받은 묘지(Lv 21~30)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 1)
				DrawManager.DrawMidText("태초의 섬(Lv 31~40)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 2)
				DrawManager.DrawMidText("용의 둥지(Lv 41~50)", WIDTH, HEIGHT*0.5 + 2 * i);
			else
				DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 2 * i);
		}
		Select = DrawManager.DrawCursor(5, WIDTH*0.5 - 7, HEIGHT*0.5 - 4);
		switch (Select)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			Battle(Select,CharacterList,1);
			*Money += 100 * Select;
			AssemblyFlag= true;
			break;
		case 6:
			return AssemblyFlag;
		}
	}
}

void Dungeon::Battle(int Floor, Character *CharacterList[], int Stage)
{

	for (int i = 0; i < 3; i++)
	{
		MonsterList[i] = new Monster();
		MonsterList[i]->InputData(Floor,i+((Stage-1)*3));
	}
	system("cls");
	DrawManager.DrawBox();
	DrawManager.gotoxy(WIDTH - (25*2), HEIGHT*0.5 - 2);
	for (int i = 0; i < 25; i++)//땅그리기
	{
		cout << "▨▧";
	}
	DrawManager.DrawSmallBox(WIDTH*0.5-25,HEIGHT*0.5-10,50,10);

	for (int i = P1; i <= P3; i++)//전투상태창 표시
	{
		CharacterList[i]->ShowBattleStat(PLAYER, i);
		MonsterList[i]->ShowBattleStat(MONSTER, i);
	}
	Sleep(1000);
	while (1)
	{
		int DmgToPlayer[3] = { 0 };
		int DmgToMonster[3] = { 0 };
		for (int i = P1; i <= P3; i++)//데미지 확인
		{
			CharacterList[i]->DealToEnemy(DmgToMonster,MonsterList);
			MonsterList[i]->DealToEnemy(DmgToPlayer,CharacterList);
		}
		for (int i = P1; i <= P3; i++)//데미지 적용
		{
			CharacterList[i]->GetDmg(DmgToPlayer,i);
			MonsterList[i]->GetDmg(DmgToMonster,i);
		}
		for (int i = P1; i <= P3; i++)//전투상태창 표시
		{
			CharacterList[i]->ShowBattleStat(PLAYER,i);
			MonsterList[i]->ShowBattleStat(MONSTER,i);
		}
		if (MonsterList[P1]->WinCheck() && MonsterList[P2]->WinCheck() && MonsterList[P3]->WinCheck())//승리확인
		{
			for (int i = 0; i < 3; i++)//경험치 획득
			{
				CharacterList[i]->GetExp(Floor*3);
			}
			DrawManager.DrawTextWithBox("승 리!",WIDTH,HEIGHT*0.5);
			system("pause");
			if (NextFloorChoice())//다음층 진행 여부확인
				Battle(Floor, CharacterList,++Stage);
			else
				break;
		}
		Sleep(1000);
	}
	for (int i = 0; i < 3; i++)
		delete MonsterList[i];
}

bool Dungeon::NextFloorChoice()
{
	bool Select;
	system("cls");
	DrawManager.DrawBox();
	DrawManager.DrawTextWithBox("계속 진행하시겠습니까?",WIDTH,HEIGHT*0.5-3);
	DrawManager.DrawMidText("예",WIDTH,HEIGHT*0.5-1);
	DrawManager.DrawMidText("아니오",WIDTH,HEIGHT*0.5+1);
	Select = DrawManager.DrawCursor(1,WIDTH*0.5-3,HEIGHT*0.5-1);
	return Select;
}


Dungeon::~Dungeon()
{
}

#include "Dungeon.h"



Dungeon::Dungeon(int *Money,int *Day)
{
	m_iMoney = Money;
	m_iDay = Day;
}

bool Dungeon::Menu(Character *CharacterList[])
{

	int Select;
	bool AssemblyFlag = false;
	while (true)
	{
		system("cls");
		DrawManager.DrawBox();
		ShowStatus(CharacterList);
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
			if (CharacterList[P1]->WinCheck() && CharacterList[P2]->WinCheck() && CharacterList[P3]->WinCheck())//플레이어 체력 확인
			{
				DrawManager.DrawTextWithBox("모든 용병이 쓰러졌습니다!", WIDTH, HEIGHT*0.5);
				system("pause");
				continue;
			}
			Battle(Select,CharacterList,1);
			AssemblyFlag= true;
			break;
		case 6:
			return AssemblyFlag;
		}
	}
}

void Dungeon::Battle(int Floor, Character *CharacterList[], int Stage)
{

	for (int i = 0,j=1; i < 3; i++,j++)
	{
		MonsterList[i] = new Monster();
		MonsterList[i]->InputData(Floor,j+((Stage-1)*3));
	}
	system("cls");
	DrawManager.DrawBox();
	DrawManager.gotoxy(WIDTH - (25*2), HEIGHT*0.5 - 2);
	for (int i = 0; i < 25; i++)//땅그리기
	{
		cout << "▨▧";
	}
	DrawManager.DrawSmallBox(WIDTH*0.5-25,HEIGHT*0.5-10,50,10);
	ShowStatus(CharacterList);
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
		if (CharacterList[P1]->WinCheck() && CharacterList[P2]->WinCheck() && CharacterList[P3]->WinCheck())//플레이어 체력 확인
		{
			system("cls");
			DrawManager.DrawBox();
			DrawManager.DrawTextWithBox("모든 용병이 쓰러졌습니다!(소지금 절반을 잃었습니다)", WIDTH, HEIGHT*0.5);
			system("pause");
			*m_iMoney *= 0.5;
			for (int i = 0; i < 3; i++)
				delete MonsterList[i];
			return;
		}
			if (MonsterList[P1]->WinCheck() && MonsterList[P2]->WinCheck() && MonsterList[P3]->WinCheck())//몬스터 체력 확인
		{
			if (Stage == 3)//보스방
			{
				*m_iMoney += (100 * Floor * 2);
				for (int i = 0; i < 3; i++)//경험치 획득
				{
					CharacterList[i]->GetExp(Floor * 5);
				}
			}
			else
			{
				*m_iMoney += (100 * Floor);
				for (int i = 0; i < 3; i++)//경험치 획득
				{
					CharacterList[i]->GetExp(Floor * 3);
				}
			}
			DrawManager.DrawTextWithBox("승 리!",WIDTH,HEIGHT*0.5);
			if (Stage == 2)
				DrawManager.DrawTextWithBox("다음 스테이지는 강력한 보스 몬스터가 출현합니다!", WIDTH, HEIGHT*0.5+6);
			system("pause");
			if (Stage == 3)
				return;
			if (NextFloorChoice() == 1)//다음층 진행 여부확인
			{
				for (int i = 0; i < 3; i++)
					delete MonsterList[i];
				Battle(Floor, CharacterList, ++Stage);
				return;
			}
			else
				break;
		}
		Sleep(1000);
	}
}

int Dungeon::NextFloorChoice()
{
	int Select;
	system("cls");
	DrawManager.DrawBox();
	DrawManager.DrawTextWithBox("계속 진행하시겠습니까?",WIDTH,HEIGHT*0.5-3);
	DrawManager.DrawMidText("예",WIDTH,HEIGHT*0.5-1);
	DrawManager.DrawMidText("아니오",WIDTH,HEIGHT*0.5+1);
	Select = DrawManager.DrawCursor(1,WIDTH*0.5-3,HEIGHT*0.5-1);
	return Select;
}

void Dungeon::ShowStatus(Character *CharacterList[])
{
	string Player[3];
	for (int i = 0; i < 3; i++)
	{
		if (CharacterList[i] == NULL)
		{
			Player[i] = " _ ";
			continue;
		}
		if (CharacterList[i]->WinCheck())
			Player[i] = " X ";
		else
			Player[i] = " O ";
	}
	DrawManager.gotoxy(WIDTH - 20, HEIGHT + 1);
	cout << "Day : " << *m_iDay << "\t 소지금 : " << *m_iMoney << " G" << "\t파티상태 : [" << Player[P1] << Player[P2] << Player[P3] << "]";
}


Dungeon::~Dungeon()
{
}

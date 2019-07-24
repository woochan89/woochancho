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
				DrawManager.DrawMidText("< �� �� >", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -2)
				DrawManager.DrawMidText("��� �ұ�(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -1)
				DrawManager.DrawMidText("��ũ ����(Lv 11~20)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 0)
				DrawManager.DrawMidText("���ֹ��� ����(Lv 21~30)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 1)
				DrawManager.DrawMidText("������ ��(Lv 31~40)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 2)
				DrawManager.DrawMidText("���� ����(Lv 41~50)", WIDTH, HEIGHT*0.5 + 2 * i);
			else
				DrawManager.DrawMidText("������", WIDTH, HEIGHT*0.5 + 2 * i);
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
	for (int i = 0; i < 25; i++)//���׸���
	{
		cout << "�ɢ�";
	}
	DrawManager.DrawSmallBox(WIDTH*0.5-25,HEIGHT*0.5-10,50,10);

	for (int i = P1; i <= P3; i++)//��������â ǥ��
	{
		CharacterList[i]->ShowBattleStat(PLAYER, i);
		MonsterList[i]->ShowBattleStat(MONSTER, i);
	}
	Sleep(1000);
	while (1)
	{
		int DmgToPlayer[3] = { 0 };
		int DmgToMonster[3] = { 0 };
		for (int i = P1; i <= P3; i++)//������ Ȯ��
		{
			CharacterList[i]->DealToEnemy(DmgToMonster,MonsterList);
			MonsterList[i]->DealToEnemy(DmgToPlayer,CharacterList);
		}
		for (int i = P1; i <= P3; i++)//������ ����
		{
			CharacterList[i]->GetDmg(DmgToPlayer,i);
			MonsterList[i]->GetDmg(DmgToMonster,i);
		}
		for (int i = P1; i <= P3; i++)//��������â ǥ��
		{
			CharacterList[i]->ShowBattleStat(PLAYER,i);
			MonsterList[i]->ShowBattleStat(MONSTER,i);
		}
		if (MonsterList[P1]->WinCheck() && MonsterList[P2]->WinCheck() && MonsterList[P3]->WinCheck())//�¸�Ȯ��
		{
			for (int i = 0; i < 3; i++)//����ġ ȹ��
			{
				CharacterList[i]->GetExp(Floor*3);
			}
			DrawManager.DrawTextWithBox("�� ��!",WIDTH,HEIGHT*0.5);
			system("pause");
			if (NextFloorChoice())//������ ���� ����Ȯ��
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
	DrawManager.DrawTextWithBox("��� �����Ͻðڽ��ϱ�?",WIDTH,HEIGHT*0.5-3);
	DrawManager.DrawMidText("��",WIDTH,HEIGHT*0.5-1);
	DrawManager.DrawMidText("�ƴϿ�",WIDTH,HEIGHT*0.5+1);
	Select = DrawManager.DrawCursor(1,WIDTH*0.5-3,HEIGHT*0.5-1);
	return Select;
}


Dungeon::~Dungeon()
{
}

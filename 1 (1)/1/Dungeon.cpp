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
				DrawManager.DrawMidText("< �� �� >", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -2)
				DrawManager.DrawMidText("��� �ұ�(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -1)
				DrawManager.DrawMidText("��� �ұ�(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 0)
				DrawManager.DrawMidText("��� �ұ�(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 1)
				DrawManager.DrawMidText("��� �ұ�(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 2)
				DrawManager.DrawMidText("��� �ұ�(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else
				DrawManager.DrawMidText("������", WIDTH, HEIGHT*0.5 + 2 * i);
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
		for (int i = P1; i <= P3; i++)//������ Ȯ��
		{
			CharacterList[i]->DealToEnemy(DmgToEnemy);
			MonsterList[i]->DealToEnemy(DmgToPlayer);
		}
		for (int i = P1; i <= P3; i++)//������ ����
		{
			CharacterList[i]->GetDmg(DmgToPlayer,i);
			MonsterList[i]->GetDmg(DmgToEnemy,i);
		}
		for (int i = P1; i <= P3; i++)//��������â ǥ��
		{
			CharacterList[i]->ShowBattleStat(PLAYER);
			MonsterList[i]->ShowBattleStat(MONSTER);
		}
		if (MonsterList[0]->WinCheck() && MonsterList[0]->WinCheck() && MonsterList[0]->WinCheck())//�¸�Ȯ��
		{
			//������
			//������ ���� ����Ȯ��
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

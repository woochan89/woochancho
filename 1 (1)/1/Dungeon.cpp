#include "Dungeon.h"



Dungeon::Dungeon()
{
}

void Dungeon::Menu(Character *CharacterList[],int *Money)
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
				DrawManager.DrawMidText("��ũ ����(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 0)
				DrawManager.DrawMidText("���ֹ��� ����(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 1)
				DrawManager.DrawMidText("������ ��(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 2)
				DrawManager.DrawMidText("���� ����(Lv 1~10)", WIDTH, HEIGHT*0.5 + 2 * i);
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
			Battle(Select,CharacterList);
			*Money += 100 * Select;
			break;
		case 6:
			return;
		}
	}
}

void Dungeon::Battle(int Floor, Character *CharacterList[])
{

	for (int i = 0; i < 3; i++)
	{
		MonsterList[i] = new Monster();
		MonsterList[i]->InputData(Floor,i);
	}
	system("cls");
	DrawManager.DrawBox();
	DrawManager.gotoxy(WIDTH - (25*2), HEIGHT*0.5 - 2);
	for (int i = 0; i < 25; i++)//���׸���
	{
		cout << "�ɢ�";
	}
	DrawManager.DrawSmallBox(WIDTH*0.5-25,HEIGHT*0.5-10,50,10);

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
			DrawManager.DrawMidText("�� ��!",WIDTH,HEIGHT*0.5);
			system("pause");
			break;//������ ���� ����Ȯ��
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

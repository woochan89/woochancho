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
			if (CharacterList[P1]->WinCheck() && CharacterList[P2]->WinCheck() && CharacterList[P3]->WinCheck())//�÷��̾� ü�� Ȯ��
			{
				DrawManager.DrawTextWithBox("��� �뺴�� ���������ϴ�!", WIDTH, HEIGHT*0.5);
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
	for (int i = 0; i < 25; i++)//���׸���
	{
		cout << "�ɢ�";
	}
	DrawManager.DrawSmallBox(WIDTH*0.5-25,HEIGHT*0.5-10,50,10);
	ShowStatus(CharacterList);
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
		if (CharacterList[P1]->WinCheck() && CharacterList[P2]->WinCheck() && CharacterList[P3]->WinCheck())//�÷��̾� ü�� Ȯ��
		{
			system("cls");
			DrawManager.DrawBox();
			DrawManager.DrawTextWithBox("��� �뺴�� ���������ϴ�!(������ ������ �Ҿ����ϴ�)", WIDTH, HEIGHT*0.5);
			system("pause");
			*m_iMoney *= 0.5;
			for (int i = 0; i < 3; i++)
				delete MonsterList[i];
			return;
		}
			if (MonsterList[P1]->WinCheck() && MonsterList[P2]->WinCheck() && MonsterList[P3]->WinCheck())//���� ü�� Ȯ��
		{
			if (Stage == 3)//������
			{
				*m_iMoney += (100 * Floor * 2);
				for (int i = 0; i < 3; i++)//����ġ ȹ��
				{
					CharacterList[i]->GetExp(Floor * 5);
				}
			}
			else
			{
				*m_iMoney += (100 * Floor);
				for (int i = 0; i < 3; i++)//����ġ ȹ��
				{
					CharacterList[i]->GetExp(Floor * 3);
				}
			}
			DrawManager.DrawTextWithBox("�� ��!",WIDTH,HEIGHT*0.5);
			if (Stage == 2)
				DrawManager.DrawTextWithBox("���� ���������� ������ ���� ���Ͱ� �����մϴ�!", WIDTH, HEIGHT*0.5+6);
			system("pause");
			if (Stage == 3)
				return;
			if (NextFloorChoice() == 1)//������ ���� ����Ȯ��
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
	DrawManager.DrawTextWithBox("��� �����Ͻðڽ��ϱ�?",WIDTH,HEIGHT*0.5-3);
	DrawManager.DrawMidText("��",WIDTH,HEIGHT*0.5-1);
	DrawManager.DrawMidText("�ƴϿ�",WIDTH,HEIGHT*0.5+1);
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
	cout << "Day : " << *m_iDay << "\t ������ : " << *m_iMoney << " G" << "\t��Ƽ���� : [" << Player[P1] << Player[P2] << Player[P3] << "]";
}


Dungeon::~Dungeon()
{
}

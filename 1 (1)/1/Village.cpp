#include "Village.h"



Village::Village()
{
	int Width= (WIDTH * 2) + 1;
	int Height= HEIGHT + 5;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);
	m_iDay = 1;
	m_iMoney = 0;
	m_bFacilityFlag = true;
	tmp[0] = { NULL };
	for (int i = 0; i < 3; i++)
		CharacterList[i] = NULL;
	GameStart();
}

void Village::GameStart()
{
	int Num = 0;
	DrawManager.DrawMidText("������ �Բ��� ���� ������ �������ּ���!", WIDTH, HEIGHT*0.5);
	DrawManager.gotoxy(0, HEIGHT);
	system("pause");
	AssemblyFacility();
	Menu();
}

void Village::Menu()
{
	int Select;
	while (true)
	{
		system("cls");
		DrawManager.DrawBox();
		ShowStatus();
		for (int i = -3; i <= 3; i++)
		{
			if (i == -3)
				DrawManager.DrawMidText("< �� �� >",WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -2)
				DrawManager.DrawMidText("�� ��", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -1)
				DrawManager.DrawMidText("�� ��", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 0)
				DrawManager.DrawMidText("�� ȸ �� ��", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 1)
				DrawManager.DrawMidText("�� ��", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 2)
				DrawManager.DrawMidText("�� ��", WIDTH, HEIGHT*0.5 + 2 * i);
			else
				DrawManager.DrawMidText("������", WIDTH, HEIGHT*0.5 + 2 * i);
		}
		Select = DrawManager.DrawCursor(6, WIDTH*0.5-4, HEIGHT*0.5 - 4);
		switch (Select)
		{
		case 1:
			DungeonManager.Menu(CharacterList);
			break;
		case 2:
			break;
		case 3://��ȸ����
			AssemblyFacility();
			break;
		case 4://����
			if (m_iMoney >= 100)
			{
				m_iDay++;
				m_iMoney -= 100;
				//ĳ���� ü��ȸ��
			}
			else
			{
				system("cls");
				DrawManager.DrawBox();
				DrawManager.DrawMidText("�������� �����մϴ�!",WIDTH,HEIGHT*0.5);
				DrawManager.gotoxy(0, HEIGHT);
				system("pause");
			}
			break;
		case 5:
			AdjustCharacter();
			break;
		case 6:
			return;
		}
	}
}

void Village::ShowStatus()
{
	DrawManager.gotoxy(WIDTH-10,HEIGHT+1);
	cout << "Day : " << m_iDay << "\t ������ : " << m_iMoney<<" G";
}

void Village::HireCharacter()
{
	int Select;
	system("cls");
	DrawManager.DrawBox();
	DrawManager.DrawMidText("���� �뺴�� �ذ��� ���ο� �뺴�� ����Ͻðڽ��ϱ�?",WIDTH,HEIGHT*0.5-4);
	DrawManager.DrawMidText("��",WIDTH,HEIGHT*0.5-2);
	DrawManager.DrawMidText("�ƴϿ�",WIDTH,HEIGHT*0.5-0);
	Select = DrawManager.DrawCursor(2, WIDTH*0.5 - 5, HEIGHT*0.5 - 2);
	switch (Select)
	{
	case 1:
			system("cls");
			DrawManager.DrawBox();
			DrawManager.DrawMidText("< �� �� �� �� >", WIDTH, HEIGHT*0.5 - 6);
			for (int i = 0,j=-4; i < 3; i++,j+=2)
			{
				DrawManager.gotoxy(WIDTH*0.5 + 15, HEIGHT*0.5 + j);
				cout << CharacterList[i]->OutputName() << "  " << CharacterList[i]->OutputClass() << " ���";
			}
			Select = DrawManager.DrawCursor(3, WIDTH*0.5 - 5, HEIGHT*0.5 - 4);
			DrawManager.gotoxy(10, HEIGHT*0.5);
			cout << CharacterList[Select - 1]->OutputName() << "�� �ذ��Ͽ����ϴ�!";
			if (Select == 1)
			{
				delete CharacterList[0];
				CharacterList[0] = NULL;
			}
			else if(Select==2)
			{
				delete CharacterList[1];
				CharacterList[1] = NULL;
			}
			else
			{
				delete CharacterList[2];
				CharacterList[2] = NULL;
			}
			DrawManager.gotoxy(0, HEIGHT);
			system("pause");
		break;
	case 2:
		return;
	}

}

void Village::AssemblyFacility()//��ȸ����
{
	int Select;
	int CharacterNum;
	int CharacterNumber=0;
	if (m_bFacilityFlag == true)
	{
		if (tmp[0] != NULL)//��üũ
		{
			for (int i = 0; i < 5; i++)
			{
				delete tmp[i];
				tmp[i] = NULL;
			}
		}
		for (int i = 0,j; i < 5; i++)//���� �뺴 �־��ֱ�
		{
			j = rand() % 3;
			if (j == 0)
				tmp[i] = new Archer();
			else if (j == 1)
				tmp[i] = new Magician();
			else
				tmp[i] = new Warrior();
			tmp[i]->InputData();
		}
	}

	for (int i;true;)
	{
		i = -2;
		system("cls");
		DrawManager.DrawBox();
		DrawManager.DrawMidText("< �� ȸ �� �� >", WIDTH, HEIGHT*0.5 -6);
		for (CharacterNum = 0; CharacterNum < 5; CharacterNum++ ,i++)
		{
			DrawManager.gotoxy(WIDTH*0.5 + 15, HEIGHT*0.5 + 2 * i);
			if (tmp[CharacterNum] == NULL)
				cout << "�� ��";
			else
				cout << tmp[CharacterNum]->OutputName() << "  " << tmp[CharacterNum]->OutputClass() << " ���";
		}
		DrawManager.DrawMidText("������", WIDTH, HEIGHT*0.5 + 2 * i);
		Select = DrawManager.DrawCursor(CharacterNum+1, WIDTH*0.5 - 5, HEIGHT*0.5 - 4);
		switch (Select)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			if (tmp[Select - 1] == NULL)
			{
				DrawManager.DrawMidText("�̹� ���õ� �뺴�Դϴ�.", WIDTH, HEIGHT*0.5);
				DrawManager.gotoxy(0, HEIGHT);
				system("pause");
				break;

			}
			if (CharacterList[0]!=NULL&& CharacterList[1] != NULL && CharacterList[2] != NULL)
			{
				DrawManager.DrawMidText("�뺴�� ����á���ϴ�.", WIDTH, HEIGHT*0.5);
				DrawManager.gotoxy(0, HEIGHT);
				system("pause");
				HireCharacter();
				break;
			}
			for (CharacterNumber = 0; CharacterNumber < 3; CharacterNumber++)
			{
				if (CharacterList[CharacterNumber] == NULL)
					break;
			}
			if (tmp[Select - 1]->OutputName() == "�ü�")
				CharacterList[CharacterNumber] = new Archer();
			else if (tmp[Select - 1]->OutputName() == "������")
				CharacterList[CharacterNumber] = new Magician();
			else
				CharacterList[CharacterNumber] = new Warrior();
			CharacterList[CharacterNumber]->InputData(tmp[Select - 1]->OutputClass());
			delete tmp[Select - 1];
			tmp[Select - 1] = NULL;
			break;
		case 6:
			if (CharacterList[0] != NULL && CharacterList[1] != NULL && CharacterList[2] != NULL)
			{
				m_bFacilityFlag = false;
				return;
			}
			DrawManager.DrawMidText("�뺴 3���� ��� ä���ֽʽÿ�", WIDTH, HEIGHT*0.5);
			DrawManager.gotoxy(0, HEIGHT);
			system("pause");
			break;
		}
	}
}

void Village::AdjustCharacter()
{
	int Select;
	system("cls");
	DrawManager.DrawBox();
	for (int i = 0; i < 3; i++)
	{
		CharacterList[i]->ShowStat(WIDTH*0.5, HEIGHT*0.5 - 8 + i * 5);
	}
	DrawManager.DrawMidText("������", WIDTH, HEIGHT*0.5 + 9);
	Select = DrawManager.DrawCursor(4, WIDTH*0.5 - 12, HEIGHT*0.5 - 6,5);

}

Village::~Village()
{
	if (tmp[0] != NULL)
	{
		for (int i = 0; i < 5; i++)
			delete tmp[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (CharacterList[i] != NULL)
			delete CharacterList[i];
	}
}

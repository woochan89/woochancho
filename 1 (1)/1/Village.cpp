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
	DrawManager.DrawMidText("모험을 함께할 동료 세명을 선택해주세요!", WIDTH, HEIGHT*0.5);
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
				DrawManager.DrawMidText("< 마 을 >",WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -2)
				DrawManager.DrawMidText("던 전", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -1)
				DrawManager.DrawMidText("상 점", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 0)
				DrawManager.DrawMidText("집 회 구 역", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 1)
				DrawManager.DrawMidText("여 관", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 2)
				DrawManager.DrawMidText("조 정", WIDTH, HEIGHT*0.5 + 2 * i);
			else
				DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 2 * i);
		}
		Select = DrawManager.DrawCursor(6, WIDTH*0.5-4, HEIGHT*0.5 - 4);
		switch (Select)
		{
		case 1:
			DungeonManager.Menu(CharacterList);
			break;
		case 2:
			break;
		case 3://집회구역
			AssemblyFacility();
			break;
		case 4://여관
			if (m_iMoney >= 100)
			{
				m_iDay++;
				m_iMoney -= 100;
				//캐릭터 체력회복
			}
			else
			{
				system("cls");
				DrawManager.DrawBox();
				DrawManager.DrawMidText("소지금이 부족합니다!",WIDTH,HEIGHT*0.5);
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
	cout << "Day : " << m_iDay << "\t 소지금 : " << m_iMoney<<" G";
}

void Village::HireCharacter()
{
	int Select;
	system("cls");
	DrawManager.DrawBox();
	DrawManager.DrawMidText("기존 용병을 해고후 새로운 용병을 고용하시겠습니까?",WIDTH,HEIGHT*0.5-4);
	DrawManager.DrawMidText("예",WIDTH,HEIGHT*0.5-2);
	DrawManager.DrawMidText("아니오",WIDTH,HEIGHT*0.5-0);
	Select = DrawManager.DrawCursor(2, WIDTH*0.5 - 5, HEIGHT*0.5 - 2);
	switch (Select)
	{
	case 1:
			system("cls");
			DrawManager.DrawBox();
			DrawManager.DrawMidText("< 현 재 용 병 >", WIDTH, HEIGHT*0.5 - 6);
			for (int i = 0,j=-4; i < 3; i++,j+=2)
			{
				DrawManager.gotoxy(WIDTH*0.5 + 15, HEIGHT*0.5 + j);
				cout << CharacterList[i]->OutputName() << "  " << CharacterList[i]->OutputClass() << " 등급";
			}
			Select = DrawManager.DrawCursor(3, WIDTH*0.5 - 5, HEIGHT*0.5 - 4);
			DrawManager.gotoxy(10, HEIGHT*0.5);
			cout << CharacterList[Select - 1]->OutputName() << "를 해고하였습니다!";
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

void Village::AssemblyFacility()//집회구역
{
	int Select;
	int CharacterNum;
	int CharacterNumber=0;
	if (m_bFacilityFlag == true)
	{
		if (tmp[0] != NULL)//널체크
		{
			for (int i = 0; i < 5; i++)
			{
				delete tmp[i];
				tmp[i] = NULL;
			}
		}
		for (int i = 0,j; i < 5; i++)//랜덤 용병 넣어주기
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
		DrawManager.DrawMidText("< 집 회 구 역 >", WIDTH, HEIGHT*0.5 -6);
		for (CharacterNum = 0; CharacterNum < 5; CharacterNum++ ,i++)
		{
			DrawManager.gotoxy(WIDTH*0.5 + 15, HEIGHT*0.5 + 2 * i);
			if (tmp[CharacterNum] == NULL)
				cout << "공 석";
			else
				cout << tmp[CharacterNum]->OutputName() << "  " << tmp[CharacterNum]->OutputClass() << " 등급";
		}
		DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 2 * i);
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
				DrawManager.DrawMidText("이미 선택된 용병입니다.", WIDTH, HEIGHT*0.5);
				DrawManager.gotoxy(0, HEIGHT);
				system("pause");
				break;

			}
			if (CharacterList[0]!=NULL&& CharacterList[1] != NULL && CharacterList[2] != NULL)
			{
				DrawManager.DrawMidText("용병이 가득찼습니다.", WIDTH, HEIGHT*0.5);
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
			if (tmp[Select - 1]->OutputName() == "궁수")
				CharacterList[CharacterNumber] = new Archer();
			else if (tmp[Select - 1]->OutputName() == "마법사")
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
			DrawManager.DrawMidText("용병 3명을 모두 채워주십시오", WIDTH, HEIGHT*0.5);
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
	DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 9);
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

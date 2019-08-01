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
	DungeonManager = new Dungeon(&m_iMoney,&m_iDay);
	MainMenu();
}

void Village::MainMenu()
{
	int Select;
	while (true)
	{
		system("cls");
		DrawManager.DrawBox();
		DrawManager.DrawTextWithBox("던 전  R P G", WIDTH, HEIGHT*0.5 - 4);
		DrawManager.DrawMidText("새 게임", WIDTH, HEIGHT*0.5 - 1);
		DrawManager.DrawMidText("불러오기", WIDTH, HEIGHT*0.5 + 1);
		DrawManager.DrawMidText("종료", WIDTH, HEIGHT*0.5 + 3);
		Select = DrawManager.DrawCursor(2, WIDTH*0.5 - 4, HEIGHT*0.5 - 1);
		switch (Select)
		{
		case 1:
			GameStart();
			break;
		case 2:
			Load();
			break;
		case 3:
			return;
		}
	}
}

void Village::GameStart()
{
	int Num = 0;
	DrawManager.DrawBox();
	DrawManager.DrawTextWithBox("모험을 함께할 용병 세명을 선택해주세요!", WIDTH, HEIGHT*0.5);
	system("pause");
	AssemblyFacility(1);
	VillageInterface();
}

void Village::VillageInterface()
{
	int Select;
	while (true)
	{
		system("cls");
		DrawManager.DrawBox();
		ShowStatus();
		for (int i = -3; i <= 4; i++)
		{
			if (i == -3)
				DrawManager.DrawMidText("< 마 을 >",WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -2)
				DrawManager.DrawMidText("던 전", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -1)
				DrawManager.DrawMidText("집 회 구 역", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 0)
				DrawManager.DrawMidText("여 관", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 1)
				DrawManager.DrawMidText("상 태 창", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 2)
				DrawManager.DrawMidText("저 장 하 기", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 3)
				DrawManager.DrawMidText("불 러 오 기", WIDTH, HEIGHT*0.5 + 2 * i);
			else
				DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 2 * i);
		}
		Select = DrawManager.DrawCursor(6, WIDTH*0.5-4, HEIGHT*0.5 - 4);
		switch (Select)
		{
		case 1:
			m_bFacilityFlag=DungeonManager->Menu(CharacterList);
			break;
		case 2://집회구역
			AssemblyFacility(0);
			break;
		case 3://여관
			if (m_iMoney >= 100)
			{
				m_iDay++;
				m_iMoney -= 100;
				for (int i = 0; i < 3; i++)
				{
					CharacterList[i]->Recovery();
				}
				DrawManager.DrawTextWithBox("휴식을 취했습니다(소지금 -100G)", WIDTH, HEIGHT*0.5);
				system("pause");
			}
			else
			{
				system("cls");
				DrawManager.DrawBox();
				DrawManager.DrawTextWithBox("소지금이 부족합니다!", WIDTH, HEIGHT*0.5);
				system("pause");
			}
			break;
		case 4:
			AdjustCharacter();
			break;
		case 5://저장하기
			break;
		case 6://불러오기
			Load();
			break;
		case 7:
			return;
		}
	}
}

void Village::ShowStatus()
{
	string Player[3];
	for (int i = 0;i < 3; i++)
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
	DrawManager.gotoxy(WIDTH-20,HEIGHT+1);
	cout << "Day : " << m_iDay << "\t 소지금 : " << m_iMoney<<" G"<<"\t파티상태 : ["<<Player[P1]<<Player[P2]<<Player[P3]<<"]";
}

void Village::HireCharacter()
{
	int Select;
	system("cls");
	DrawManager.DrawBox();
	DrawManager.DrawMidText("기존 용병을 해고후 새로운 용병을 고용하시겠습니까?",WIDTH,HEIGHT*0.5-4);
	DrawManager.DrawMidText("예",WIDTH,HEIGHT*0.5-2);
	DrawManager.DrawMidText("아니오",WIDTH,HEIGHT*0.5-0);
	Select = DrawManager.DrawCursor(1, WIDTH*0.5 - 5, HEIGHT*0.5 - 2);
	switch (Select)
	{
	case 1:
			system("cls");
			DrawManager.DrawBox();
			DrawManager.DrawMidText("< 현 재 용 병 >", WIDTH, HEIGHT*0.5 - 6);
			for (int i = 0,j=-4; i <= 3; i++,j+=2)
			{
				DrawManager.gotoxy((WIDTH*0.5-3)*2, HEIGHT*0.5 + j);
				if (i == 3)
				{
					cout << "나가기";
					break;
				}
				cout << CharacterList[i]->OutputName() << "  " << CharacterList[i]->OutputClass() << " 등급";
			}
			Select = DrawManager.DrawCursor(3, WIDTH*0.5 - 5, HEIGHT*0.5 - 4);
			DrawManager.gotoxy((WIDTH*0.5-6)*2, HEIGHT*0.5);
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

void Village::AssemblyFacility(bool Check)//집회구역
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
			DrawManager.gotoxy((WIDTH*0.5-3)*2  , HEIGHT*0.5 + 2 * i);
			if (tmp[CharacterNum] == NULL)
				cout << "공 석";
			else
				cout << tmp[CharacterNum]->OutputName() << "  " << tmp[CharacterNum]->OutputClass() << " 등급";
		}
		DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 2 * i);
		Select = DrawManager.DrawCursor(CharacterNum, WIDTH*0.5 - 5, HEIGHT*0.5 - 4);
		switch (Select)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			if (tmp[Select - 1] == NULL)
			{
				DrawManager.DrawTextWithBox("이미 선택된 용병입니다.", WIDTH, HEIGHT*0.5);
				DrawManager.gotoxy(0, HEIGHT);
				system("pause");
				break;

			}
			if (CharacterList[0]!=NULL&& CharacterList[1] != NULL && CharacterList[2] != NULL)
			{
				DrawManager.DrawTextWithBox("용병이 가득찼습니다.", WIDTH, HEIGHT*0.5);
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
			if (CharacterNumber == 2 && Check == 1)
			{
				m_bFacilityFlag = false;
				DrawManager.DrawTextWithBox("함께 할 용병 3명을 모두 선택하셨습니다!",WIDTH,HEIGHT*0.5);
				system("pause");
				return;
			}
			break;
		case 6:
			if (CharacterList[0] != NULL && CharacterList[1] != NULL && CharacterList[2] != NULL)
			{
				m_bFacilityFlag = false;
				return;
			}
			DrawManager.DrawTextWithBox("용병 3명을 모두 채워주십시오", WIDTH, HEIGHT*0.5);
			system("pause");
			break;
		}
	}
}

void Village::AdjustCharacter()
{
	int Select1st=0,Select2nd=0;
	Character *tmp;
	while (true)
	{
		system("cls");
		DrawManager.DrawBox();
		if (Select1st == 0)
			DrawManager.DrawMidText("위치를 바꿀 용병을 선택해주십시오", WIDTH, 5);
		else
			DrawManager.DrawMidText("바꿀 위치의 용병을 선택해주십시오", WIDTH, 5);
		for (int i = 0; i < 3; i++)
		{
			DrawManager.gotoxy((WIDTH*0.5 - 10) * 2, HEIGHT*0.5 - 6 + i * 5);
			if (i == 0)
				cout << "선봉";
			else if (i == 1)
				cout << "중진";
			else
				cout << "후위";
		}
		for (int i = 0; i < 3; i++)
		{
			CharacterList[i]->ShowStat((WIDTH*0.5 - 7) * 2, HEIGHT*0.5 - 8 + i * 5);
		}
		DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 9);
		if (Select1st == 4)
			break;
		if (Select1st == 0)
			Select1st = DrawManager.DrawCursor(3, WIDTH*0.5 - 12, HEIGHT*0.5 - 6, 5);
		else
		{
				Select2nd = DrawManager.DrawCursor(3, WIDTH*0.5 - 12, HEIGHT*0.5 - 6, 5);
				if (Select2nd == 4)
					break;
				if (CharacterList[Select2nd - 1]->OutputName() == "궁수")
					tmp = new Archer();
				else if (CharacterList[Select2nd - 1]->OutputName() == "마법사")
					tmp = new Magician();
				else
					tmp = new Warrior();
				tmp->GetData(CharacterList[Select2nd - 1]);
				delete CharacterList[Select2nd - 1];
				if (CharacterList[Select1st - 1]->OutputName() == "궁수")
					CharacterList[Select2nd - 1] = new Archer();
				else if (CharacterList[Select1st - 1]->OutputName() == "마법사")
					CharacterList[Select2nd - 1] = new Magician();
				else
					CharacterList[Select2nd - 1] = new Warrior();
				CharacterList[Select2nd - 1]->GetData(CharacterList[Select1st - 1]);
				delete CharacterList[Select1st - 1];
				CharacterList[Select1st - 1] = tmp;
				Select1st = 0;
				Select2nd = 0;
		}
	}

}

void Village::Save()
{
	ofstream save;
	save.open("Save.txt");
	if (save.is_open())
	{
		DrawManager.DrawTextWithBox("기존 세이브 파일이 있습니다", WIDTH, HEIGHT*0.5);
		system("pause");
		save.close();
	}
	else
	{
		save << m_iDay << " " << m_iMoney << endl;
		DrawManager.DrawTextWithBox("세이브 완료!", WIDTH, HEIGHT*0.5);
		system("pause");
		save.close();
	}

}

void Village::Load()
{
	ifstream load;
	load.open("Save.txt");
	if (load.is_open())
	{
		DrawManager.DrawTextWithBox("세이브 파일이 없습니다!",WIDTH,HEIGHT*0.5);
		system("pause");
		load.close();
	}
	else
	{

		DrawManager.DrawTextWithBox("불러오기 완료!", WIDTH, HEIGHT*0.5);
		system("pause");
		load.close();
	}
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
	delete DungeonManager;
}

#include "Play.h"



Play::Play()
{
	m_iHeart = 9;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, (WIDTH * 2) + 1);
	system(buf);
	srand((unsigned)time);
	m_iTypingWordNum = 0;
	Menu();
}

void Play::Menu()
{
	int Select;
	while (true)
	{
		Drawmanager.Drawinterface();
		YELLOW
		Drawmanager.DrawTextWithBox("★ ☆ 베 네 치 아 ☆ ★", WIDTH, HEIGHT*0.2);
		ORIGINAL
		Drawmanager.DrawMidText("1. 게임 시작", WIDTH, HEIGHT*0.5 - 2);
		Drawmanager.DrawMidText("2. 랭킹", WIDTH, HEIGHT*0.5);
		Drawmanager.DrawMidText("3. 나가기", WIDTH, HEIGHT*0.5 + 2);
		Select = Drawmanager.DrawCursor(3, WIDTH*0.5 - 6, HEIGHT*0.5 - 2);
		cout << Select;
		switch (Select)
		{
		case 1:
			Drawmanager.Drawinterface();
			Intro();
			m_sName=Getname();
			Gameplay();
			break;
		case 2:
			Rankmanager.Showrank();
			break;
		case 3:
			return;
		}
	}
}

void Play::Intro()
{
	char ch;
	int max;
	int Curclock, Wordclock;
	ifstream load;
	string *str;
	load.open("베네치아_스토리.txt");
	load >> max;
	str = new string[max + 1];
	for (int i=0;!load.eof();i++)
	{
		getline(load, str[i]);
	}
	Drawmanager.DrawSmallBox(WIDTH*0.5 - 6, HEIGHT*0.5 + 6, 12, 3);
	Drawmanager.DrawMidText("Skip : s", WIDTH, HEIGHT*0.5 + 7);
	Wordclock = clock();
	for (int i = 0; i <= max;)
	{
		Curclock = clock();
		if (Curclock - Wordclock >= 500)
		{
			i++;
			if (i >= 12)
			{
				for (int j = i - 12, k = 0; k < 12; j++, k++)
				{
					Drawmanager.DrawMidText("                                       ", WIDTH, HEIGHT*0.5 - 7 + k);
					Drawmanager.DrawMidText(str[j + 1], WIDTH, HEIGHT*0.5 - 7 + k);
				}
				continue;
			}
			Drawmanager.DrawMidText(str[i], WIDTH, HEIGHT*0.5 - 7 + i);
			Wordclock = Curclock;
		}
		if (kbhit())
		{
			ch = getch();
			if (ch == 's')
				return;
		}
	}

}

string Play::Getname()
{
	char tmp[11] = {NULL};
	int num=0;
	char ch;
	Drawmanager.Drawinterface();
	Drawmanager.DrawSmallBox(WIDTH*0.5 - 6, HEIGHT*0.5 + 6, 12, 3);
	Drawmanager.DrawMidText("이름 입력(영문,10글자 이하)", WIDTH, HEIGHT*0.5 + 5);
	while (true)
	{
		ch = getch();
		if (ch == 13&&num>0)//엔터
			break;
		else if (ch == 8)//백스페이스
		{
			tmp[num - 1] = NULL;
			if (num > 0)
				num--;
		}
		else if (!(ch >= 'a'&&ch <= 'z') && !(ch >= 'A'&&ch <= 'Z'))
			continue;
		else
			tmp[num++]=ch;
		Drawmanager.DrawMidText("                    ", WIDTH, HEIGHT*0.5 + 7);
		Drawmanager.DrawMidText(tmp, WIDTH, HEIGHT*0.5 + 7);
		if (num > 9)
		{
			Drawmanager.DrawTextWithBox("10글자 초과!!", WIDTH, HEIGHT*0.5);
			system("pause");
			break;
		}
	}
	return tmp;
}

bool Play::GetWord()
{
	char ch = getch();
	if (ch == 13)//엔터
	{
		if (m_iTypingWordNum > 0)
		{
			m_iTypingWordNum = 0;
			return true;
		}
		return false;
	}
	else if (ch == 8)//백스페이스
	{
		if (m_iTypingWordNum > 0)
		{
			m_cWord[m_iTypingWordNum - 1] = NULL;
			m_iTypingWordNum--;
		}
	}
	else if (!(ch >= 'a'&&ch <= 'z') && !(ch >= 'A'&&ch <= 'Z'))
		return false;
	else
		m_cWord[m_iTypingWordNum++] = ch;
	Drawmanager.DrawMidText("                    ", WIDTH, HEIGHT*0.5 + 7);
	Drawmanager.DrawMidText(m_cWord, WIDTH, HEIGHT*0.5 + 7);

	return false;
}

void Play::Gameplay(int stage)
{
	int Effect;
	int TimeCounter = 0;
	int StopCounter = 0;
	int ErrorCounter=0;
	int Curclock, Wordclock;
	int wordlength=0;
	int loseheart=0;
	int Score=0;
	int Gamespeed;
	float SpeedChange = 1;
	char tmp[20];
	sprintf(tmp, "%d stage", stage);
	Drawmanager.Drawinterface(m_sName, m_iHeart);
	Drawmanager.DrawSmallBox(WIDTH*0.5 - 6, HEIGHT*0.5 + 6, 12, 3);
	Drawmanager.DrawMidText(tmp, WIDTH, HEIGHT*0.5);
	Drawmanager.gotoxy(WIDTH, HEIGHT*0.5 + 7);
	Sleep(1000);
	Drawmanager.DrawMidText("       ", WIDTH, HEIGHT*0.5);
	Drawmanager.gotoxy(WIDTH, HEIGHT*0.5 + 7);
	Sleep(500);
	Wordclock = clock();
	while (true)
	{
		Curclock = clock();
		if (kbhit())
		{
				if (ErrorCounter == NULL&&GetWord())
				{
					Effect = Word::HitWord(m_cWord, &wordlength);
					if (wordlength == NULL)
					{
						Drawmanager.DrawMidText("                    ", WIDTH, HEIGHT*0.5 + 7);
						Drawmanager.DrawMidText("MISS!", WIDTH, HEIGHT*0.5 + 7);
						ErrorCounter = 4;
						for (int i = 0; i < 11; i++)
							m_cWord[i] = NULL;
					}
					else
					{
						for (int i = 0; i < 11; i++)
							m_cWord[i] = NULL;
						Drawmanager.DrawMidText("                    ", WIDTH, HEIGHT*0.5 + 7);
					}
					if (Effect == SLOW)
					{
						SpeedChange = 1.5;
						TimeCounter = 4;
					}
					else if (Effect == FAST)
					{
						SpeedChange = 0.5;
						TimeCounter = 4;
					}
					else if (Effect == STOP)
						StopCounter = 4;
					if (wordlength != 0)
					{
						Score += wordlength * 10;
						Drawmanager.DrawScore(Score);
					}
					if (Score >= 200 + stage * 200)
					{
						Drawmanager.DrawTextWithBox("STAGE CLEAR!!", WIDTH, HEIGHT*0.5);
						system("pause");
						Word::WordReset();
						Gameplay(++stage);
						return;
					}
				}
			
		}
		Gamespeed = 500 - (100 * stage);
		if (Gamespeed <= 400)
			Gamespeed = 400;
		Gamespeed *= SpeedChange;
		if (Curclock - Wordclock >= Gamespeed)
		{
			if (StopCounter == 0)
			{
				loseheart = Word::Dropword();
				if (loseheart != 0)
				{
					m_iHeart -= loseheart;
					Drawmanager.DrawHeart(m_iHeart);
					loseheart = 0;
					if (m_iHeart <= 0)
					{
						Drawmanager.DrawTextWithBox("STAGE FAIL", WIDTH, HEIGHT*0.5);
						system("pause");
						Word::WordReset();
						m_iHeart = 9;
						return;
					}
				}
				Word::Makeword();
			}
			else
				StopCounter--;
			Wordclock = Curclock;
			if (TimeCounter != 0)
			{
				TimeCounter--;
				if (TimeCounter == 0)
					SpeedChange = 1;
			}
			if (ErrorCounter > 0)
			{
				ErrorCounter--;
				if(ErrorCounter==0)
					Drawmanager.DrawMidText("     ", WIDTH, HEIGHT*0.5 + 4);
			}
		}
	}
}

Play::~Play()
{
}

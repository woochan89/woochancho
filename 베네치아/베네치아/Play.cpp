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
		Drawmanager.DrawTextWithBox("★ ☆ 베 네 치 아 ☆ ★", WIDTH, HEIGHT*0.2);
		Drawmanager.DrawMidText("1. 게임 시작", WIDTH, HEIGHT*0.5 - 2);
		Drawmanager.DrawMidText("2. 랭킹", WIDTH, HEIGHT*0.5);
		Drawmanager.DrawMidText("3. 나가기", WIDTH, HEIGHT*0.5 + 2);
		Select = Drawmanager.DrawCursor(3, WIDTH*0.5 - 6, HEIGHT*0.5 - 2);
		cout << Select;
		switch (Select)
		{
		case 1:
			Drawmanager.Drawinterface();
			//Intro();
			m_sName=Getname();
			Gameplay(1);
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
	int max;
	ifstream load;
	string *str;
	load.open("베네치아_스토리.txt");
	load >> max;
	str = new string[max + 1];
	for (int i=0;!load.eof();i++)
	{
		getline(load, str[i]);
		if (i + 1 == max)
			str[i] = " ";
	}
	Introchange(str, 0);

}

void Play::Introchange(string str[],int num)
{
	if (str[num] == " ")
		return;
	for (int i = 0; i <= num; i++)
	{
		if (i >= 12)
		{
			for (int j = i-12, k=0 ; k < 12; j++,k++)
			{
				Drawmanager.DrawMidText("                                       ", WIDTH, HEIGHT*0.5 - 7 + k);
				Drawmanager.DrawMidText(str[j+1], WIDTH, HEIGHT*0.5 - 7 + k);
			}
			continue;
		}
		Drawmanager.DrawMidText(str[i], WIDTH, HEIGHT*0.5 - 7 + i);
	}
	Sleep(100);
	Introchange(str, ++num);
}

string Play::Getname()
{
	char tmp[11] = {NULL};
	int num=0;
	char ch;
	Drawmanager.Drawinterface();
	Drawmanager.DrawSmallBox(23, HEIGHT*0.5 + 3, 15, 3);
	Drawmanager.DrawMidText("이름 입력(영문,10글자 이하)", WIDTH, HEIGHT*0.5 + 2);
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
		Drawmanager.DrawMidText("                    ", WIDTH, HEIGHT*0.5 + 4);
		Drawmanager.DrawMidText(tmp, WIDTH, HEIGHT*0.5 + 4);
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
	Drawmanager.DrawMidText("                    ", WIDTH, HEIGHT*0.5 + 4);
	Drawmanager.DrawMidText(m_cWord, WIDTH, HEIGHT*0.5 + 4);

	return false;
}

void Play::Gameplay(int stage)
{
	int Effect;
	int TimeCounter = 0;
	int StopCounter = 0;
	int BlindCounter = 0;
	int Curclock, Wordclock;
	int wordlength=0;
	int loseheart=0;
	int Score=0;
	int Gamespeed=0;
	char tmp[20];
	char ch;
	sprintf(tmp, "%d stage", stage);
	Drawmanager.Drawinterface(m_sName);
	Drawmanager.DrawMidText(tmp, WIDTH, HEIGHT*0.5);
	Sleep(1000);
	Drawmanager.DrawMidText("       ", WIDTH, HEIGHT*0.5);
	Sleep(1000);
	Wordclock = clock();
	while (true)
	{
		Curclock = clock();
		if (kbhit())
		{
			if (GetWord())
			{
				Effect=Word::HitWord(m_cWord,&wordlength);
				for (int i = 0; i < 11; i++)
					m_cWord[i] = NULL;
				Drawmanager.DrawMidText("                    ", WIDTH, HEIGHT*0.5 + 4);
				if (Effect == SLOW)
				{
					Gamespeed = 500;
					TimeCounter = 4;
				}
				else if (Effect == FAST)
				{
					Gamespeed = -500;
					TimeCounter = 4 ;
				}
				else if (Effect == STOP)
					StopCounter = 4;
				else if (Effect == BLIND)
				{
					BlindCounter = 4;
				}
				if (wordlength != 0)
				{
					Score += wordlength * 10;
					Drawmanager.DrawScore(Score);
				}
				if (Score >= 10000)
				{
					Drawmanager.DrawMidText("STAGE CLEAR!!",WIDTH,HEIGHT*0.5);
					system("pause");
					Word::WordReset();
					return;
				}
			}
		}
		if (Curclock - Wordclock >= 700 + Gamespeed)
		{
			if (StopCounter == 0)
			{
				loseheart = Word::Dropword(BlindCounter);
				if (loseheart != 0)
				{
					m_iHeart -= loseheart;
					Drawmanager.DrawHeart(m_iHeart);
					loseheart = 0;
					if (m_iHeart <= 0)
					{
						Drawmanager.DrawMidText("STAGE FAIL", WIDTH, HEIGHT*0.5);
						system("pause");
						Word::WordReset();
						m_iHeart = 9;
						return;
					}
				}
				Word::Makeword(BlindCounter);
			}
			else
				StopCounter--;
			Wordclock = Curclock;
			if (TimeCounter != 0)
			{
				TimeCounter--;
				if (TimeCounter == 0)
					Gamespeed = 0;
			}
		}
	}
}

Play::~Play()
{
}

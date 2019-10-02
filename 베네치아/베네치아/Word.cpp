#include "Word.h"



Word::Word()
{
	m_iWordmax = 0;
	m_wDroppingword = NULL;
	Getdata();
}

void Word::Getdata()
{
	ifstream load;
	load.open("Word.txt");
	load >> m_iMax;
	m_sWordlist = new string[m_iMax];
	for (int i=0;!load.eof();i++)
	{
		load >> m_sWordlist[i];
	}
	load.close();
}


void Word::Makeword()
{
	Wordtree *Add;
	int num[3] = {NULL};
	int tmp;
	int words=0;
	int overlapcheck[2][2] = { NULL };
	int effectchance;

	int chance = rand() % 100;//단어 생성 갯수 설정
	if (chance <= 7)
		words = 3;
	else if (chance <= 15)
		words = 2;
	else if (chance <= 30)
		words = 1;
	else
		return;

	for (int i = 0; i < words; i++)
	{
		num[i] = rand() % m_iMax;
	}

	for (int i=0;words != 0&&i<3;i++)
	{
		tmp = rand() % WIDTH;
		if (tmp + m_sWordlist[num[i]].length() <WIDTH&&tmp>0)
		{
			if (overlapcheck[0][0] != NULL || overlapcheck[0][1] != NULL)//첫번째 단어와 겹치지 않게 좌표 설정
			{
				if (tmp + m_sWordlist[num[i]].length() >= overlapcheck[0][0] && tmp <= overlapcheck[0][1])
				{
					--i;
					continue;
				}
			}
			if (overlapcheck[1][0] != NULL || overlapcheck[1][1] != NULL)//두번째 단어와 겹치지 않게 좌표 설정
			{
				if (tmp + m_sWordlist[num[i]].length() >= overlapcheck[1][0] && tmp <= overlapcheck[1][1])
				{
					i--;
					continue;
				}
			}
			Add = new Wordtree();
			Add->word = m_sWordlist[num[i]];
			Add->Xcoordinate = tmp;
			Add->Ycoordinate = 1;
			if (rand() % 100 < 10)//특수효과 설정
			{
				effectchance = rand() % 3;
				Add->effect = effectchance + 1;
			}
			else
				Add->effect = NULL;
			if (m_iWordmax == 0)//첫번째 단어 그리기
			{
				m_wDroppingword = Add;
				m_wTmp = m_wDroppingword;
				if (m_wTmp->effect != NULL)
				{
					YELLOW
						Drawmanager.DrawPoint(m_wTmp->word, m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
					ORIGINAL
				}
				else
				Drawmanager.DrawPoint(m_wTmp->word, m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
				m_iWordmax++;
				words--;
			}
			else//단어 그리기
			{
				m_wTmp = m_wDroppingword;
				while (m_wTmp->next != NULL)
					m_wTmp = m_wTmp->next;
				m_wTmp->next = Add;
				m_iWordmax++;
				words--;
				m_wTmp = m_wTmp->next;
				if (m_wTmp->effect != NULL)
				{
					YELLOW
						Drawmanager.DrawPoint(m_wTmp->word, m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
					ORIGINAL
				}
				else
				Drawmanager.DrawPoint(m_wTmp->word, m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
			}
			if (i == 0)
			{
				overlapcheck[0][0] = tmp;//첫째 단어 시작좌표
				overlapcheck[0][1] = tmp + m_sWordlist[num[i]].length();//첫째 단어 끝좌표

			}
			else if (i == 1)
			{
				overlapcheck[1][0] = tmp;
				overlapcheck[1][1] = tmp+ m_sWordlist[num[i]].length();

			}
		}
	}
	Drawmanager.gotoxy(WIDTH, HEIGHT*0.5 + 7);

}

int Word::Dropword()
{
	int Dropcheck = 0;
	int length = 0;
	m_wTmp = m_wDroppingword;
	for (int i=0;i<m_iWordmax;i++)
	{
		if (m_wTmp->Ycoordinate >= HEIGHT * 0.5 + 5 && m_wTmp->Ycoordinate <= HEIGHT * 0.5 + 7)
		{
			if (m_wTmp->Ycoordinate == HEIGHT * 0.5 + 5)
				EraseWord(m_wTmp);
			if (m_wTmp->Xcoordinate + m_wTmp->word.length()>WIDTH*0.5 - 6&&m_wTmp->Xcoordinate<WIDTH*0.5+6)//입력박스 와 겹치는 단어 그리지 않기
			{
				m_wTmp->Ycoordinate++;
				m_wTmp = m_wTmp->next;
				continue;
			}
		}
		if(!(m_wTmp->Ycoordinate==HEIGHT*0.5+8&& m_wTmp->Xcoordinate + m_wTmp->word.length() > WIDTH*0.5 - 6 && m_wTmp->Xcoordinate < WIDTH*0.5 + 6))
			EraseWord(m_wTmp);
		m_wTmp->Ycoordinate++;
		if (m_wTmp->Ycoordinate >= HEIGHT-2)
		{
			Dropcheck++;
			FirstWordErase(&length);
			m_wTmp = m_wDroppingword;
		}
		else
		{
			if (m_wTmp->effect != NULL)
			{
				YELLOW
				Drawmanager.DrawPoint(m_wTmp->word, m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
				ORIGINAL
			}
			else
			Drawmanager.DrawPoint(m_wTmp->word, m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
			m_wTmp = m_wTmp->next;
		}
	}
	Drawmanager.gotoxy(WIDTH, HEIGHT*0.5 + 7);
	return Dropcheck;
}

void Word::EraseWord(Wordtree *word)
{
	Drawmanager.gotoxy(word->Xcoordinate*2, word->Ycoordinate);
	for (int i = 0; i < word->word.length(); i++)
		cout << " ";
}

int Word::HitWord(string typingword,int *wordlength)
{
	int firstcheck=1;
	Wordtree *tmpnext;
	Wordtree *tmp3;
	int effect=NULL;
	*wordlength = 0;
	if (m_wDroppingword == NULL)
		return effect;
	m_wTmp = m_wDroppingword;
	while (1)
	{
		if (m_wTmp->word == typingword)
		{
			if (firstcheck == 1)
				effect = FirstWordErase(wordlength);
			else
			{
				EraseWord(m_wTmp);
				effect = m_wTmp->effect;
				*wordlength = m_wTmp->word.length();
				if (m_wTmp->next == NULL)
					tmpnext = NULL;
				else
					tmpnext = m_wTmp->next;
				delete m_wTmp;
				m_wTmp = m_wDroppingword;
				while (1)
				{
					if (m_wTmp->next != NULL)
					{
						tmp3 = m_wTmp->next;
						if (tmp3->effect >= 0 && tmp3->effect <= STOP)
						{
							m_wTmp = m_wTmp->next;
							continue;
						}
						else
							break;
					}
					m_wTmp = m_wTmp->next;
				}
				m_wTmp->next = tmpnext;
				m_iWordmax--;
			}
			return effect;
		}
		if (m_wTmp->next == NULL)
			break;
		m_wTmp = m_wTmp->next;
		firstcheck++;
	}
	return effect;
}

int Word::FirstWordErase(int *length)
{
	Wordtree *tmp;
	int effect=0;
	EraseWord(m_wDroppingword);
	effect = m_wDroppingword->effect;
	*length = m_wDroppingword->word.length();
	if (m_wDroppingword->next != NULL)
	{
		tmp = m_wDroppingword->next;
	}
	else
		tmp = NULL;
	delete m_wDroppingword;
	m_wDroppingword = tmp;
	m_iWordmax--;
	return effect;
}

void Word::WordReset()
{
	if(m_wDroppingword->next!=NULL)
		WordReset(m_wDroppingword->next);
	delete m_wDroppingword;
	m_iWordmax = 0;
}

void Word::WordReset(Wordtree *word)
{
	if (word->next != NULL)
		WordReset(word->next);
	else
	{
		delete word;
		return;
	}
	delete word;
}

Word::~Word()
{
	delete[] m_sWordlist;

}

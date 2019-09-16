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

	int chance = rand() % 100;
	if (chance <= 5)
		words = 3;
	else if (chance <= 15)
		words = 2;
	else if (chance <= 30)
		words = 1;
	else
		return;
	//if (m_wDroppingword == NULL)
	//	m_wDroppingword = new Wordtree();

	for (int i = 0; i < words; i++)
	{
		num[i] = rand() % m_iMax;
	}
	for (int i=0;words != 0&&i<3;i++)
	{
		tmp = rand() % WIDTH;
		if (tmp + m_sWordlist[num[i]].length() <WIDTH&&tmp>0)
		{
			Add = new Wordtree();
			Add->word = m_sWordlist[num[i]];
			Add->Xcoordinate = tmp;
			Add->Ycoordinate = 1;
			if (rand() % 100 < 10)
				tmp = rand() % 4;
			else
				tmp = NULL;
			Add->effect = tmp;
			if (m_iWordmax == 0)
			{
				m_wDroppingword = Add;
				m_wTmp = m_wDroppingword;
				Drawmanager.DrawPoint(m_wTmp->word, m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
				m_iWordmax++;
				words--;
			}
			else
			{
				m_wTmp = m_wDroppingword;
				while (m_wTmp->next != NULL)
					m_wTmp = m_wTmp->next;
				m_wTmp->next = Add;
				m_iWordmax++;
				words--;
				m_wTmp = m_wTmp->next;
				Drawmanager.DrawPoint(m_wTmp->word, m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
			}
		}
	}
}

void Word::Dropword()
{
	m_wTmp = m_wDroppingword;
	for (int i=0;i<m_iWordmax;i++)
	{
		EraseWord(m_wTmp);
		m_wTmp->Ycoordinate++;
		Drawmanager.DrawPoint(m_wTmp->word, m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
		m_wTmp = m_wTmp->next;
	}
}

void Word::EraseWord(Wordtree *word)
{
	Drawmanager.gotoxy(word->Xcoordinate*2, word->Ycoordinate);
	for (int i = 0; i < word->word.length(); i++)
		cout << " ";
}

int Word::HitWord(string typingword)
{
	int firstcheck=1;
	Wordtree *tmp2;
	Wordtree *tmp3;
	int effect=NULL;
	if (m_wDroppingword == NULL)
		return effect;
	m_wTmp = m_wDroppingword;
	while (1)
	{
		if (m_wTmp->word == typingword)
		{
			EraseWord(m_wTmp);
			effect = m_wTmp->effect;
			if (m_wTmp->next == NULL)
				tmp2 = NULL;
			else
				tmp2 = m_wTmp->next;
			delete m_wTmp;
			if (firstcheck == 1)
				m_wDroppingword = tmp2;
			m_wTmp = m_wDroppingword;

			while (1)//do while 확인, 넥스트가 널이면 반복문 진입 X
			{
				if (m_wTmp->next != NULL)
				{
					tmp3 = m_wTmp->next;
					if (tmp3->effect >= 0 && tmp3->effect <= BLIND)
					{
						m_wTmp = m_wTmp->next;
						continue;
					}
					else
						break;
				}
				m_wTmp = m_wTmp->next;
			}
			m_wTmp->next = tmp2;
			m_iWordmax--;
			return effect;
		}
		if (m_wTmp->next == NULL)
			break;
		m_wTmp = m_wTmp->next;
		firstcheck++;
	}
	return effect;
}


Word::~Word()
{
	delete[] m_sWordlist;

}

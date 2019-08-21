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
	if(m_wDroppingword==NULL)
	m_wDroppingword = new Wordtree();

	int chance = rand() % 100;
	if (chance <= 3)
		words = 3;
	else if (chance <= 10)
		words = 2;
	else if (chance <= 50)
		words = 1;
	for (int i = 0; i < words; i++)
	{
		num[i] = rand() % m_iMax;
	}
	m_wTmp = m_wDroppingword;
	while (m_wTmp->next != NULL)
		m_wTmp = m_wTmp->next;
	for (int i=0;words != 0&&i<3;i++)
	{
		tmp = rand() % WIDTH;
		if (tmp + m_sWordlist[num[i]].length() <WIDTH&&tmp>0)
		{
			Add = new Wordtree();
			Add->word = m_sWordlist[num[i]];
			Add->Xcoordinate = tmp;
			Add->Ycoordinate = 1;
			Add->number = m_iWordmax;
			if (rand() % 100 < 10)
				tmp = rand() % 4;
			else
				tmp = NULL;
			Add->effect = tmp;
			if (m_iWordmax == 0)
				m_wDroppingword = Add;
			else
			m_wTmp->next = Add;
			m_iWordmax++;
			words--;
			Drawmanager.DrawPoint(m_wTmp->word,m_wTmp->Xcoordinate, m_wTmp->Ycoordinate);
			m_wTmp = m_wTmp->next;
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

void Word::GetWord(string typingword)
{
	if (m_wDroppingword == NULL)
		return;
	m_wTmp = m_wDroppingword;
	int i = 0;
	while (1)
	{
		if (m_wTmp->word == typingword)
		{
			m_w[i].word = m_wTmp->word;//����
			tmp[i++].Ycoordinate = m_wTmp->Ycoordinate;
		}
		if (m_wTmp->next == NULL)
			break;
		m_wTmp = m_wTmp->next;
	}
	if(i>=2)

	else

}


Word::~Word()
{
	delete[] m_sWordlist;

}

#include "Word.h"



Word::Word()
{
	Getdata();
}

void Word::Getdata()
{
	ifstream load;
	load.open("Word.txt");
	load >> m_iMax;
	Wordlist = new Wordstat[m_iMax];
	for (int i=0;!load.eof();i++)
	{
		load >> Wordlist[i].word;
		Wordlist[i].coordinate = NULL;
	}
	load.close();
}


void Word::Makeword()
{
	int num[3] = {NULL};
	int tmp;
	int words=0;
	int chance = rand() % 100;
	if (chance <= 3)
		words = 3;
	else if (chance <= 10)
		words = 2;
	else if (chance <= 20)
		words = 1;
	for (int i = 0; i < words; i++)
	{
		num[i] = rand() % m_iMax;
	}

	for (int i=0;words != 0||i<3;i++)
	{
		tmp = rand() % WIDTH;
		if (tmp + Wordlist[num[i]].word.length() <WIDTH&&tmp>0)
		{
			Wordlist[num[i]].coordinate = rand() % WIDTH;
			words--;
		}
	}
}


void Word::Dropword()
{
}


Word::~Word()
{
	delete[]Wordlist;

}

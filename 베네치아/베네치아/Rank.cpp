#include "Rank.h"



Rank::Rank()
{
}

void Rank::Showrank()
{
	int max = 0;
	int tmp;
	ifstream load;
	string str;
	string *namelist;
	int *stagelist;
	int *scorelist;
	load.open("Rank.txt");
	for (; !load.eof(); max++)//맥스값 찾기
	{
		getline(load, str);
	}
	max--;
	load.close();
	load.open("Rank.txt");

	namelist = new string[max];
	stagelist = new int[max];
	scorelist = new int[max];

	for (int i = 0; i < max; i++)
	{
		load>> namelist[i];
		load >> stagelist[i];
		load >> scorelist[i];
	}
	load.close();

	for (int i = 0; i < max-1; i++)//스테이지 기준 정렬
	{
		for (int j = i + 1; j < max; j++)
		{
			if (stagelist[i] < stagelist[j])
			{
				str = namelist[i];
				namelist[i] = namelist[j];
				namelist[j] = str;
				tmp = stagelist[i];
				stagelist[i] = stagelist[j];
				stagelist[j] = tmp;
				tmp = scorelist[i];
				scorelist[i] = scorelist[j];
				scorelist[j] = tmp;
			}
		}
	}

	for (int i = 0; i < max - 1; i++)//스코어 기준 정렬
	{
		for (int j = i + 1; j < max; j++)
		{
			if (scorelist[i] < scorelist[j] && stagelist[i] == stagelist[j])
			{
				str = namelist[i];
				namelist[i] = namelist[j];
				namelist[j] = str;
				tmp = stagelist[i];
				stagelist[i] = stagelist[j];
				stagelist[j] = tmp;
				tmp = scorelist[i];
				scorelist[i] = scorelist[j];
				scorelist[j] = tmp;
			}
		}
	}

	system("cls");
	Drawmanager.DrawBox();
	YELLOW
	Drawmanager.DrawTextWithBox("   Ranking   ",WIDTH,5);
	GREEN
	for (int i = 2; i < (WIDTH-1)*2; i++)
	{
		Drawmanager.gotoxy(i, 8);
		cout << "=";
	}
	ORIGINAL
	for (int i = 0,j=45; i < 10&&i<max; i++)
	{
		Drawmanager.gotoxy(j, 10 + (i * 2));
		cout << i + 1;
		Drawmanager.gotoxy(j+4, 10 + (i * 2));
		cout << namelist[i];
		Drawmanager.gotoxy(j+15, 10 + (i * 2));
		cout << stagelist[i];
		Drawmanager.gotoxy(j+25, 10 + (i * 2));
		cout << scorelist[i];
	}
	Drawmanager.gotoxy(0, HEIGHT + 3);

	system("pause");

}


Rank::~Rank()
{
}

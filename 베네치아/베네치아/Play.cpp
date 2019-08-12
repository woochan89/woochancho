#include "Play.h"



Play::Play()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, (WIDTH * 2) + 1);
	system(buf);
	Menu();

}

void Play::Menu()
{
	int Select;
	while (true)
	{
		Drawmanager.Drawinterface();
		Drawmanager.DrawTextWithBox("�� �� �� �� ġ �� �� ��", WIDTH, HEIGHT*0.2);
		Drawmanager.DrawMidText("1. ���� ����", WIDTH, HEIGHT*0.5 - 2);
		Drawmanager.DrawMidText("2. ��ŷ", WIDTH, HEIGHT*0.5);
		Drawmanager.DrawMidText("3. ������", WIDTH, HEIGHT*0.5 + 2);
		Select = Drawmanager.DrawCursor(3, WIDTH*0.5 - 6, HEIGHT*0.5 - 2);
		cout << Select;
		switch (Select)
		{
		case 1:
			Drawmanager.Drawinterface();
			//Intro();
			Getname();
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
	load.open("����ġ��_���丮.txt");
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

void Play::Getname()
{
	m_sName = "";
	char ch;
	Drawmanager.Drawinterface();
	Drawmanager.DrawSmallBox(23, HEIGHT*0.5 + 3, 15, 3);
	Drawmanager.DrawMidText("�̸� �Է�(����,10���� ����)", WIDTH, HEIGHT*0.5 + 2);
	while (true)
	{
		ch = getch();
		if (!(ch >= 'a'&&ch <= 'z') && !(ch >= 'A'&&ch <= 'Z')&&ch!=8)
			continue;
		if (ch == 8)//�齺���̽�
		{
			m_sName[m_sName.length()] = NULL;
		}
		m_sName += ch;
		Drawmanager.DrawMidText(m_sName, WIDTH, HEIGHT*0.5 + 4);
		if (m_sName.length() >= 10)
		{
			Drawmanager.DrawTextWithBox("10���� �ʰ�!!", WIDTH, HEIGHT*0.5);
			system("pause");
			break;
		}
	}

}

void Play::Gameplay(int stage)
{

}

Play::~Play()
{
}

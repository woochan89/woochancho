#pragma once
#include"Draw.h"
#define MINE 9
#define BLOCK 10
#define FLAG 11

struct Mine
{
	int X;
	int Y;
};
class Play
{
private:
	Draw Drawmanager;
	Mine *m_mList;
	int m_iCursorX, m_iCursorY;
	int m_iTable[9][9];
	int m_iLiveTable[9][9];
	int m_iMineMax;
	int m_iBlankMax;
	int m_iX;
	int m_iY;
public:
	void Setting(int level,int x,int y);
	void MakeMine(int level,int x,int y);
	void TableSetting(int x=9,int y=9);
	int ControlCursor(int width, int height, int x=1, int y=1);
	string DrawAssist(int X);
	bool CheckBlock();
	void BlankCheck(int x,int y);
	bool WinCheck();
	void Reset();
	Play();
	~Play();
};


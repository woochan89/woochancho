#pragma once
#include"Draw.h"

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
public:
	void Setting(int level,int x,int y);
	void MakeMine(int level,int x,int y);
	void ControlCursor(int x,int y);
	void CheckMine();

	void Reset();

	Play();
	~Play();
};


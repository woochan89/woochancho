#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<Windows.h>
#include<conio.h>

using namespace std;

inline void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

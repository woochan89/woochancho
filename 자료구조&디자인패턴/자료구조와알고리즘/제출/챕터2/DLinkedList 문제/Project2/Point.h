#include<stdio.h>
#include<iostream>

#ifndef _point_
#define _point_


typedef struct _point {
	int xpos;
	int ypos;
}Point;

Point InputPos(int x, int y);// ��ǥ ����

int CompPos(Point ppos, Point comp);// ��ǥ ��

void ShowPos(Point ppos);// ��ǥ ���


#endif
#include<stdio.h>
#include<iostream>

#ifndef _point_
#define _point_


typedef struct _point {
	int xpos;
	int ypos;
}Point;

Point InputPos(int x, int y);// ÁÂÇ¥ »ğÀÔ

int CompPos(Point ppos, Point comp);// ÁÂÇ¥ ºñ±³

void ShowPos(Point ppos);// ÁÂÇ¥ Ãâ·Â


#endif
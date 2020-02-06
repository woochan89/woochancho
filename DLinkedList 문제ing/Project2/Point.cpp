#include "Point.h"

Point InputPos(int x, int y)// 좌표 삽입
{
	Point newPoint;
	newPoint.xpos = x;
	newPoint.ypos = y;
	return newPoint;
}

int CompPos(Point ppos, Point comp)// 좌표 비교
{
	int num = NULL;
	if (ppos.xpos == comp.xpos && ppos.ypos != comp.ypos)//x만 같을때
		num = 1;
	else if (ppos.ypos == comp.ypos && ppos.xpos != comp.xpos)// y만 같을때
		num = 2;
	else if (ppos.ypos == comp.ypos && ppos.xpos == comp.xpos)// 둘다 같을때
		num = 3;
	return num;
}

void ShowPos(Point ppos)// 좌표 출력
{
	printf("%d, %d\n", ppos.xpos,ppos.ypos);
}
#include "Point.h"

Point InputPos(int x, int y)// ��ǥ ����
{
	Point newPoint;
	newPoint.xpos = x;
	newPoint.ypos = y;
	return newPoint;
}

int CompPos(Point ppos, Point comp)// ��ǥ ��
{
	int num = NULL;
	if (ppos.xpos == comp.xpos && ppos.ypos != comp.ypos)//x�� ������
		num = 1;
	else if (ppos.ypos == comp.ypos && ppos.xpos != comp.xpos)// y�� ������
		num = 2;
	else if (ppos.ypos == comp.ypos && ppos.xpos == comp.xpos)// �Ѵ� ������
		num = 3;
	return num;
}

void ShowPos(Point ppos)// ��ǥ ���
{
	printf("%d, %d\n", ppos.xpos,ppos.ypos);
}
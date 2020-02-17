#include"LinkedListQ.h"
#include<time.h>

#define	CUS_COME_TERM	15		// ���� �ֹ� ����: �� ����

#define CHEBUR 0
#define BULBER 1
#define DOUBER 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DOU_TERM 24

void main()
{
	LQ Q;
	int makingtime=0;
	int Cheese = 0, Bul = 0, Double = 0;

	LQinit(&Q);
	srand(time(NULL));

	for (int sec = 0; sec < 3600; sec++) {
		if (sec % CUS_COME_TERM == 0) {
			switch (rand() % 3) {
			case CHEBUR:
				Enqueue(&Q, CHE_TERM);
				Cheese++;
				break;
			case BULBER:
				Enqueue(&Q, BUL_TERM);
				Bul++;
				break;
			case DOUBER:
				Enqueue(&Q, DOU_TERM);
				Double++;
				break;
			}
		}
		if (makingtime <= 0 && Q.front != NULL)
			makingtime = Dequeue(&Q);
		makingtime--;

	}
	printf("�ܹ��� �ֹ���Ȳ\n");
	printf("ġ����� : %d��\n",Cheese);
	printf("�Ұ����� : %d��\n",Bul);
	printf("������� : %d��\n",Double);
}
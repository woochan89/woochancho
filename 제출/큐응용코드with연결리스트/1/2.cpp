#include"LinkedListQ.h"
#include<time.h>

#define	CUS_COME_TERM	15		// 고객의 주문 간격: 초 단위

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
	printf("햄버거 주문현황\n");
	printf("치즈버거 : %d개\n",Cheese);
	printf("불고기버거 : %d개\n",Bul);
	printf("더블버거 : %d개\n",Double);
}
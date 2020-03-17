#include "CircleQueue.h"
#include<stdio.h>
#include<stdlib.h>

//초기화
void QInit(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

//체크
int QIsEmpty(Queue q)
{
	if (q.front == q.rear)
		return true;
	else return false;
}

//위치조절
int NextPosIdx(int idx)
{
	if (idx + 1 == MAX)
		return 0;
	else return idx++;
}

//삽입
void Enqueue(Queue* q, Data data)
{
	if (NextPosIdx(q->rear) == q->front)
	{
		printf("큐 메모리 에러\n");
		exit(-1);
	}
	q->queueArr[q->rear] = data;
	NextPosIdx(q->rear);
}

//제거
Data Dequeue(Queue* q)
{
	if (QIsEmpty(*q))
	{
		printf("큐 메모리 에러\n");
		exit(-1);
	}
	q->front = NextPosIdx(q->front);
	return q->queueArr[q->front];
}

//픽
Data QPeek(Queue* q)
{
	if (QIsEmpty(*q))
	{
		printf("큐 메모리 에러\n");
		exit(-1);
	}
	return q->queueArr[NextPosIdx(q->front)];

}
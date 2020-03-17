#include "CircleQueue.h"
#include<stdio.h>
#include<stdlib.h>

//�ʱ�ȭ
void QInit(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

//üũ
int QIsEmpty(Queue q)
{
	if (q.front == q.rear)
		return true;
	else return false;
}

//��ġ����
int NextPosIdx(int idx)
{
	if (idx + 1 == MAX)
		return 0;
	else return idx++;
}

//����
void Enqueue(Queue* q, Data data)
{
	if (NextPosIdx(q->rear) == q->front)
	{
		printf("ť �޸� ����\n");
		exit(-1);
	}
	q->queueArr[q->rear] = data;
	NextPosIdx(q->rear);
}

//����
Data Dequeue(Queue* q)
{
	if (QIsEmpty(*q))
	{
		printf("ť �޸� ����\n");
		exit(-1);
	}
	q->front = NextPosIdx(q->front);
	return q->queueArr[q->front];
}

//��
Data QPeek(Queue* q)
{
	if (QIsEmpty(*q))
	{
		printf("ť �޸� ����\n");
		exit(-1);
	}
	return q->queueArr[NextPosIdx(q->front)];

}
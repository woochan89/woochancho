#ifndef _CIRCLE_QUEUE_
#define _CIRCLE_QUEUE_
#define MAX 100

typedef int Data;
typedef struct _cQueue
{
	int front;
	int rear;
	Data queueArr[MAX];
}CQueue;

typedef CQueue Queue;

//�ʱ�ȭ
void QInit(Queue* q);

//üũ
int QIsEmpty(Queue q);

//��ġ����
int NextPosIdx(int idx);

//����
void Enqueue(Queue* q, Data data);

//����
Data Dequeue(Queue* q);

//��
Data QPeek(Queue* q);

#endif // !_CIRCLE_QUEUE_

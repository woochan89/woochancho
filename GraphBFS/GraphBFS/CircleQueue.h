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

//초기화
void QInit(Queue* q);

//체크
int QIsEmpty(Queue q);

//위치조절
int NextPosIdx(int idx);

//삽입
void Enqueue(Queue* q, Data data);

//제거
Data Dequeue(Queue* q);

//픽
Data QPeek(Queue* q);

#endif // !_CIRCLE_QUEUE_

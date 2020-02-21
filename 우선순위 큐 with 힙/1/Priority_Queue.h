#ifndef _PRIORITYQUEUE_
#define _PRIORITYQUEUE_
#define HEAP_LEN 100

#include<iostream>

typedef char HData;
typedef int Priority;

typedef struct _heapElem {
	Priority pr;
	HData data;
}HeapElem;

typedef struct _heap {
	int numOfdata;
	HeapElem heapArr[HEAP_LEN];
}Heap;

//�ʱ�ȭ
void Heapinit(Heap *ph);

//��Ƽüũ
bool EmptyCheck(Heap *ph);

//������ ����
void Hinsert(Heap *ph, HData data, Priority pr);

//������ȸ ���
void Hprint(Heap *ph);

//������ ����
HData HDelete(Heap *ph);

//���� ã��
int GetHiPriChildIDX(Heap * ph, int idx);

//�θ� ����� �ε��� ���� ��ȯ
int GetParentIdx(int idx);

//���� �ڽ��� �ε��� ���� ��ȯ
int GetLChildIdx(int idx);

//������ �ڽ��� �ε��� ���� ��ȯ
int GetRChildIdx(int idx);

//�ΰ��� �ڽ� ��� �� ���� �켱������ �ڽĳ�� �ε��� ���� ��ȯ
int GetHiPriChildIdx(Heap* ph, int idx);
#endif // !_PRIORITY_QUEUE_

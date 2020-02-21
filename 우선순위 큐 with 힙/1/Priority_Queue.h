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

//초기화
void Heapinit(Heap *ph);

//엠티체크
bool EmptyCheck(Heap *ph);

//데이터 삽입
void Hinsert(Heap *ph, HData data, Priority pr);

//레벨순회 출력
void Hprint(Heap *ph);

//데이터 삭제
HData HDelete(Heap *ph);

//꼬리 찾기
int GetHiPriChildIDX(Heap * ph, int idx);

//부모 노드의 인덱스 값을 반환
int GetParentIdx(int idx);

//왼쪽 자식의 인덱스 값을 반환
int GetLChildIdx(int idx);

//오른쪽 자식의 인덱스 값을 반환
int GetRChildIdx(int idx);

//두개의 자식 노드 중 높은 우선순위의 자식노드 인덱스 값을 반환
int GetHiPriChildIdx(Heap* ph, int idx);
#endif // !_PRIORITY_QUEUE_

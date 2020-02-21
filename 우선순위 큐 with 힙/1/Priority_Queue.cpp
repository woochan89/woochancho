#include "Priority_Queue.h"

//초기화
void Heapinit(Heap *ph) {
	ph->numOfdata = 0;
}

//엠티체크
bool EmptyCheck(Heap *ph) {
	int num = (ph->numOfdata == 0) ? 1 : 0;
	return num;
}

//데이터 삽입
void Hinsert(Heap *ph, HData data, Priority pr) {
	int idx = ph->numOfdata + 1;
	HeapElem newElem = { pr,data };

	while (idx != 1) {
		if (pr < ph->heapArr[GetParentIdx(idx)].pr) {
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else break;
	}
	ph->heapArr[idx] = newElem;
	ph->numOfdata++;
}

//레벨순회 출력
void Hprint(Heap *ph) {
	while()
}


//꼬리찾기
int GetHiPriChildIDX(Heap * ph, int idx) {
	if (GetLChildIdx(idx) > ph->numOfdata)
		return 0;
	else if (GetLChildIdx(idx) == ph->numOfdata)
		return GetLChildIdx(idx);
	else
		if (ph->heapArr[GetLChildIdx(idx)].pr > ph->heapArr[GetRChildIdx(idx)].pr)
			return GetRChildIdx(idx);
		else return GetLChildIdx(idx);
}

//삭제
HData HDelete(Heap* ph) {
	HData retData = ph->heapArr[1].data;
	HeapElem lastElem = ph->heapArr[ph->numOfdata];

	int parentidx = 1;
	int childidx;

	while (childidx = GetHiPriChildIDX(ph, parentidx)) {
		if (lastElem.pr <= ph->heapArr[childidx].pr)
			break;
		ph->heapArr[parentidx] = ph->heapArr[childidx];
		parentidx = childidx;
	}

	ph->heapArr[parentidx] = lastElem;
	ph->numOfdata--;
	return retData;
}



//부모 노드의 인덱스 값을 반환
int GetParentIdx(int idx) {
	return idx / 2;
}

//왼쪽 자식의 인덱스 값을 반환
int GetLChildIdx(int idx) {
	return idx * 2;
}

//오른쪽 자식의 인덱스 값을 반환
int GetRChildIdx(int idx) {
	return GetLChildIdx(idx) + 1;
}

//두개의 자식 노드 중 높은 우선순위의 자식노드 인덱스 값을 반환
int GetHiPriChildIdx(Heap* ph, int idx) {
	int num = (ph->heapArr[idx / 2].pr >= ph->heapArr[idx / 2 + 1].pr) ? idx / 2 : idx / 2 + 1;
	return num;
}


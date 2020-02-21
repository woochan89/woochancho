#include "Priority_Queue.h"

//�ʱ�ȭ
void Heapinit(Heap *ph) {
	ph->numOfdata = 0;
}

//��Ƽüũ
bool EmptyCheck(Heap *ph) {
	int num = (ph->numOfdata == 0) ? 1 : 0;
	return num;
}

//������ ����
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

//������ȸ ���
void Hprint(Heap *ph) {
	while()
}


//����ã��
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

//����
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



//�θ� ����� �ε��� ���� ��ȯ
int GetParentIdx(int idx) {
	return idx / 2;
}

//���� �ڽ��� �ε��� ���� ��ȯ
int GetLChildIdx(int idx) {
	return idx * 2;
}

//������ �ڽ��� �ε��� ���� ��ȯ
int GetRChildIdx(int idx) {
	return GetLChildIdx(idx) + 1;
}

//�ΰ��� �ڽ� ��� �� ���� �켱������ �ڽĳ�� �ε��� ���� ��ȯ
int GetHiPriChildIdx(Heap* ph, int idx) {
	int num = (ph->heapArr[idx / 2].pr >= ph->heapArr[idx / 2 + 1].pr) ? idx / 2 : idx / 2 + 1;
	return num;
}


#include <stdio.h>
#include<iostream>
#include "CLinkedList.h"

int main(void)
{
	List list;
	Data data;

	//�ʱ�ȭ
	ListInit(&list);

	//����
	LInsertFront(&list, 1);
	LInsertFront(&list, 2);
	LInsertFront(&list, 3);
	LInsertFront(&list, 4);
	LInsertFront(&list, 5);

	//���� �� ���
	LFirst(&list, &data);
	do
	{
		printf("%d\n", LRemove(&list));
		LNext(&list, &data);
	} while (list.numOfData != 0);


	return 0;
}
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
	while ()
	{
		std::cout << LRemove(&list) << std::endl;
	}

	return 0;
}
#include"dbLinkedList.h"

int main()
{
	List list;
	Data data;

	//초기화
	ListInit(&list);
	//입력
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	//출력
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		while (LNext(&list, &data)) 
			printf("%d\n", data);
		printf("\n");
	}
	//삭제
	if (LFirst(&list, &data)) {
		if(data % 2 == 0)
		LRemove(&list);
		while (LNext(&list, &data))
			if (data % 2 == 0)
				LRemove(&list);
	}
	//출력
	printf("2배수를 제거후 출력\n");
	if (LFirst(&list, &data)) {
		printf("%d\n", data);
		while (LNext(&list, &data))
			printf("%d\n", data);
		printf("\n");
	}
	//할당해제
	Node *dNode = list.head;
	Node *dnNode = list.head->next;
	free(list.head);
	while (dnNode != NULL && dnNode != list.tail) {
		dNode = dnNode;
		dnNode = dnNode->next;
		free(dNode);
	}
	free(list.tail);




	return 0;
}
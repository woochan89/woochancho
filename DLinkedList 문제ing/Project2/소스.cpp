#include"DLinkedList.h"

int main()
{
	List list;
	Point tmp;
	Point comp;

	init(&list);//초기화

	for (int i = 1; i <= 5; i++) {//리스트에 데이터 삽입
		tmp = InputPos(i, i + 1);
		InputData(&list, tmp);
	}

	printf("데이터 갯수 : %d\n", list.numOfdata);//데이터 출력
	if (Lfirst(&list, &tmp))//numOfdata가 0이 아니라면 실행
	{
		ShowPos(tmp);
		while (Lnext(&list, &tmp))
			ShowPos(tmp);
	}

	//데이터 삭제
	printf("x가 2인 모든 데이터 삭제\n");
	if (Lfirst(&list, &tmp))//numOfdata가 0이 아니라면 실행
	{
		comp = InputPos(2, 0);
		if (CompPos(tmp, comp) == 1 || CompPos(tmp, comp) == 3)
		{
			Lremove(&list, &tmp);
			printf("%d, %d 삭제\n", tmp.xpos, tmp.ypos);
		}
		while (Lnext(&list, &tmp))
		{
			if (CompPos(tmp, comp) == 1 || CompPos(tmp, comp) == 3)
			{
				Lremove(&list, &tmp);
				printf("%d, %d 삭제\n", tmp.xpos, tmp.ypos);
			}
		}
	}
	printf("남은 데이터 갯수 : %d\n", list.numOfdata);

	Node *dNode = list.head->next;
	Node *dnNode = list.head->next->next;
	delete list.head;
	delete dNode;
	while (dnNode!=NULL)
	{
		dNode = dnNode;
		dnNode = dnNode->next;
		delete dNode;
	}

	return 0;
}
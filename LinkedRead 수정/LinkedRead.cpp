#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

typedef struct _list
{
	Node *head;
	Node *tail;
	Node *cur;
	int numOfdata;
}List;

void Linit(List *list)
{
	list->head = new Node;
	list->head->next = NULL;
	list->cur = NULL;
	list->numOfdata = 0;
}

void Linsert(List *list, int data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list->head->next;
	if (list->numOfdata == 0)
		list->tail = newNode;
	list->head->next = newNode;
	list->numOfdata++;
}


int main(void)
{
	List list;
	Node * newNode = NULL;
	int readData;

	Linit(&list);

	/**** 데이터를 입력 받는 과정 ****/
	while (1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;
		Linsert(&list, readData);
	}
	printf("\n");

	/**** 입력 받은 데이터의 출력과정 ****/
	printf("입력 받은 데이터의 전체출력! \n");
	if (list.head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		list.cur = list.head->next;
		printf("%d  ", list.cur->data);   // 첫 번째 데이터 출력

		while (list.cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			list.cur = list.cur->next;
			printf("%d  ", list.cur->data);
		}
	}
	printf("\n\n");

	/**** 메모리의 해제과정 ****/
	if (list.head == NULL)
	{
		return 0;    // 해제할 노드가 존재하지 않는다.
	}
	else
	{
		Node * delNode = list.head;
		Node * delNextNode = list.head->next;

		printf("더미 노드를 삭제합니다. \n");
		free(delNode);    // 더미 노드의 삭제

		while (delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}

	system("pause");

	return 0;
}
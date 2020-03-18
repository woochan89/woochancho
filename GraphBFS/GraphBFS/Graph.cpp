#include "Graph.h"
#include<iostream>

//�ʱ�ȭ
void GraphInit(Graph* g, int nv)
{
	g->edgeList = (List*)malloc(sizeof(List)*nv);
	g->numE = 0;
	g->numV = nv;
	for (int i = 0; i < nv; i++)
	{
		ListInit(&g->edgeList[i]);
		SetSortRule(&g->edgeList[i], WhoIsPrecede);
	}
	g->visitInfo = (bool*)malloc(sizeof(bool)*nv);
	memset(g->visitInfo, 0, sizeof(int)*nv);
}

//�Ҵ� ����
void GraphDestroy(Graph* g)
{
	if (g->edgeList != NULL)
		free(g->edgeList);
	if (g->visitInfo != NULL)
		free(g->visitInfo);

}

//���� ����
void AddEdge(Graph* g, int fromV, int toV)
{
	LInsert(&g->edgeList[fromV], toV);
	LInsert(&g->edgeList[toV], fromV);
	g->numE++;
}

//���� ���� ���
void ShowEdge(Graph* g)
{
	int vx;

	for (int i = 0; i < g->numV; i++)
	{
		printf("%c�� ����� ����: ", i + 65);

		if (LFirst(&(g->edgeList[i]), vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(g->edgeList[i]), vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}

}



//���� ���� ���
void BFSshowGraphVertex(Graph* g, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	QInit(&queue);

	VisitVertex(g, visitV);

	while (LFirst(&(g->edgeList[visitV]), nextV) == true)
	{
		if (VisitVertex(g, nextV) == true)
			Enqueue(&queue, nextV);

		while (LNext(&(g->edgeList[visitV]), nextV) == true)
		{
			if (VisitVertex(g, nextV) == true)
				Enqueue(&queue, nextV);
		}

		if (QIsEmpty(queue))    // ť�� ��� BFS ����
			break;
		else
			visitV = Dequeue(&queue);
	}

	// Ž�� ���� �ʱ�ȭ
	memset(g->visitInfo, 0, sizeof(int) * g->numV);

}

int VisitVertex(Graph * g, int visitV)
{
	if (g->visitInfo[visitV] == 0)
	{
		g->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);    // �湮 ���� ���
		return true;
	}

	return false;
}

//���Լ�
int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

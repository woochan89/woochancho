#include "Graph.h"
#include<iostream>

//초기화
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

//할당 해제
void GraphDestroy(Graph* g)
{
	if (g->edgeList != NULL)
		free(g->edgeList);
	if (g->visitInfo != NULL)
		free(g->visitInfo);

}

//간선 연결
void AddEdge(Graph* g, int fromV, int toV)
{
	LInsert(&g->edgeList[fromV], toV);
	LInsert(&g->edgeList[toV], fromV);
	g->numE++;
}

//간선 정보 출력
void ShowEdge(Graph* g)
{
	int vx;

	for (int i = 0; i < g->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);

		if (LFirst(&(g->edgeList[i]), vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(g->edgeList[i]), vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}

}



//정점 정보 출력
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

		if (QIsEmpty(queue))    // 큐가 비면 BFS 종료
			break;
		else
			visitV = Dequeue(&queue);
	}

	// 탐색 정보 초기화
	memset(g->visitInfo, 0, sizeof(int) * g->numV);

}

int VisitVertex(Graph * g, int visitV)
{
	if (g->visitInfo[visitV] == 0)
	{
		g->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);    // 방문 정점 출력
		return true;
	}

	return false;
}

//비교함수
int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

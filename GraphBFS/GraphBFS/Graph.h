#ifndef _GRAPH_드
#define _GRAPH_
#include"LinkedList.h"
#include"CircleQueue.h"

enum
{
	A=0,B,C,D,E,F,G,H,I,J
};

typedef struct _graph
{
	int numV;
	int numE;
	List *edgeList;
	bool *visitInfo;
}Graph;

//초기화
void GraphInit(Graph* g, int nv);

//할당 해제
void GraphDestroy(Graph* g);

//간선 연결
void AddEdge(Graph* g, int fromV, int toV);

//간선 정보 출력
void ShowEdge(Graph* g);

//정점 정보 출력
void BFSshowGraphVertex(Graph* g, int startV);
int VisitVertex(Graph * g, int visitV);

//비교함수
int WhoIsPrecede(int data1, int data2);


#endif // !_GRAPH_

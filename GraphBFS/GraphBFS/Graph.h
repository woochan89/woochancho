#ifndef _GRAPH_
#define _GRAPH_

#define NAME_LEN 30
#include"LinkedList.h"
#include"CircleQueue.h"


typedef struct _graph
{
	int numV;
	int numE;
	//char **name;
	List NameList;
	List *edgeList;
	bool *visitInfo;
}Graph;

int GetIDX(Graph* g, int visitV);


void VertexInit(Graph* g);

//초기화
void GraphInit(Graph* g);

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

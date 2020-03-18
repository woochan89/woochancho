#include <stdio.h>
#include "Graph.h"

int main(void)
{
	Graph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowEdge(&graph);

	BFSshowGraphVertex(&graph, A); printf("\n");
	BFSshowGraphVertex(&graph, C); printf("\n");
	BFSshowGraphVertex(&graph, E); printf("\n");
	BFSshowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
	return 0;
}
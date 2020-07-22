#include "headers.h"

Graph* addEdge(unsigned int id, unsigned int start, unsigned int end, int weight, Graph* g) {
	g->edges[id].start = start;
	g->edges[id].end = end;
	g->edges[id].weight = weight;
	return g;
}

void readEdges(Graph* g) {
	printf("Describe a graph by entering %d edges in format: START END WEIGHT\n",g->E);
	for (unsigned int i = 0; i < g->E; i++) {
		unsigned int v, u;
		int d;
		scanf("%d%d%d", &v, &u, &d);
		addEdge(i, v, u, d, g);
	}
}

int search(unsigned int a, unsigned int b, int* d, Graph* g) {
	for (unsigned int i = 0; i < g->V; i++)
		d[i] = INT_MAX;
	//marking distance to all vertexes as infinity (INT_MAX)

	d[a] = 0; //distance to "a" vertex is marked as 0

	for (unsigned int i = 1; i <= g->V - 1; i++) {
		for (unsigned int j = 0; j < g->E; j++) {
			unsigned int start, end;
			int weight;
			weight = g->edges[j].weight;
			start = g->edges[j].start;
			end = g->edges[j].end;
			if (d[start] != INT_MAX && d[start] + weight < d[end])
				d[end] = d[start] + weight;
		}
	}
	for (unsigned int i = 0; i < g->E; i++) {
		unsigned int start, end;
		int weight;
		weight = g->edges[i].weight;
		start = g->edges[i].start;
		end = g->edges[i].end;
		if (d[start] != INT_MAX && d[end] > d[start] + weight) {
			return -2; //negative cycle detected
		}
	}
	if (d[b] != INT_MAX)
		return 0; //result ok
	else if (d[b] == INT_MAX)
		return -1; //disconnection between considered vertices
	return 1; //no result, error
}
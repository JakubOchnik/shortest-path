#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

/*
	A simple C program which finds the length of a shortest path between two vertices of a directed graph.
	It uses a simple implementation of the Bellman-Ford algorithm.
	AUTHOR: Jakub Ochnik
	CONTACT: jakub.ochnik1@gmail.com
*/

int main() {
	printf("--The shortest weighted path (Bellman-Ford algorithm)--\n");
	printf("--Author: Jakub Ochnik--\n");
	unsigned int n, m, t;
	/*
		n -> number of vertices (V)
		m -> number of edges (E)
	*/
	printf("Enter a number of vertices and a number of edges (separated by whitespace):\n");
	scanf("%d%d", &n, &m);
	Graph g;
	g.E = m;
	g.V = n;
	g.edges = (Edge*)malloc(m * sizeof(Edge));
	readEdges(&g);
	printf("Enter a number of problems to solve:\n");
	scanf("%d", &t);
	for (unsigned int i = 0; i < t; i++) {
		int* dist = (int*)malloc((g.V) * sizeof(int));
		unsigned int a, b;
		printf("Enter start and finish vertices (separated by whitespace):\n");
		scanf("%d %d", &a, &b);
		printf("Result:\n");
		switch (search(a, b, dist, &g)) {
		case 0:
			printf("%d\n", dist[b]);
			break;
		case -1:
			printf("!\n");
			break;
		case -2:
			printf("-inf\n");
			break;
		case 1:
			printf("err\n");
			break;
		}
		free(dist);
	}
	return 0;
}
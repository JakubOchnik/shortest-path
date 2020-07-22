#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "graphDef.h"

Graph* addEdge(unsigned int id, unsigned int start, unsigned int end, int val, Graph* g);
void readEdges(Graph* g);
int search(unsigned int a, unsigned int b, int* dist, Graph* g);
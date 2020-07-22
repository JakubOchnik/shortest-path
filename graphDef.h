typedef struct EdgeDef {
	int weight;
	unsigned int start, end;
}Edge;

typedef struct GraphDef {
	unsigned int V, E;
	Edge* edges;
}Graph;
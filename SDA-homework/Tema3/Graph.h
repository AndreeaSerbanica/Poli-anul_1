/*
    SERBANICA Andreea-Maria - 313CD
*/


#ifndef GRAPH_H
#define GRAPH_H

typedef struct pair {
    int v;
    int cost;
} Pair;

typedef struct list {
    Pair data;
    struct list *prev, *next;
} *List;

typedef struct graph {
    int nr_nodes;
    List *adjList;
    int *visited;
} *Graph;

Graph initGraph(int);
Graph insertEdge(Graph, int, int, int);
int getCost(Graph, int, int);
void printGraph(Graph);
void DFS(Graph, int);
Graph destroyGraph(Graph);
void Prim(Graph g, int start, int minCostArray[]);

#endif
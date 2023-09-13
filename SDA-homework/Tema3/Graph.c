/*
    SERBANICA Andreea-Maria - 313CD
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Graph.h"
#include "Utils.h"
#include "Heap.h"

#define INF 1000000

Graph initGraph(int nrNodes) {
    Graph g = (Graph)malloc(sizeof(struct graph));
    g->nr_nodes = nrNodes;
    g->adjList = (List*)calloc(nrNodes, sizeof(List));
    g->visited = calloc(nrNodes, sizeof(int));
    return g;
}

Graph insertEdge(Graph g, int u, int v, int cost) {
    Pair p;
    p.v = v;
    p.cost = cost;
    g->adjList[u] = addFirst(g->adjList[u], p);
    return g;
}

int getCost(Graph g, int u, int v) {
    List tmp = g->adjList[u];

    while (tmp != NULL) {
        if (tmp->data.v == v)
            return tmp->data.cost;
        tmp = tmp->next;
    }
    return INF;
}

void printGraph(Graph g) {
    for (int i = 0; i < g->nr_nodes; i++) {
        List tmp = g->adjList[i];
        printf("List for vertex: %d: ", i);
        while (tmp != NULL) {
            printf("%d %d -> ", tmp->data.v, tmp->data.cost);
            tmp = tmp->next;
        }
        printf("NULL\n");
    }
}

void DFS(Graph g, int start) {
    Stack stack = NULL;
    stack = push(stack, start);

    g->visited[start] = 1;
    int current;
    while(!isStackEmpty(stack)) {
        current = top(stack);
        stack = pop(stack);
        List tmp = g->adjList[current];
        while (tmp != NULL) {
            if (!g->visited[tmp->data.v]) {
                stack = push(stack, tmp->data.v);
                g->visited[tmp->data.v] = 1;
            }
            tmp = tmp->next;
        }
    }
    if (!isStackEmpty) {
        freeStack(stack);
    }
}


Graph destroyGraph(Graph g) {
    List current, tmp;
    for (int i = 0; i < g->nr_nodes; i++) {
        g->adjList[i] = destroyList(g->adjList[i]);
    }
    free(g->adjList);
    free(g->visited);
    free(g);
}


void Prim(Graph g, int start, int minCostArray[]) {
    int nrNodes = g->nr_nodes;
    int costs[nrNodes];

    MinHeap *h = newQueue(nrNodes);

    for (int i = 0; i < nrNodes; i++) {
        costs[i] = INF;
        h->elem[i] = newNode(i, costs[i]);
        h->pos[i] = i;
    }

    costs[start] = 0;
    h->elem[start]->v = start;
    h->elem[start]->d = costs[start];
    h->pos[start] = start;
    h->size = nrNodes;

    while (!isEmpty(h)) {
        MinHeapNode* minHeapNode = removeMin(h);
        int u = minHeapNode->v;
        List t = g->adjList[u];

        while (t != NULL) {
            int v = t->data.v;
            if (isInMinHeap(h, v) && t->data.cost < costs[v]) {
                costs[v] = t->data.cost;
                SiftUp(h, v, costs[v]);
            }
            t = t->next;
        }
    }
    int total_cost = 0;
    for (int i = start; i < g->nr_nodes; i++) {
        if (g->visited[i] == 0)
            break;
        total_cost += costs[i];
    }
    for(int i = 0; i < nrNodes; i++) {
        if (minCostArray[i] == INF) {
            minCostArray[i] = total_cost;
            break;
        }
    }
}
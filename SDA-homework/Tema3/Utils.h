/*
    SERBANICA Andreea-Maria - 313CD
*/


#ifndef UTILS_H
#define UTILS_H
#include "Graph.h"

#define INF 1000000
#define NIL -1

typedef struct stack {
    int value;
    struct stack *next;
}*Stack;


int getIndex(char*, char**, int);
List addFirst(List, Pair);
List destroyList(List);
Stack initStack (int);
int isStackEmpty(Stack);
Stack push(Stack, int);
Stack pop(Stack);
int top(Stack);
Stack freeStack(Stack);
void simple_sort(int array[], int n);

#endif
/*
    SERBANICA Andreea-Maria - 313CD
*/


#ifndef __HEAP_H__
#define __HEAP_H__

typedef struct MinHeapNode
{
    int  v;
    int d;
} MinHeapNode;


typedef struct MinHeap
{
    int size;
    int capacity;
    int *pos;
    MinHeapNode **elem;
} MinHeap;

MinHeapNode *newNode(int, int);
MinHeap* newQueue(int);
void swap(MinHeapNode**, MinHeapNode**);
void SiftDown(MinHeap*, int);
int isEmpty(MinHeap*);
MinHeapNode* removeMin(MinHeap*);
void SiftUp(MinHeap*, int, int);
int isInMinHeap(MinHeap *, int);
MinHeap* destroyHeap(MinHeap*, int);

#endif
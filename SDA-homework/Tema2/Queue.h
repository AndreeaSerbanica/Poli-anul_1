/*
    SERBANICA Andreea-Maria - 313CD
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "Tree.h"
#include <stdio.h>

typedef struct nodeQueue {
    unsigned char nodeType;
    Pixel nodePixel;
    struct nodeQueue *next;
}*NodeQueue;

typedef struct queue {
    NodeQueue head;
    NodeQueue tail;
}*Queue;

Queue initQueue(void);
NodeQueue createNodeQueue(T, Pixel);
int isQueueEmpty(Queue);
Queue enqueue(Queue, T, Pixel);
Queue dequeue(Queue);
Queue destroyQueue(Queue);

#endif
/*
    SERBANICA Andreea-Maria - 313CD
*/

typedef unsigned char T;

#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"
#include "Queue.h"

// initialize a queue
Queue initQueue() {
    Queue q = calloc(1,sizeof(struct queue));
    return q;
}

// create a node for queue
NodeQueue createNodeQueue(T nodeType, Pixel nodePixel) {
    NodeQueue qNode = calloc(1, sizeof(struct nodeQueue));
    qNode->nodeType = nodeType;
    qNode->nodePixel = nodePixel;
    return qNode;
}

// verify if the queue is empty
int isQueueEmpty(Queue q) {
    if (q == NULL || q->head == NULL) {
        return 1;
    }
    return 0;
}

// put new element in queue
Queue enqueue(Queue q, T nodeType, Pixel nodePixel) {
    if (isQueueEmpty(q)) {
        q->head = createNodeQueue(nodeType, nodePixel);
        q->tail = q->head;
        return q;
    }

    NodeQueue node = createNodeQueue(nodeType, nodePixel);
    q->tail->next = node;
    q->tail = node;
    return q;
}

// eliminate an element from queue
Queue dequeue(Queue q) {
    NodeQueue tmp;
    if (q->head != NULL) {
        tmp = q->head;
        q->head = q->head->next;
        free(tmp);
    }
    return q;
}

// de-allocate the memory for the queue
Queue destroyQueue(Queue q) {
    while (isQueueEmpty(q) == 0) {
        q = dequeue(q);
    }
    if (q) {
        free(q);
    }
    return NULL;
}
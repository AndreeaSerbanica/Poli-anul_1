/*
    SERBANICA_Andreea-Maria-313CD
*/

#ifndef QUEUE_H
#define QUEUE_H

typedef struct nodeQueue {
    T data[100];
    T caracter;
    struct nodeQueue* next;
}queueNode;

typedef struct queue {
    queueNode *head, *tail;
    int size;
}*TQueue;

queueNode *initNodeforQueue(T *data, T character);
TQueue initQueue(void);
int isQueueEmpty(TQueue q);
TQueue addToQueue(TQueue q, queueNode *newElement);
queueNode *freeNode(queueNode *node);
TQueue deleteFromQueue(TQueue q);

#endif
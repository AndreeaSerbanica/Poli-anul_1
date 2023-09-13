/*
    SERBANICA Andreea-Maria - 313CD
*/

typedef char T;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"


queueNode *initNodeforQueue(T *data, T character) {
    queueNode *node =  malloc(sizeof(struct nodeQueue));
    strcpy(node->data, data);
    node->caracter = character;
    node->next = NULL;
    return node;
}

// initialize an empty queue
TQueue initQueue() {
    TQueue queue = malloc(sizeof(struct queue));
    queue->tail = queue->head = NULL;
    queue->size = 0;
    return queue;
}

int isQueueEmpty(TQueue q) {
    if(q->head == NULL && q->tail == NULL && q->size == 0)
        return 1;
    return 0;
}

//add operation to queue
TQueue addToQueue(TQueue q, queueNode *newElement) {
    if(isQueueEmpty(q)) {
        q->size = 1;
        q->head = newElement;
        q->tail = newElement;
        return q;
    }
    q->tail->next = newElement;
    q->tail = newElement;
    q->size++;
    return q;
}

queueNode *freeNode(queueNode *node) {
    if(node)
        free(node);
    return NULL;
}

// delete elements from the queue
TQueue deleteFromQueue(TQueue q) {
    queueNode *node;
    if(!isQueueEmpty(q)) {
        if(q->size == 1) {
            node = q->head;
            node = freeNode(node);
            q->size--;
            return q;
        }
        node = q->head;
        q->head = q->head->next;
        node = freeNode(node);
        q->size--;
    }
    return q;
}

// de-allocate the memory
TQueue freeQueue(TQueue q) {
    while(!isQueueEmpty(q)) {
        q = deleteFromQueue(q);
    }
    if(q) {
        free(q);
    }
    return NULL;
}
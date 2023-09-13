/*
    SERBANICA Andreea-Maria - 313CD
*/

#ifndef STACK_H
#define STACK_H

#include "DoubleLinkedList.h"

typedef struct stack {
    TList data;
    struct stack *next;
}*TStack;

TStack initStack (TList);
int isStackEmpty(TStack);
TStack push (TStack, TList);
TStack pop(TStack);
TList top(TStack);
TStack freeStack(TStack);
TStack init(void);


#endif
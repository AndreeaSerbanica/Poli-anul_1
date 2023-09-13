/*
    SERBANICA Andreea-Maria - 313CD
*/

typedef char T;

#include "Stack.h"
#include <stdlib.h>
#include "DoubleLinkedList.h"

// initialize the stack with a value in it
TStack initStack (TList data) {
    TStack s = malloc(sizeof(*s));
    s->data = data;;
    s->next = NULL;
    return s;
}

int isStackEmpty(TStack s) {
    if(s == NULL)
        return 1;
    return 0;
}

TStack push (TStack s, TList data) {
    TStack top;
    if(isStackEmpty(s)) {
        return initStack(data);
    }
    top = initStack(data);
    top->next = s;
    return top;
}

TStack pop(TStack s) {
    TStack tmp;
    if(isStackEmpty(s))
        return s;
    tmp = s;
    s = s->next;
    free(tmp);
    return s;
}

TList top(TStack s) {
    if(isStackEmpty(s))
        exit(1);
    return s->data;
}

TStack freeStack(TStack s) {
    while (!isStackEmpty(s)) {
        s = pop(s);
    }
    return NULL;
}

// initialize an empty stack
TStack init() {
    return NULL;
}

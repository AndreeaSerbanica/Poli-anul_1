/*
    SERBANICA Andreea-Maria - 313CD
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "Graph.h"


//get the index of the word in the array if the word exists
int getIndex(char *word, char **word_array, int nrWords) {
    for (int i = 0; i < nrWords; i++) {
        if (strcmp(word, word_array[i]) == 0) {
            return i;
        }
    }
    return INF;
}

//add first element in the list
List addFirst(List list, Pair data) {
    if (list == NULL) {
        list = malloc(sizeof(struct list));
        list->data = data;
        list->next = NULL;
        list->prev = NULL;
        return list;
    }

    List newNode = malloc(sizeof(struct list));
    newNode->data = data;
    newNode->next = list;
    newNode->prev = NULL;
    list->prev = newNode;
    list = newNode;
    return list;
}

//de-allocate memory for the list
List destroyList(List list) {
    List tmp;
    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
    free(list);
}
/*.........functions for stack................*/

Stack initStack (int value) {
    Stack s = malloc(sizeof(*s));
    s->value = value;
    s->next = NULL;
    return s;
}

int isStackEmpty(Stack s) {
    return s == NULL;
}

Stack push(Stack s, int value) {
    Stack top;

    if (isStackEmpty(s))
        return initStack(value);

    top = initStack(value);
    top->next = s;
    return top;
}

Stack pop(Stack s) {
    Stack tmp;

    if (isStackEmpty(s))
        return s;

    tmp = s;
    s = s->next;
    free(tmp);
    return s;
}

int top(Stack s) {
    if (isStackEmpty(s))
        exit(1);
    
    return s->value;
}

Stack freeStack(Stack s) {
    while (!isStackEmpty(s)) {
        s = pop(s);
    }
    return NULL;
}
/*.........functions for stack................*/


void simple_sort(int array[], int n) {
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}
/* 
    SERBANICA Andreea-Maria - 313CD 
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct nodeList {
    T value;
    struct nodeList *next;
    struct nodeList *prev;
}NodeList, *TList;

typedef struct banda {
    TList sentinel;
    TList finger;
    TList last;
}*TBanda;

TList initList(void);
TList createNodeList (T);
TBanda initTape(void);
TList freeNodeList(TList);
TBanda freeBanda(TBanda);
void write(TBanda, T);
void move_left(TBanda, TList*);
void move_right(TBanda);
void show(TBanda, FILE*);
void show_current(TBanda, FILE*);
void move_left_char(TBanda, T, FILE*);
void move_right_char(TBanda, T);
void insert_left(TBanda, T, FILE*);
void insert_right(TBanda, T);

#endif
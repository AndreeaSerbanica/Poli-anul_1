/* 
    SERBANICA Andreea-Maria - 313CD 
*/

typedef char T;

#include "DoubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

// initialize an empty list (an empty node)
TList initList() {
    TList doubleLinkedList = calloc(1, sizeof(struct nodeList));
    return doubleLinkedList;
}

// create a nod with a value
TList createNodeList (T value) {
    TList node = malloc(sizeof(struct nodeList));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;
    return node;
}

// initialize an empty banda
TBanda initTape() {
    TBanda tape = malloc(sizeof(*tape));
    TList sentinel = initList();
    TList prim = createNodeList('#'); //create a diffrent node from the sentinel with the value '#'
    tape->sentinel = sentinel;
    tape->finger = prim;
    tape->last = prim;
    sentinel->next = prim;
    prim->prev = sentinel;
    return tape;
}

TList freeNodeList(TList node) {
    if(node)
        free(node);
    return NULL;
}

TBanda freeBanda(TBanda tape) {
    TList tmp;
    while(tape->sentinel != NULL ){
        tmp = tape->sentinel;
        tape->sentinel = tape->sentinel->next;
        tmp = freeNodeList(tmp);
    }
    free(tape);
    return NULL;
}

void write(TBanda tape, T character) {
    tape->finger->value = character;
}

void move_left(TBanda tape,TList *finger_for_stack) {
    if (tape->finger->prev == tape->sentinel)
        return;
    *finger_for_stack = tape->finger; // variable for the previous finger to add to the stack
    tape->finger = tape->finger->prev;
}

void move_right(TBanda tape) {
    if(tape->finger->next != NULL) {
        tape->finger = tape->finger->next;
        return;
    }    
    TList newNode = createNodeList('#');
    newNode->prev = tape->finger;
    tape->finger->next = newNode;
    tape->finger = newNode;
    tape->last = tape->finger;
}

void move_left_char(TBanda tape, T character, FILE *fout) {
    int ok = 0;
    TList tmp = tape->finger;
    while(tmp->value != character) {
        if (tmp == tape->sentinel) {
            ok = 1;
            fprintf(fout, "ERROR\n");
            break;
        }
        tmp = tmp->prev;
    }
    if (ok == 0) {
        tape->finger = tmp;
    }
}

void move_right_char(TBanda tape, T character) {
    TList tmp = tape->finger;
    while(tmp->value != character) {
        if(tmp->next == NULL) {
            break;
        }
        tmp = tmp->next;
    }
    if (tmp->value == character) {
        tape->finger = tmp;
        return;
    }
    tape->finger = tmp;
    TList newNode = createNodeList('#');
    newNode->prev = tape->finger;
    tape->finger->next = newNode;
    tape->finger = newNode;
    tape->last = tape->finger;
}

void insert_left(TBanda tape, T character, FILE *fout) {
    int ok = 0;
    if(tape->finger->prev == tape->sentinel) {
        fprintf(fout, "ERROR\n");
    } else {
        TList newNode = createNodeList(character);
        newNode->prev = tape->finger->prev;
        tape->finger->prev->next = newNode;
        newNode->next = tape->finger;
        tape->finger->prev = newNode;
        tape->finger = newNode;
    }
}

void insert_right(TBanda tape, T character) {
    TList newNode = createNodeList(character);
    if (tape->finger->next == NULL) {
        newNode->prev = tape->finger;
        tape->finger->next = newNode;
        tape->finger = newNode;
        return;
    }
    newNode->next = tape->finger->next;
    tape->finger->next->prev = newNode;
    newNode->prev = tape->finger;
    tape->finger->next = newNode;
    tape->finger = newNode;
}

void show(TBanda tape, FILE *fout) {
    TList tmp = tape->sentinel->next;
    while(tmp != NULL) {
        if(tape->finger == tmp) {
            fprintf(fout, "|%c|", tmp->value);
        } else {
            fprintf(fout, "%c", tmp->value);
        }
        tmp = tmp->next;
    }
    fprintf(fout, "\n");
}

void show_current(TBanda tape, FILE *fout) {
    fprintf(fout, "%c", tape->finger->value);
    fprintf(fout, "\n");
}
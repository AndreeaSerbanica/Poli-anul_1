/*
    SERBANICA Andreea-Maria - 313CD
*/

typedef char T;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DoubleLinkedList.h"
#include "Queue.h"
#include "Stack.h"

int main() {
    /*
        reading from a file
    */
    int num; //number of operations
    T word[20];
    const char no_comands[40] = "UNDO_REDO_SHOW_CURRENT_EXECUTE";
    T letter;
    FILE *fin, *fout;

 
    // verify if the file exists
    fin = fopen("tema1.in", "r");
    fout = fopen("tema1.out", "w");
    if (fin  == NULL || fout == NULL) {
        fputs("ERROR! NO FILE!\n", stderr);

        exit(0);
    }
    
    // we add the operations to queue
    queueNode *tmp;
    TQueue queue = initQueue();
    fscanf(fin, "%d", &num);
    for(int i = 0; i < num; i++) {
        if(feof(fin))
            break;
        fscanf(fin, "%s", word);
        if(strcmp(word, "WRITE") == 0 || strcmp(word, "INSERT_LEFT") == 0 || strcmp(word, "INSERT_RIGHT") == 0 || strcmp(word, "MOVE_LEFT_CHAR") == 0 || strcmp(word, "MOVE_RIGHT_CHAR") == 0) {
            fscanf(fin, " %c", &letter);
            tmp = initNodeforQueue(word, letter);
        } else {
            letter = ' ';
            tmp = initNodeforQueue(word, letter);
        }
        queue= addToQueue(queue, tmp);
    }

    fclose(fin);

    // initialize banda;
    TBanda tape = initTape();

     //initialize the stacks
    TStack undo_stack = init();
    TStack redo_stack = init();

    queueNode *tmp1 = queue->head;
    queueNode *queue_head = queue->head; //variable to retain the head of the queue

    while (tmp1 != NULL) {
        if(strstr(no_comands, tmp1->data) != 0) {
            if(strcmp("EXECUTE", tmp1->data) == 0) {
                if (strcmp("WRITE",queue->head->data) == 0) {
                    undo_stack = freeStack(undo_stack);
                    redo_stack = freeStack(redo_stack);
                    write(tape, queue->head->caracter);
                } else if (strcmp("MOVE_LEFT", queue->head->data) == 0) {
                    TList finger_for_stack;
                    move_left(tape, &finger_for_stack);
                    undo_stack = push(undo_stack,finger_for_stack);
                } else if (strcmp("MOVE_RIGHT", queue->head->data) == 0) {
                    undo_stack = push(undo_stack, tape->finger);
                    move_right(tape);
                } else if (strcmp("MOVE_LEFT_CHAR", queue->head->data) == 0) {
                    undo_stack = freeStack(undo_stack);
                    redo_stack = freeStack(redo_stack);
                    move_left_char(tape, queue->head->caracter, fout);
                } else if (strcmp("MOVE_RIGHT_CHAR", queue->head->data) == 0) {
                    undo_stack = freeStack(undo_stack);
                    redo_stack = freeStack(redo_stack);
                    move_right_char(tape, queue->head->caracter);
                } else if (strcmp("INSERT_LEFT", queue->head->data) == 0) {
                    undo_stack = freeStack(undo_stack);
                    redo_stack = freeStack(redo_stack);
                    insert_left(tape, queue->head->caracter, fout);
                } else if (strcmp("INSERT_RIGHT", queue->head->data) == 0) {
                    undo_stack = freeStack(undo_stack);
                    redo_stack = freeStack(redo_stack);
                    insert_right(tape, queue->head->caracter);
                }
                queue->head = queue->head->next;

            } else if (strcmp("SHOW", tmp1->data) == 0) {
                show(tape, fout);
            } else if (strcmp("SHOW_CURRENT", tmp1->data) == 0) {
                show_current(tape, fout);
            } else if (strcmp("UNDO",tmp1->data) == 0) {
                redo_stack = push(redo_stack, tape->finger);
                tape->finger = top(undo_stack);
                undo_stack = pop(undo_stack);
            } else if (strcmp("REDO", tmp1->data) == 0) {
                undo_stack = push(undo_stack, tape->finger);
                tape->finger = top(redo_stack);
                redo_stack = pop(redo_stack);
            }
        }
        if (strstr(no_comands, queue->head->data) != 0) {
            while (strstr(no_comands, queue->head->data) != 0) {
                if(queue->head->next != NULL) {
                    queue->head = queue->head->next;
                }
                else { 
                    break;
                }
            }
        }
        tmp1 = tmp1->next;
    }


    fclose(fout);

    //de-allocate everything
    
    while(queue_head != NULL) {
        queueNode *tmp;
        tmp = queue_head;
        queue_head = queue_head->next;
        tmp = freeNode(tmp);
    }

    undo_stack = freeStack(undo_stack);
    redo_stack = freeStack(redo_stack);

    tape = freeBanda(tape);
    free(queue);

    return 0;
}
/*
    SERBANICA Andreea-Maria - 313CD
*/

#ifndef TREE_H
#define TREE_H

#include <stdio.h>

/* structure of a pixel */
typedef struct pixel {
    T red, green, blue; 
}Pixel;


typedef struct node {
    T nodeType; // node type
    Pixel nodePixel; // RGB values of a node
    int heightTree;
    struct node *next1, *next2, *next3, *next4;
}*CompressionTree;

CompressionTree initTree(void); 
CompressionTree createNode(T, Pixel);
CompressionTree divide_and_insert(CompressionTree, Pixel**, unsigned int, unsigned int, unsigned int, int);
void printLevel(CompressionTree, FILE*, int);
int max(int, int, int, int);
int findHeight(CompressionTree);
void countLeafNodes(CompressionTree, int*);
void firstLeafLevel(CompressionTree, int, int*);
int calculateBiggestDimension(int, int);
CompressionTree freeTree(CompressionTree);

#endif
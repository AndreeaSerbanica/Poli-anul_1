/*
    SERBANICA Andreea-Maria - 313CD
*/

typedef unsigned char T;

#include <stdio.h>
#include <stdlib.h>
#include "Decompression.h"
#include "Tree.h"
#include "Queue.h"

// create a quadtree using a queue with the elements of the tree
void createQuadTree(CompressionTree root, Queue *queue, int level) {
    if (root == NULL) {
       return;
    }
    if (level == 0) {
        if (root->nodeType == 1) {
            return;
        } else if (root->nodeType == 0) {
            root->next1 = createNode((*queue)->head->nodeType, (*queue)->head->nodePixel);
            *queue = dequeue(*queue);
            root->next2 = createNode((*queue)->head->nodeType, (*queue)->head->nodePixel);
            *queue = dequeue(*queue);
            root->next3 = createNode((*queue)->head->nodeType, (*queue)->head->nodePixel);
            *queue = dequeue(*queue);
            root->next4 = createNode((*queue)->head->nodeType, (*queue)->head->nodePixel);
            *queue = dequeue(*queue);
            return;
        }
    }

    createQuadTree(root->next1, queue, level - 1);
    createQuadTree(root->next2, queue, level - 1);
    createQuadTree(root->next3, queue, level - 1);
    createQuadTree(root->next4, queue, level - 1);

    return;
}

// create the pixel matrix
void createPixelMatrix(CompressionTree root, Pixel ***matrix, unsigned int size, unsigned int startRow, unsigned int startCol) {
    if (root == NULL) {
        return;
    }
    if (root->nodeType == 1) {
        for (int i = startRow; i < startRow + size; i++) {
            for (int j = startCol; j < startCol + size; j++) {
                (*matrix)[i][j] = root->nodePixel;
            }
        }
        return;
    }

    createPixelMatrix(root->next1, matrix, size / 2, startRow, startCol);
    createPixelMatrix(root->next2, matrix, size / 2, startRow, startCol + size/2);
    createPixelMatrix(root->next3, matrix, size / 2, startRow + size/2, startCol + size/2);
    createPixelMatrix(root->next4, matrix, size / 2, startRow + size/2, startCol);
}
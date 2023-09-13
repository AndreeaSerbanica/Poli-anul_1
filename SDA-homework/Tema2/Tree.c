/*
    SERBANICA Andreea-Maria - 313CD
*/

typedef unsigned char T;
#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "Compression.h"

// initialize a tree
CompressionTree initTree() {
    CompressionTree root = calloc(1, sizeof(struct node));
    return root;
}

// create aa node for a tree
CompressionTree createNode(T nodeType, Pixel nodePixel) {
    CompressionTree root = calloc(1, sizeof(struct node));
    root->nodeType = nodeType;
    root->nodePixel = nodePixel;
    root->heightTree = 1;
    return root;
}

// divide the matrix and insert in a tree
CompressionTree divide_and_insert(CompressionTree root, Pixel **matrix, unsigned int size, unsigned int startRow, unsigned int startCol, int factor) {

    /*............calculate mean...........*/
    unsigned long long red_mean = 0, green_mean = 0, blue_mean = 0;
    unsigned long long mean = 0;
    for (int i = startRow; i < startRow + size; i++) {
        for (int j = startCol; j < startCol + size; j++) {
            red_mean += matrix[i][j].red;
            green_mean += matrix[i][j].green;
            blue_mean += matrix[i][j].blue;
        }
    }
    red_mean = red_mean / (size * size);
    green_mean = green_mean / (size * size);
    blue_mean = blue_mean / (size * size);
    for (int i = startRow; i < startRow + size; i++) {
        for (int j = startCol; j < startCol + size; j++) {
           mean += (red_mean - matrix[i][j].red) * (red_mean - matrix[i][j].red) + (green_mean - matrix[i][j].green) * (green_mean - matrix[i][j].green) + (blue_mean - matrix[i][j].blue) * (blue_mean - matrix[i][j].blue);
        }
    }
    mean = mean / (3 * (size * size)); 
    /*............calculate mean...........*/

    Pixel pixelNULL;
    pixelNULL.red = pixelNULL.green = pixelNULL.blue = 0;
    Pixel pixelColor;
    pixelColor.red = red_mean;
    pixelColor.green = green_mean;
    pixelColor.blue = blue_mean;
    if (mean <= factor) {
        return createNode(1, pixelColor);
    } else if (mean > factor) {
        root = createNode(0, pixelNULL);
    }
    root->next1 = divide_and_insert(root->next1, matrix, size/2, startRow, startCol,factor);
    root->next2 = divide_and_insert(root->next2, matrix, size/2, startRow, startCol + size/2, factor);
    root->next3 = divide_and_insert(root->next3, matrix, size/2, startRow + size/2, startCol + size/2, factor);
    root->next4 = divide_and_insert(root->next4, matrix, size/2, startRow + size/2, startCol, factor);

    return root;
}


// print the tree by level
void printLevel(CompressionTree root, FILE* fout, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 0) {    
        fprintf(fout, "RGB: %d %d %d, TYPE: %u\n", root->nodePixel.red, root->nodePixel.green, root->nodePixel.blue, root->nodeType);
        return;
    }
    printLevel(root->next1, fout, level - 1);
    printLevel(root->next2, fout, level - 1);
    printLevel(root->next3, fout, level - 1);
    printLevel(root->next4, fout, level - 1);
}

// find the max between 4 numbers
int max(int a, int b, int c, int d) {
    int max_val = a;
    if (b > max_val) {
        max_val = b;
    }
    if (c > max_val) {
        max_val = c;
    }
    if (d > max_val) {
        max_val = d;
    }
    return max_val;
}

// find the height of a tree
int findHeight(CompressionTree root) {
    if (root == NULL) {
        return 0;
    }
    int height1 = findHeight(root->next1);
    int height2 = findHeight(root->next2);
    int height3 = findHeight(root->next3);
    int height4 = findHeight(root->next4);
    return 1 + max(height1, height2, height3, height4);

}

// count the terminal nodes of a tree
void countLeafNodes(CompressionTree root, int *count) {
    if (root == NULL) {
        return;
    }

    if (root->nodeType == 1) {
        (*count)++;
    }

    countLeafNodes(root->next1, count);
    countLeafNodes(root->next2, count);
    countLeafNodes(root->next3, count);
    countLeafNodes(root->next4, count);
}

// find the first level that has a terminal node
void firstLeafLevel(CompressionTree root, int level, int *ok){
    if (root == NULL) {
        return;
    }
    if (level == 1 && root->nodeType == 1) {
        *ok = 1;
        return;
    } 
    firstLeafLevel(root->next1, level - 1, ok);
    firstLeafLevel(root->next2, level - 1, ok);
    firstLeafLevel(root->next3, level - 1, ok);
    firstLeafLevel(root->next4, level - 1, ok);
}

// calculate the biggest dimension in the matrix
int calculateBiggestDimension(int width, int leaf_lvl) {
    int x = 1;
    for (int i = 1; i < leaf_lvl; i++) {
        x *= 2;
    }
    int dim = width / x;
    return dim;
}

// de-allocate the tree
CompressionTree freeTree(CompressionTree root) {
    if (root == NULL) {
        return NULL;
    }
    root->next1 = freeTree(root->next1);
    root->next2 = freeTree(root->next2);
    root->next3 = freeTree(root->next3);
    root->next4 = freeTree(root->next4);
    free(root);
    return NULL;
}

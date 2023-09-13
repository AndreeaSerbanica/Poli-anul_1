/*
    SERBANICA Andreea-Maria - 313CD
*/

typedef unsigned char T;

#include <stdio.h>
#include "Tree.h"
#include "Compression.h"
#include <stdlib.h>

// is writting the tree in a binary file by order
void binaryLevelOrder(CompressionTree root, int level, FILE* fout) {
    if (root == NULL) {
        return;
    }
    if (level == 0) {
        if (root->nodeType == 0) {
            unsigned char type = 0;
            fwrite(&type,  sizeof(unsigned char), 1, fout);
        } else {
            fwrite(&(root->nodeType), sizeof(unsigned char), 1, fout);
            fwrite(&(root->nodePixel.red), sizeof(unsigned char), 1, fout);
            fwrite(&(root->nodePixel.green), sizeof(unsigned char), 1, fout);
            fwrite(&(root->nodePixel.blue), sizeof(unsigned char), 1, fout);
        }
        return;
    }
    binaryLevelOrder(root->next1, level - 1, fout);
    binaryLevelOrder(root->next2, level - 1, fout);
    binaryLevelOrder(root->next3, level - 1, fout);
    binaryLevelOrder(root->next4, level - 1, fout);
}
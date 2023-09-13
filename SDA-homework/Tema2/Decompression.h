/*
    SERBANICA Andreea-Maria - 313CD
*/

#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

#include "Tree.h"
#include <stdio.h>
#include "Queue.h"

void createQuadTree(CompressionTree, Queue*, int);
void createPixelMatrix(CompressionTree, Pixel ***, unsigned int, unsigned int, unsigned int);

#endif
/*
    SERBANICA Andreea-Maria - 313CD
*/

typedef unsigned char T;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"
#include "Compression.h"
#include "Decompression.h"
#include "Queue.h"

int main(int argc, char *argv[]) {

    if (argc < 4) {
        fputs("NOT ENOUGH ARGUMENTS!\n", stderr);
        exit(0);
    }
    if (strcmp(argv[1], "-c1") == 0) {
        int factor = strtol(argv[2], NULL, 10);

        FILE *fin = fopen(argv[3], "rb");
        FILE *fout = fopen(argv[4], "w");

        if (fin == NULL)
        {
            fputs("NO FILE TO OPEN!\n", stderr);
            exit(0);
        }

        char fileType[2];
        unsigned int width, height;
        unsigned int maxColorValue;
        fscanf(fin, "%s", fileType);           // read the file type
        fscanf(fin, "%u %u", &width, &height); // read the dimensions of the photos
        fscanf(fin, "%u", &maxColorValue);     // read the max value of a color
        fgetc(fin); // take out \n

        /*...............allocate memmory for a matrix...............*/
        Pixel **pixelsMatrix = malloc(height * sizeof(Pixel *));
        for (int i = 0; i < height; i++) {
            pixelsMatrix[i] = malloc(width * sizeof(Pixel));
        }


        /*...............put elements in the matrix...............*/
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fread(&pixelsMatrix[i][j].red, sizeof(unsigned char), 1, fin);
                fread(&pixelsMatrix[i][j].green, sizeof(unsigned char), 1, fin);
                fread(&pixelsMatrix[i][j].blue, sizeof(unsigned char), 1, fin);
            }
        }   

        unsigned int size = width;
        float red_mean = 0, green_mean = 0, blue_mean = 0, mean = 0;

        Pixel rgbNULL; //aux variable with red, green, blue 0
        rgbNULL.red = rgbNULL.green = rgbNULL.blue = 0;


        /*...............make the tree and find height...............*/
        CompressionTree pixelTree = NULL;
        pixelTree = divide_and_insert(pixelTree, pixelsMatrix, width, 0, 0, factor);
        pixelTree->heightTree = findHeight(pixelTree); //find the height
        fprintf(fout, "%d\n", pixelTree->heightTree);


        /*...............find the first level in the tree that have a leaf...............*/
        int leaf_lvl;
        for (int i = 1; i <= pixelTree->heightTree; i++) {
            int ok = 0;
            int level = i;
            firstLeafLevel(pixelTree, i, &ok);
            if (ok == 1) {
                leaf_lvl = level;
                break;
            }
        }
        int leaves = 0;
        countLeafNodes(pixelTree, &leaves); //count the number of leaves

        fprintf(fout, "%d\n", leaves); //print the number of leaves
        fprintf(fout, "%d\n", calculateBiggestDimension(width, leaf_lvl)); //calculcate the dimension

        /*...............de-allocate the memory...............*/
        for (int i = 0; i < width; i++ ){
            free(pixelsMatrix[i]);
        }
        free(pixelsMatrix);
        pixelTree = freeTree(pixelTree);


        return 0;
    } 

    if (strcmp(argv[1], "-c2") == 0) {
        int factor = strtol(argv[2], NULL, 10);
        
        FILE *fin = fopen(argv[3], "rb");
        FILE *fout = fopen(argv[4], "wb");

        if (fin == NULL)
        {
            fputs("NO FILE TO OPEN!\n", stderr);
            exit(0);
        }

        char fileType[2];
        unsigned int width, height;
        unsigned int maxColorValue;
        fscanf(fin, "%s", fileType);           // read the file type
        fscanf(fin, "%u %u", &width, &height); // read the dimensions of the photos
        fscanf(fin, "%u", &maxColorValue);     // read the max value of a color

        fgetc(fin); // take out \n

        /*...............allocate memmory for a matrix...............*/
        Pixel **pixelsMatrix = malloc(height * sizeof(Pixel *));
        for (int i = 0; i < height; i++) {
            pixelsMatrix[i] = malloc(width * sizeof(Pixel));
        }


        /*...............put elements in the matrix...............*/
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fread(&pixelsMatrix[i][j].red, sizeof(unsigned char), 1, fin);
                fread(&pixelsMatrix[i][j].green, sizeof(unsigned char), 1, fin);
                fread(&pixelsMatrix[i][j].blue, sizeof(unsigned char), 1, fin);
            }
        }

        unsigned int size = width;
        float red_mean = 0, green_mean = 0, blue_mean = 0, mean = 0;

        Pixel rgbNULL;  // variable with the red, green, blue = 0
        rgbNULL.red = rgbNULL.green = rgbNULL.blue = 0;


        /*...............divide matrix and put the elements in a tree...............*/
        CompressionTree pixelTree = NULL;
        pixelTree = divide_and_insert(pixelTree, pixelsMatrix, width, 0, 0, factor);
        pixelTree->heightTree = findHeight(pixelTree);

        /*...............write the elements of the tree in the binary file...............*/
        fwrite(&width, sizeof(unsigned int), 1, fout);
        for (int level = 0; level < pixelTree->heightTree; level++) {
            binaryLevelOrder(pixelTree, level, fout);
        }

        /*...............de-allocate the memory...............*/
        for (int i = 0; i < width; i++ ){
            free(pixelsMatrix[i]);
        }
        free(pixelsMatrix);
        pixelTree = freeTree(pixelTree);

        return 0;
    }

    if (strcmp(argv[1], "-d") == 0) {
        FILE *fin = fopen(argv[2], "rb");
        FILE *fout = fopen(argv[3], "wb");

        if (fin == NULL)
        {
            fputs("NO FILE TO OPEN!\n", stderr);
            exit(0);
        }

        unsigned int width;
        Queue pixelQueue = initQueue();


        /*...............read from the binary file...............*/
        fread(&width, sizeof(unsigned int), 1, fin);
        Pixel pixelColour;
        unsigned char pixelType;
        while(!feof(fin)) {
            fread(&(pixelType), sizeof(unsigned char), 1, fin);
            if (pixelType == 0) {
                pixelColour.red = pixelColour.green = pixelColour.blue = 0;
            } else {
                fread(&(pixelColour.red), sizeof(unsigned char), 1, fin);
                fread(&(pixelColour.green), sizeof(unsigned char), 1, fin);
                fread(&(pixelColour.blue), sizeof(unsigned char), 1, fin);
            }
            pixelQueue = enqueue(pixelQueue, pixelType, pixelColour); //put the elements in a queue
        }

        /*...............make the quadric tree...............*/
        CompressionTree pixelTree = createNode(pixelQueue->head->nodeType, pixelQueue->head->nodePixel); //put the first element in the tree
        pixelQueue = dequeue(pixelQueue);
        int level = 0;
        while(pixelQueue->head->next != NULL) {
            createQuadTree(pixelTree, &pixelQueue, level); //put the rest elements
            level++;
        }
        
        /*...............allocate memory for the matrix...............*/
        Pixel **pixelMartix = malloc(width * sizeof(Pixel*));
        for (int i = 0; i < width; i++) {
            pixelMartix[i] = malloc(width * sizeof(Pixel));
        }
        createPixelMatrix(pixelTree, &(pixelMartix), width, 0, 0); //create the matrix

        /*...............write the binary file .ppm...............*/
        fprintf(fout, "P6\n%u %u\n255\n", width, width);
        
        for ( int i = 0; i < width; i++) {
            for ( int  j = 0; j < width; j++) {
                fwrite(&(pixelMartix[i][j].red), sizeof(unsigned char), 1, fout);
                fwrite(&(pixelMartix[i][j].green), sizeof(unsigned char),1, fout);
                fwrite(&(pixelMartix[i][j].blue), sizeof(unsigned char), 1, fout);
            }
        }


        /*...............de-allcoate the memory...............*/
        for (int i = 0; i < width; i++ ){
            free(pixelMartix[i]);
        }
        free(pixelMartix);
        pixelTree = freeTree(pixelTree);
        pixelQueue = destroyQueue(pixelQueue);


        return 0;
    }
    return 0;
}
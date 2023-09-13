/*
    SERBANICA Andreea-Maria - 313CD
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "Graph.h"
#include "Heap.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fputs("Not enough arguments!\n", stderr);
        return 0;
    }

    if (strcmp(argv[1], "1") == 0) {
        FILE *fin  = fopen("tema3.in", "r");
        FILE *fout = fopen("tema3.out", "w");

        if (fin == NULL) {
            fputs("No file to open!\n", stderr);
            exit(0);
        }

        int nrNodes, nrEdges;
        fscanf(fin, "%d %d", &nrNodes, &nrEdges);

        Graph map = initGraph(nrNodes);
        
    /*...................allocate memory for the array of objectives...................*/
        char **objectives = malloc(nrNodes * sizeof(char*));
        for (int i = 0; i < nrNodes; i++) {
            objectives[i] = malloc(50 * sizeof(char));
        }

    /*...................allocate memory for the array of objectives...................*/


        //read the elements and create the objectives array and the graph
        int count = 0;
        char source[50], destination[50];
        int cost;
        for (int i = 0; i < nrEdges; i++) {
            fscanf(fin, "%s %s", source, destination);
            fscanf(fin, "%d", &cost);
            
            int index_source = getIndex(source, objectives, count);
            if (index_source == INF) {
                strcpy(objectives[count], source);
                index_source = count;
                count++;
            }

            int index_destination = getIndex(destination, objectives, count);
            if(index_destination == INF) {
                strcpy(objectives[count], destination);
                index_destination = count;
                count++;                
            }

            map = insertEdge(map, index_source, index_destination, cost);
            map = insertEdge(map, index_destination, index_source, cost);
        }

        //count how many graphs
        int nrGraphs = 0, start = 0;
        int cost_total[nrNodes];
        for (int i = 0; i < map->nr_nodes; i++) {
            cost_total[i] = INF;
        }
        for (int i = 0; i < map->nr_nodes; i++) {
            if (map->visited[i] == 0) {
                start = i; 
                DFS(map, start);
                Prim(map, start, cost_total);
                nrGraphs++;
            }
            
        }
        fprintf(fout, "%d\n", nrGraphs);
        simple_sort(cost_total, nrGraphs);

        for (int i = 0; i < nrGraphs; i++) {
            fprintf(fout, "%d\n", cost_total[i]);
        }




    /*...................de-allocate memory...................*/
        for (int i = 0; i < nrNodes; i++) {
            free(objectives[i]);
        }
        free(objectives);

        map = destroyGraph(map);

    /*...................de-allocate memory...................*/

    fclose(fin);
    fclose(fout);

        return 0;
    }
    
    if (strcmp(argv[1], "2") == 0) {
        FILE *fout = fopen("tema3.out", "w");
        fprintf(fout, "This is task 2");
        return 0;
    }
    return 0;
}
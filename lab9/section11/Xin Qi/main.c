#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "adjacencymatrix.h"

int main() {

    int* g_testgraph = (int*)malloc(sizeof(int) * ROWS * COLUMNS);
    // Generate a random graph
    generateGraph(g_testgraph);
    // Print out the graph
    printGraph(g_testgraph);
    // Print out the nodeInDegree of each of the
    // five nodes
    int i = 0;
    for (i = 0; i < COLUMNS; ++i) {
        printf("node %d in-degree= %d\n", i, nodeInDegree(g_testgraph, i));
    }
    // Print out the nodeInDegree of each of the
    // five nodes
    i = 0;
    for (i = 0; i < COLUMNS; ++i) {
        printf("node %d out-degree= %d\n", i, nodeOutDegree(g_testgraph, i));
    }
    // Check which nodes '0' is connected to
    printf("Node 0 connections:");
    int j;
    for (j = 0; j < COLUMNS; ++j) {
        printf("%d ", isConnected(g_testgraph, 0, j));
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "adjacencymatrix.h"

/*  ============= Tutorial on Graph format ============
    You are given a randomly generated graph that looks
    of the form:

    0 0 1 1 1
    1 0 0 1 1
    0 1 0 1 1
    1 0 0 0 0
    1 0 1 1 0

    You can think of the graph with labels for each of
    the nodes (sometimes called vertices) more clearly below:

               0 1 2 3 4
               ---------
    node 0:    0 0 1 1 1
    node 1:    1 0 0 1 1
    node 2:    0 1 0 1 1
    node 3:    1 0 0 0 0
    node 4:    1 0 1 1 0

    A '1' represents a connection to a node, and a 0
    means it is not connected.

               0 1 2 3 4
               ---------
    node 0:    0 0 1 1 1
    node 1:    1 0 0 1 1
    node 2:    0 1 0 1 1
    node 3:    1 0 0 0 0
    node 4:    1 0 1 1 0

    In the above, '0' is connected to 2, 3, and 4.
    That means node 0 has directed-edges out
    to nodes  2,3,and 4. In other words,
    the edge-list for node 0 is:
    0->2, 0->3, 0->4

    The number of connections a node has out is its 'out-degree'
    The number of connections a node has in are it's 'in-degree'
*/

// This function generates a random graph
// Note: For the purpose of this lab,
//       we do not seed the random number generator
//       so we can generate the same graph over
//       and over again.
void generateGraph(int* g) {
    // Uncomment the line below if you want
    // to generate a random graph each time.
    // srand(time(NULL));
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (i == j) {
                g[i * ROWS + j] = 0; // Why do we have this condition?
            } else {
                g[i * ROWS + j] = rand() % 2;
            }
        }
    }
}

// This function will print out the adjacency
// matrix for a graph.
void printGraph(int* g) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%d ", g[i * ROWS + j]);
        }
        printf("\n");
    }
}

// Compute 'in-degree' of a node
// For a given node 'n' in an adjacency matrix,
// compute the in-degree.
int nodeInDegree(int* g, int node) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        // Check if there's an incoming edge from i to 'node'
        if (g[i * COLUMNS + node] == 1) {
            count++;
        }
    }
    return count;
}

// Compute 'out-degree' of a node
// For a given node 'n' in an adjacency matrix,
// compute the out-degree.
int nodeOutDegree(int* g, int node) {
    int count = 0;
    for (int j = 0; j < COLUMNS; j++) {
        // Check if 'node' has an outgoing edge to j
        if (g[node * COLUMNS + j] == 1) {
            count++;
        }
    }
    return count;
}

// Figure out if two nodes are connected
// Returns a 1 if node1 is connected to node 2
// for now, this function is checking only if an edge exists between
//          node 1 and node 2.
// what would we need to do if we wanted to see if there were a path
//          between node 1 and node 2?
int isConnected(int* g, int node1, int node2) {
    // Direct check if there's an edge from node1 to node2
    return g[node1 * COLUMNS + node2] == 1;
}
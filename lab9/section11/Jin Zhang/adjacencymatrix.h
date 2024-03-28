/*
* This file contains the definition of the TreeNode_t struct and
the function prototypes for the dfs.c file.

Do NOT modify this file.
*/

// These defines do a text replacement
// everytime the string 'ROWS' and 'COLUMNS'
// are found in this specific source file.
// You can play with these values.

#ifndef ROWS   // do not modify
#define ROWS 5 // you can modify this
#endif         // do not modify

#ifndef COLUMNS   // do not modify
#define COLUMNS 5 // you can modify this
#endif            // do not modify

void generateGraph(int* g);

void printGraph(int* g);

int nodeInDegree(int* g, int node);

int nodeOutDegree(int* g, int node);

int isConnected(int* g, int node1, int node2);

// This is a great lab to practice debugging.
// The Makefile already has the -g flag, so you can use gdb to debug.
// See the debugging tutorial on Piazza / Canvas for more information.
#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"

// Depth-First Tree Traversal
// Make sure to print out each node you visit, and only print it out once!
// **Hint** Think recursively
void dfs(TreeNode_t* start) {
    //base case.
    if(start == NULL){
        return;
    }
    //preoder: current-left-right.
    //print current node:
    printf("%c\n", start->letter);
    //recursively travse the left of tree.
    dfs(start->lChild);
    dfs(start->rChild);//then right of tree.
}

// free function
void freeTree(TreeNode_t* start) {
    if(start == NULL){
        return;
    }
    //free left of tree first
    freeTree(start->lChild);
    freeTree(start->rChild);
    free(start);
}

// This is a great lab to practice debugging.
// The Makefile already has the -g flag, so you can use gdb to debug.
// See the debugging tutorial on Piazza / Canvas for more information.
#include "dfs.h"

#include <stdio.h>
#include <stdlib.h>

// Depth-First Tree Traversal
// Make sure to print out each node you visit, and only print it out once!
// **Hint** Think recursively
void dfs(TreeNode_t* start) {
    // TODO: Hmm, how can I look through both branches of the node?
    // TODO: Hmm, when do I stop?

    if (start == NULL) {
    } else {
        TreeNode_t* startl = start->lChild;
        TreeNode_t* startr = start->rChild;

        printf("%c", start->letter);
        dfs(startl);
        dfs(startr);
    }
}

// free function
void freeTree(TreeNode_t* start) {
    // TODO
    //

    if (start == NULL) {
    } else {
        TreeNode_t* startl = start->lChild;
        TreeNode_t* startr = start->rChild;

        freeTree(startl);
        freeTree(startr);
        free(start);
    }
}

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
    // TODO: Hmm, how can I look through both branches of the node?
    // TODO: Hmm, when do I stop?
    // when we hit a leaf, which means the children of the node is null
    if (start == NULL)
        return;

    printf("%c ", start->letter);

    // Recursively traverse the left subtree first
    dfs(start->lChild);

    dfs(start->rChild);
}

// free function
void freeTree(TreeNode_t* start) {
    if (start == NULL) {
        return;
    }
    freeTree(start->lChild);
    freeTree(start->rChild);
    // Free current node
    free(start);
}

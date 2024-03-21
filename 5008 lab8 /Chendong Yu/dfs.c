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
    // set up base case for recursion
    if (start == NULL)
        return;

    // Print the current node
    printf("%c ", start->letter);

    // Recursively traverse the left subtree
    dfs(start->lChild);

    // Recursively traverse the right subtree
    dfs(start->rChild);
}

// free function
void freeTree(TreeNode_t* start) {
    // set up base case for recursion
    if (start == NULL)
        return;

    // Recursively free the left subtree
    freeTree(start->lChild);

    // Recursively free the right subtree
    freeTree(start->rChild);

    // Free the memory allocated for the current node
    free(start);
}

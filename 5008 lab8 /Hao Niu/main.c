#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"

/*
* This is the driver for the Depth-First Tree Traversal lab.
*/

int main() {

    // Manually create a tree for this lab
    TreeNode_t* start = malloc(sizeof(TreeNode_t));
    TreeNode_t* a = malloc(sizeof(TreeNode_t));
    TreeNode_t* b = malloc(sizeof(TreeNode_t));
    TreeNode_t* c = malloc(sizeof(TreeNode_t));
    TreeNode_t* d = malloc(sizeof(TreeNode_t));
    TreeNode_t* e = malloc(sizeof(TreeNode_t));
    TreeNode_t* f = malloc(sizeof(TreeNode_t));
    TreeNode_t* g = malloc(sizeof(TreeNode_t));
    TreeNode_t* h = malloc(sizeof(TreeNode_t));

    // The root of our tree
    // The root also has two 'branches' a and b.
    start->letter = 's';
    start->lChild = a;
    start->rChild = b;

    a->letter = 'a';
    a->lChild = c;
    a->rChild = d;

    b->letter = 'b';
    b->lChild = e;
    b->rChild = f;

    c->letter = 'c';
    c->lChild = g;
    c->rChild = h;

    // All of the 'leaves' in our tree
    d->letter = 'd';
    d->lChild = NULL;
    d->rChild = NULL;

    e->letter = 'e';
    e->lChild = NULL;
    e->rChild = NULL;

    f->letter = 'f';
    f->lChild = NULL;
    f->rChild = NULL;

    g->letter = 'g';
    g->lChild = NULL;
    g->rChild = NULL;

    h->letter = 'h';
    h->lChild = NULL;
    h->rChild = NULL;

    // Perform the dfs
    dfs(start);

    // Perform the dfs at a different spot)
    dfs(b);

    // TODO: Finish freeTree in dfs.c to free all the nodes
    freeTree(start);

    // Think carefully of the order that nodes should be freed.
    // Use valgrind to make sure that you were successful!
    return 0;
}
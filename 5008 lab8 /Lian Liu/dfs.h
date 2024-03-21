/*
* This file contains the definition of the TreeNode_t struct and
* the function prototypes for the dfs.c file.
* 
* Do NOT modify this file.
*/

// TreeNode_t struct definition
typedef struct TreeNode {
    struct TreeNode* lChild;
    struct TreeNode* rChild;
    char letter;
} TreeNode_t;

// Function prototypes
void dfs(TreeNode_t* start);
void freeTree(TreeNode_t* start);

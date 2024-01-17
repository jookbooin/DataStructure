#include <stdio.h>

typedef struct TreeNode{
    int data;
    struct TreeNode * left, * right;
} TreeNode;


/**
 *      node1
 *     /    \
 *  node2   node3
*/
int main(){

    TreeNode * node1 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode * node2 = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode * node3 = (TreeNode *)malloc(sizeof(TreeNode));

    node1->data = 10;
    node1->left = node2;
    node1->right = node3;

    node2->data = 20;
    node2->left =NULL;
    node2->right = NULL;

    node3->data = 30;
    node3->left =NULL;
    node3->right = NULL;

    free(node1); free(node2); free(node3);
    return 0;
}
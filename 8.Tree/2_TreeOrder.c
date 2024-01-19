#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data ;
    struct TreeNode *left, *right;
} TreeNode;


/**        15
 *    4         20
 * 1         16    25    
*/

TreeNode node4 = { 1, NULL,NULL};
TreeNode node5 = { 16, NULL,NULL};
TreeNode node6 = { 25, NULL,NULL};
TreeNode node2 = { 4, &node4,NULL};
TreeNode node3 = { 20, &node5, &node6};
TreeNode node1 = { 15, &node2,&node3};


void inOrder(TreeNode* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d -> ",root->data);
        inOrder(root->right);
    }

}

void preOrder(TreeNode* root){
    if(root != NULL){
        printf("%d -> ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }

}

void postOrder(TreeNode* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d -> ",root->data);
    }

}

int main(void){


    printf("중위순회\n");
    inOrder(&node1);
    printf("\n");

    printf("전위순회\n");
    preOrder(&node1);
    printf("\n");

    printf("후위순회\n");
    postOrder(&node1);
    printf("\n");
    return 0;
}


#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

/**        15
 *     4         20
 * 1          16    25
 */

TreeNode node4 = {1, NULL, NULL};
TreeNode node5 = {16, NULL, NULL};
TreeNode node6 = {25, NULL, NULL};
TreeNode node2 = {4, &node4, NULL};
TreeNode node3 = {20, &node5, &node6};
TreeNode node1 = {15, &node2, &node3};

int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *np) {
    if (top < SIZE - 1) {
        stack[++top] = np;
    }
}

TreeNode *pop() {
    TreeNode *removed = NULL;  // �ߴ� ����

    if (top >= 0) {            // Stack ���ο� ����
        removed = stack[top--];
    }
    return removed;
}

void inorder_stack(TreeNode *root) {
    while (1) {
        // left
        for (; root; root = root->left) {
            push(root);
        }
        root = pop();

        // stack�� ��� �ִ� ���� ������ NULL
        if (!root) break;

        // mid
        printf("[%d] ", root->data);

        // right
        root = root->right;
    }
}

int main(void) {
    /**
     * �湮 -> push
     * ��� -> pop
     */
    inorder_stack(&node1);
}
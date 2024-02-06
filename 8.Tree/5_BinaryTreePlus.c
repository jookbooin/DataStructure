#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

/**        15
 *     4         20
 * 1          16    25
 *                      30
 */

TreeNode node7 = {30, NULL, NULL};
TreeNode node1 = {1, NULL, NULL};
TreeNode node2 = {4, &node1, NULL};
TreeNode node3 = {16, NULL, NULL};
TreeNode node4 = {25, NULL, &node7};
TreeNode node5 = {20, &node3, &node4};
TreeNode node6 = {15, &node2, &node5};

TreeNode *root = &node6;

int get_node_count(TreeNode *node) {
    int count = 0;
    if (node != NULL) {
        count = 1 + get_node_count(node->left)  // ����Ʈ�� ���� ����
                + get_node_count(node->right);  // ����Ʈ�� ������ ����
    }
    return count;
}

int get_leaf_count(TreeNode *node) {
    int count = 0;

    if (node != NULL) {
        if (node->left == NULL && node->right == NULL)
            return 1;
        else  // �� ���� �� + �� ������ ��
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
    }

    return count;
}

int get_height(TreeNode *node) {
    int height = 0; // ���� �ʱ�ȭ

    if (node != NULL) {
        // �ܺ� ����� ��� ���̸� 0���� ��ȯ
        if (node->left == NULL && node->right == NULL) 
            return 0;
        
        height = 1 + max(get_height(node->left), get_height(node->right));
    }

    return height;
}

int main(void) {
    printf("%d\n", get_node_count(root));
    printf("%d\n", get_leaf_count(root));
    printf("%d\n", get_height(root));

    return 0;
}
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
        count = 1 + get_node_count(node->left)  // 서브트리 왼쪽 개수
                + get_node_count(node->right);  // 서브트리 오른쪽 개수
    }
    return count;
}

int get_leaf_count(TreeNode *node) {
    int count = 0;

    if (node != NULL) {
        if (node->left == NULL && node->right == NULL)
            return 1;
        else  // 맨 왼쪽 끝 + 맨 오른쪽 끝
            count = get_leaf_count(node->left) + get_leaf_count(node->right);
    }

    return count;
}

int get_height(TreeNode *node) {
    int height = 0; // 변수 초기화

    if (node != NULL) {
        // 외부 노드인 경우 높이를 0으로 반환
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
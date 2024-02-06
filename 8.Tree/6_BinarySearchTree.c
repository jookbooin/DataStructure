#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* search(TreeNode* node, int key) {
    if (node == NULL) return NULL;
    if (key == node->key)
        return node;
    else if (key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

TreeNode* new_node(int item) {

    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;

    return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {

    // 트리 공백이면 새로운 노드 반환
    if (node == NULL) 
        return new_node(key);

    // 공백이 아닐시 순환적으로 트리를 내려간다.
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);

    return node;
}

TreeNode* min_value_node(TreeNode* node) {
    TreeNode* current = node;

    // 맨 왼쪽 단말 노드를 찾으러 내려감
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

//키가 주어지면 키가 저장된 노드를 삭제하고, 새로운 루트 노드로 바꾼다.
TreeNode* delete_node(TreeNode* root, int key) {
    if (root == NULL) return root;

    // 왼쪽에서 삭제노드 찾는다.
    if (key < root->key) {
        root->left = delete_node(root->left, key);

    // 오른쪽에서 삭제노드 찾는다.
    } else if (key > root->key) {
        root->right = delete_node(root->right, key);

    // 키가 루트에 있을때
    } else {

            // 오른쪽이 다음 root
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;

            // 왼쪽이 다음 root
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // root 기준 오른쪽에서 가장 작은값
        // root 기준 왼쪽에서 가장 큰값
        TreeNode* temp = min_value_node(root->right);  

        root->key = temp->key; // 특정 key를 root쪽으로 복사하고

        // 오른쪽에서 복사된 값을 가지고 있는 원본을 삭제한다.
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

int main(void) {
    TreeNode* root = NULL;
    TreeNode* tmp = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    inorder(root);
    printf("\n\n");
    if (search(root, 30) != NULL)
        printf("30 발견");
    else
        printf("30 발견못함");

    return 0;
}
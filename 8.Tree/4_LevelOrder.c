#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

/**        15
 *     4         20
 * 1          16    25
 */

TreeNode node1 = {1, NULL, NULL};
TreeNode node2 = {4, &node1, NULL};
TreeNode node3 = {16, NULL, NULL};
TreeNode node4 = {25, NULL, NULL};
TreeNode node5 = {20, &node3, &node4};
TreeNode node6 = {15, &node2, &node5};
TreeNode *root = &node6;

#define MAX_QUEUE_SIZE 100

typedef TreeNode *element;

typedef struct {
    element data[MAX_QUEUE_SIZE];  // TreeNode
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) { q->front = q->rear = 0; }

int is_Empty(QueueType *q) { return q->front == q->rear; }

// 원형 큐 포화 (rear + 1 ) <-> front 위치 동일
int is_full(QueueType *q) { return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); }


/** 
 * 초기 idx = 0 일때는 비어있음
 * enqueue idx = 1 칸에 추가
 * dequeue idx = 1 칸에서 제거
*/
void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        error("가득 찼습니다.");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
    if (is_Empty(q)) {
        error("비어잇습니다.");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void level_Order(TreeNode *pt) {
    QueueType q;
    init_queue(&q);
    if (pt == NULL) return;

    enqueue(&q, pt);
    while (!is_Empty(&q)) {
        pt = dequeue(&q);
        printf("[%d] ", pt->data);
        if (pt->left) enqueue(&q, pt->left);
        if (pt->right) enqueue(&q, pt->right);
    }
}

int main(void) {
    level_Order(root);
    return 0;
}
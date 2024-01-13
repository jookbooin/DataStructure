#include <stdio.h>
#include <stdlib.h>

/**
 * 이중 연결 리스트에서 임의의 노드를 가리키는 포인터 p라 할때
 * p = p->llink->rlink = p->rlink->llink 성립
 */

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = data;
    newNode->llink = before;
    newNode->rlink = before->rlink;

    // before->rlink 노드가 가리키는 llink = newNode가 되도록
    // before->rlink 노드를 newNode로
    
    before->rlink->llink = newNode;  // 필수
    before->rlink = newNode;
    
}

void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf(" < %d > ", p->data);
    }
    printf("\n");
}

int main(void) {
    printf("%d \n", sizeof(DListNode));  // 24

    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    printf("추가 \n");
    for (int i = 0; i < 5; i++) {
        dinsert(head, i);
        print_dlist(head);
    }

    printf("삭제 \n");
    for (int i = 0; i < 5; i++) {
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    free(head);
    return 0;
}

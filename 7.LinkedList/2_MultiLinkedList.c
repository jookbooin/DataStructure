#include <stdio.h>
#include <stdlib.h>

/**
 * ���� ���� ����Ʈ���� ������ ��带 ����Ű�� ������ p�� �Ҷ�
 * p = p->llink->rlink = p->rlink->llink ����
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

    // before->rlink ��尡 ����Ű�� llink = newNode�� �ǵ���
    // before->rlink ��带 newNode��
    
    before->rlink->llink = newNode;  // �ʼ�
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

    printf("�߰� \n");
    for (int i = 0; i < 5; i++) {
        dinsert(head, i);
        print_dlist(head);
    }

    printf("���� \n");
    for (int i = 0; i < 5; i++) {
        print_dlist(head);
        ddelete(head, head->rlink);
    }
    free(head);
    return 0;
}

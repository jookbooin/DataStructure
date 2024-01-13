#include <stdio.h>
#include <stdlib.h>

/**
 * head�� �� �ڿ� ����
 * | insert_first | node | - > | | head | -> | insert_last | node |
 * 
*/
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

// 1.insert_last
ListNode *insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;

    if (head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;  // ó��
        head->link = node;        // ������
        head = node;
    }
    return head;
}

// 2.insert_first
ListNode *insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
    }
    return head;  // head�� �ǵ� , node�� �Ǿտ� �����Ѵ�.
}

void print_list(ListNode *head) {
    ListNode *p;
    if (head == NULL) return;
    p = head->link;  // ���� ����
    while (p != head) {
        printf("%d -> ", p->data);
        p = p->link;
    };
    printf("%d -> \n", p->data);
}

int main(void) {
    printf("%d \n", sizeof(element));     // 4
    printf("%d \n", sizeof(ListNode *));  // 8
    printf("%d \n", sizeof(ListNode));    // 16

    /**
     * ����ü�� '����(padding)
     * ��ǻ�ʹ� �޸𸮸� ȿ�������� ����ϱ� ���� �����͸� �����ϰ�, �� �������� �޸��� �Ϻθ� ����д�.
     * 'ListNode'�� ũ��� padding�� �����Ͽ� 16����Ʈ�� �ȴ�.
     */

    ListNode *head = NULL;

    print_list(head);
    head = insert_last(head, 20);
    print_list(head);
    head = insert_last(head, 30);
    print_list(head);
    head = insert_first(head, 40);
    print_list(head);
    head = insert_first(head, 50);
    print_list(head);
}
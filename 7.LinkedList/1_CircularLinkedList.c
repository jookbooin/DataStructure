#include <stdio.h>
#include <stdlib.h>

/**
 * head는 맨 뒤에 존재
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
        node->link = head->link;  // 처음
        head->link = node;        // 마지막
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
    return head;  // head는 맨뒤 , node는 맨앞에 존재한다.
}

void print_list(ListNode *head) {
    ListNode *p;
    if (head == NULL) return;
    p = head->link;  // 시작 지점
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
     * 구조체의 '정렬(padding)
     * 컴퓨터는 메모리를 효율적으로 사용하기 위해 데이터를 정렬하고, 이 과정에서 메모리의 일부를 비워둔다.
     * 'ListNode'의 크기는 padding을 포함하여 16바이트가 된다.
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
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
    element data; // 4
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// pre노드 뒤에 새로운 노드 삽입
ListNode *insert(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode *delete_first(ListNode *head)
{
    ListNode *removed;
    if (head == NULL)
        return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode *delete(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head)
{
    for (ListNode *p = head; p != NULL; p = p->link)
    {
        printf("%d -> ", p->data);
    }
    printf("NULL \n");
}

// 특정 값 검색
ListNode *search_node(ListNode *head, element value)
{
    ListNode *p = head;

    while (p != NULL)
    {
        if (p->data == value)
            return p;
        p = p->link;
    }
    return NULL;
}

// 리스트 합치기
ListNode * search_node(ListNode *head1, ListNode * head2){

    if(head1 == NULL) return head2;
    else if(head2 == NULL) return head1;
    else{

        ListNode *p;
        p = head1;
        while(p->link != NULL)
            p = p->link;
        p->link = head2;       // head2를 뒤에 붙인다.
        return head1;

    }

}

// 리스트 역순
ListNode * reverse(ListNode * head){
    ListNode *p, *q, *r;

    p = head;
    q = NULL;
    while(p != NULL){
        r = q;

        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

int main(void)
{

    printf("sizeof : %d \n", sizeof(ListNode));
    printf("sizeof : %d \n", sizeof(ListNode *));
    printf("sizeof : %d \n", sizeof(element));

    ListNode *head = NULL;

    print_list(head);
    for (int i = 0; i < 5; i++){
        head = insert_first(head, i);
        print_list(head);
    }

    if (search_node(head, 3) != NULL){
        printf("\n");
        printf("%d 발견 \n\n", search_node(head, 3)->data);
    }else{
        printf("발견 X \n");
    }

    for (int i = 0; i < 5; i++){
        head = delete_first(head);
        print_list(head);
    }

}
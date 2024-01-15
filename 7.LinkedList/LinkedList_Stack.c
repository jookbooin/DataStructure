#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

typedef int element;
typedef struct StackNode {
    element data;
    struct StackNode *link;
} StackNode;

// stack의 top 위치
typedef struct {
    StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s) { s->top = NULL; }

int is_full(LinkedStackType *s) { return 0; }

int is_empty(LinkedStackType *s) { return (s->top == NULL); }

/**
 *  temp    temp (top)
 *   ↓         ↓
 * s(top)      s
 */

void push(LinkedStackType *s, element item) {
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

element pop(LinkedStackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 비어있음");
        exit(1);
    }
    StackNode *temp = s->top;
    int data = temp->data;
    s->top = s->top->link;
    free(temp);
    return data;
}

element peek(LinkedStackType *s) {
    if (is_empty(s)) {
        fprintf(stderr,"스택 비어있음\n");
        exit(1);
    }

    return s->top->data;
}
void print_stack(LinkedStackType *s) {
    for (StackNode *p = s->top; p != NULL; p = p->link) printf("%d -> ", p->data);
    printf("NULL \n");
}

int main(void) {
    LinkedStackType s;
    init(&s);
    push(&s, 1);
    print_stack(&s);
    push(&s, 2);
    print_stack(&s);
    push(&s, 3);
    print_stack(&s);
    push(&s, 4);
    print_stack(&s);
    push(&s, 5);
    print_stack(&s);

    printf("peek : %d\n",peek(&s));
    pop(&s); print_stack(&s);
    printf("peek : %d\n",peek(&s));
    pop(&s); print_stack(&s);
    printf("peek : %d\n",peek(&s));
    pop(&s); print_stack(&s);

    

    return 0;
}
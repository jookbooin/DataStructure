#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {  // �ʱ�ȭ
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);  // heap_size ����

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {  // ���� �ö󰡸鼭 ��
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];  // �� ������ ���  + heap_size 1�� ���̱�
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {

        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))  // �� ū ��� ã�ƾ� ��.
            child++;

        if (temp.key >= h->heap[child].key)  // temp �� child ���� Ŭ�� ���� -> parent �ڸ��� temp ������ ��.
            break;

        // �Ѵܰ� �Ʒ��� �̵�
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;
    return item;  // �����Ϸ��� ���
}

int main(void) {
    element e1 = {10}, e2 = {5}, e3 = {30}, e4 = {20}, e5 = {40}, e6 = {50};
    element e10;

    HeapType* heap;

    heap = create();  // heap �迭 ����
    init(heap);       // heap_size �ʱ�ȭ

    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);
    insert_max_heap(heap, e4);
    insert_max_heap(heap, e5);
    insert_max_heap(heap, e6);

    e10 = delete_max_heap(heap);
    printf("< %d > ", e10.key);

    e10 = delete_max_heap(heap);
    printf("< %d > ", e10.key);

    e10 = delete_max_heap(heap);
    printf("< %d > ", e10.key);

    e10 = delete_max_heap(heap);
    printf("< %d > ", e10.key);

    e10 = delete_max_heap(heap);
    printf("< %d > ", e10.key);

    e10 = delete_max_heap(heap);
    printf("< %d > ", e10.key);

    return 0;
}

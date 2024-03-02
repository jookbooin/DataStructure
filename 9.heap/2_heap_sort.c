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

void init(HeapType* h) {  // 초기화
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);  // heap_size 증가

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {  // 위로 올라가면서 비교
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];  // 맨 마지막 요소  + heap_size 1개 줄이기
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {

        if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))  // 더 큰 요소 찾아야 함.
            child++;

        if (temp.key >= h->heap[child].key)  // temp 가 child 보다 클때 중지 -> parent 자리에 temp 넣으면 됨.
            break;

        // 한단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;
    return item;  // 삭제하려는 요소
}

void heap_sort(element * a, int n){
    
    int i;
    HeapType* h;

    h = create();
    init(h);

    // 배열에서 최댓값만 뽑기 위해 힙에 넣고
    for(int i = 0; i < n; i++){
        insert_max_heap(h, a[i]);
    }

    // 정렬을 위해 pop을 한다.
    for(int i = n-1 ; i>=0 ; i--){
        a[i] = delete_max_heap(h);
    }

    free(h); // heap은 임시로 사용한 것이므로

}

#define SIZE 8

int main(void){

    element list[SIZE] = {23,56,11,9,56,99,27,34};

    heap_sort(list, SIZE); // 배열 원본 수정

    for(int i =0; i< SIZE; i ++){
        printf("%d ", list[i].key);
    }


    return 0;
}
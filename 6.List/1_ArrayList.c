#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 

typedef int element;
typedef struct{
    element array[MAX_LIST_SIZE]; // 배열 정의
    int size;
} ArrayListType;


void init(ArrayListType * list){
    list -> size = 0;
}

void error(char * message){
    fprintf(stderr, "%s\n",message);
    exit(1);
}

// 비어있으면 1 반환
int is_empty(ArrayListType * list){
    return list->size==0;
}

// 가득차있으면 1 반환
int is_full(ArrayListType * list){
    return list->size == MAX_LIST_SIZE;
}

// pos 위치에 요소 추가
void insert(ArrayListType * list, int pos, element item){
    if(!is_full(list) && (pos >= 0) && (pos <= list->size)){
        for(int i = list->size-1; i>=pos ; i--){
            list->array[i+1] = list->array[i];
        }
        list->array[pos] = item;
        list->size++;
    }
}

// 마지막에 추가후 size 증가 
void insert_last(ArrayListType * list, element item){
    if( list->size >= MAX_LIST_SIZE){
        error("리스트 오버플로우");
    }
    list->array[list->size++] = item;
}

// 특정 위치 삭제후 size 감소
element delete(ArrayListType * list, int pos){

    element item;

    if(pos < 0 || pos >= list->size){
        error("위치오류");
    }

    item = list->array[pos];

    for(int i = pos; i< (list->size-1); i++){
        list->array[i] = list->array[i+1];
    }

    list->size--;
    return item;

}

// 바로 배열에 접근가능하기 때문에 O(1)
element get_entry (ArrayListType * list, int pos){
    if(pos < 0 || pos >= list->size){
        error("위치 오류");
    }
    return list->array[pos];
}


void print_list(ArrayListType * list){
    for(int i = 0 ; i< list->size ; i++ ){
        printf("%d -> ", list->array[i]);
    }
    printf("\n");
}


int main(void){

    ArrayListType list;
    init(&list);
    insert(&list , 0, 10); print_list(&list);
    insert(&list , 0, 20); print_list(&list);
    insert(&list , 0, 30); print_list(&list);
    insert_last(&list, 11); print_list(&list);

    delete(&list, 2); print_list(&list);
    delete(&list, 1); print_list(&list);

    return 0;
}
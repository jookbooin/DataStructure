#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 

typedef int element;
typedef struct{
    element array[MAX_LIST_SIZE]; // �迭 ����
    int size;
} ArrayListType;


void init(ArrayListType * list){
    list -> size = 0;
}

void error(char * message){
    fprintf(stderr, "%s\n",message);
    exit(1);
}

// ��������� 1 ��ȯ
int is_empty(ArrayListType * list){
    return list->size==0;
}

// ������������ 1 ��ȯ
int is_full(ArrayListType * list){
    return list->size == MAX_LIST_SIZE;
}

// pos ��ġ�� ��� �߰�
void insert(ArrayListType * list, int pos, element item){
    if(!is_full(list) && (pos >= 0) && (pos <= list->size)){
        for(int i = list->size-1; i>=pos ; i--){
            list->array[i+1] = list->array[i];
        }
        list->array[pos] = item;
        list->size++;
    }
}

// �������� �߰��� size ���� 
void insert_last(ArrayListType * list, element item){
    if( list->size >= MAX_LIST_SIZE){
        error("����Ʈ �����÷ο�");
    }
    list->array[list->size++] = item;
}

// Ư�� ��ġ ������ size ����
element delete(ArrayListType * list, int pos){

    element item;

    if(pos < 0 || pos >= list->size){
        error("��ġ����");
    }

    item = list->array[pos];

    for(int i = pos; i< (list->size-1); i++){
        list->array[i] = list->array[i+1];
    }

    list->size--;
    return item;

}

// �ٷ� �迭�� ���ٰ����ϱ� ������ O(1)
element get_entry (ArrayListType * list, int pos){
    if(pos < 0 || pos >= list->size){
        error("��ġ ����");
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
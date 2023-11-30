#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* insert(struct Node* header, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = x;
    (*temp).next = NULL;
    if (header != NULL){
        (*temp).next = header;
    }
    header = temp;
    return header;
}

void print_list(struct Node* header){
    struct Node* temp = header;
    printf("This list contains: \n");
    printf("%d, ", (*temp).data);
    while ((*temp).next != NULL){
        temp = (*temp).next;
        printf("%d, ", (*temp).data);
    }
}

int access_list(struct Node* header, int index){
    struct Node* temp = header;
    for (int i = 0; i < index & (*temp).next != NULL; i++){
        temp = (*temp).next;
    }
    printf("The value at index %d is %d\n", index, (*temp).data);
    return (*temp).data;
}

int main(void){
    struct Node* header = NULL;
    header = insert(header, 1);
    header = insert(header,2);
    header = insert(header,3);
    header = insert(header,4);
    header = insert(header,5);
    print_list(header);
    access_list(header, 10);
}
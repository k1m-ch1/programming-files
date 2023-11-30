#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(void){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = 0;
    (*temp).next = NULL;
    struct Node* temp1 = temp;
    int list_size;
    printf("Input the size of this list: ");
    scanf("%d", &list_size);
    for (int i = 0; i < list_size; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        (*temp).data = i+1;
        (*temp).next = temp1;
        temp1 = temp;
    }
    printf("The linked list contains: ");
    while ((*temp).next != NULL){
        printf("%d, ", (*temp).data);
        free(temp);
        temp = (*temp).next;
    }




}
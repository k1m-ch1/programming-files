#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int main(void){
    int size_of_list;
    printf("Enter the size of the linked list: ");
    scanf("%d", &size_of_list);
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = temp;
    for (int i = 0; i < size_of_list; i++){
        if (i == 0){
            (*temp).data = i+1;
            (*temp).next = NULL;
        }else{
            struct Node* prev_temp = temp;
            temp = (struct Node*)malloc(sizeof(struct Node));
            (*temp).data = i+1;
            (*temp).next = NULL;
            (*prev_temp).next = temp;
        }
    }
    printf("%d, ", (*head).data);
    while((*head).next != NULL){
        head = (*head).next;
        printf("%d, ", (*head).data);
    }





}
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* push(struct Node* head, int x){
    if(head == NULL){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        (*temp).data = x;
        (*temp).next = NULL;
        return temp;
    }else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        (*temp).data = x;
        (*temp).next = head;
        return temp;
    }
}

struct Node* pop(struct Node* head){
    if(head==NULL){
        printf("NOthing in here\n");
        return head;
    }
    else if((*head).next == NULL){
        head = NULL;
        return head;
    }
    else{
        struct Node* return_head = (*head).next;
        free(head);
        return return_head;
    }
}

void print_top(struct Node* head){
    if(head == NULL){
        printf("Nothing to print sry\n");
        return;
    }
    printf("The top contains %d\n", (*head).data);
}

int main(){
    struct Node* head = NULL;
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);
    head = push(head, 40);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    print_top(head);

}
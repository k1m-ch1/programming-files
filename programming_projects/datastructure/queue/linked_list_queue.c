#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void enqueue(struct Node** head, struct Node** tail, int x){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(*head == NULL & *tail == NULL){
        (*new_node).data = x;
        (*new_node).next = NULL;
        *head = *tail = new_node;
    }
    else{
        (*new_node).data = x;
        (*new_node).next = NULL;
        (**head).next = new_node;
        *head = new_node;
    }
}

int dequeue(struct Node** head, struct Node** tail){
    if(*head == NULL || *tail == NULL){
        printf("The queue is currently empty\n");
        return NULL;
    }
    else if(*head == *tail){
        int return_value = (**tail).data;
        free(*head);
        *head = *tail = NULL;
        return return_value;
    }
    else{
        struct Node* temp = (**tail).next;
        int return_value = (**tail).data;
        free(*tail);
        *tail = temp;
        return return_value;
    }
}

int main(void){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    enqueue(&head, &tail, 10);
    enqueue(&head, &tail, 20);
    enqueue(&head, &tail, 30);
    for(int i = 0; i < 4; i++){
        printf("%d\n", dequeue(&head, &tail));
    }

}
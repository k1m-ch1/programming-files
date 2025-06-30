#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* insert_at_beginning(struct Node* head, int x);
struct Node* insert_at_end(struct Node* head, int x);
void print_list(struct Node* head, int index);

int main(void){
    struct Node* head = NULL;
    for (int i = 0; i < 10; i ++){
        head = insert_at_end(head, i);
    }
    print_list(head, 20);
    return 0;

}

struct Node* insert_at_beginning(struct Node* head, int x){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL){
        (*new_node).data = x;
        (*new_node).next = new_node;
        return new_node;
    }
    (*new_node).next = (*head).next;
    (*head).next = new_node;
    (*new_node).data = x;
    return head;
}
struct Node* insert_at_end(struct Node* head, int x){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(head == NULL){
        (*new_node).data = x;
        (*new_node).next = new_node;
        return new_node;
    }
    (*new_node).next = (*head).next;
    (*head).next = new_node;
    head = new_node;
    (*new_node).data = x;
    return head;
}

void print_list(struct Node* head, int index){
    struct Node* temp = head;
    printf("\nThis list contains: \n");
    for (int i = 0; i < index; i++){
        printf("%d, ", (*temp).data);
        temp = (*temp).next;
    }
}
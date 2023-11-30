#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Head{
    struct Node* start;
    struct Node* end;
};

void insert_beginning(struct Head* head, int x);
void print_list(struct Node* head);
struct Node* get_end(struct Node* head);
void print_list_reverse(struct Node* head);
void delete(struct Head* head, int index);
void insert_at(struct Head* head, int index, int x);

int main(void){
    struct Head* head = (struct Head*)malloc(sizeof(struct Head));
    (*head).start = NULL;
    (*head).end = NULL;
    for (int i = 0; i < 10; i++){
        insert_beginning(head, i);
    }
    print_list((*head).start);
    insert_at(head, 3, 2);
    print_list((*head).start);
    print_list_reverse((*head).end);

}

void insert_beginning(struct Head* head, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if ((*head).start == NULL){
        (*temp).prev = NULL;
        (*temp).data = x;
        (*temp).next = NULL;
        (*head).start = temp;
        (*head).end = temp;
    }
    else{
        (*((*head).start)).prev = temp;
        (*temp).data = x;
        (*temp).prev = NULL;
        (*temp).next = (*head).start;
        (*head).start = temp;
    }
}


void print_list(struct Node* head){
    printf("\nThis linked list contains: \n");
    while(head != NULL){
        printf("%d, ", (*head).data);
        head = (*head).next;
    }
}

void print_list_reverse(struct Node* head){
    printf("\nThis linked list contains: \n");
    while(head != NULL){
        printf("%d, ", (*head).data);
        head = (*head).prev;
    }
}

struct Node* get_end(struct Node* head){
    while((*head).next != NULL){
        head = (*head).next;
    }
    return head;
}

void delete(struct Head* head, int index){
    struct Node* temp = (*head).start;
    if((*head).start == NULL|| (*head).end == NULL){
        printf("\nList is empty");
        return;
    }
    if (index == 0){
        (*((*temp).next)).prev = NULL;
        (*head).start = (*temp).next;
        free(temp);
        return;
    }
    for (int i = 0; i < index; i++){
        if ((*temp).next == NULL){
            (*((*temp).prev)).next = NULL;
            (*head).end = (*temp).prev;
            free(temp);
            return;
        }
        temp = (*temp).next;
        }
    (*((*temp).prev)).next = (*temp).next;
    (*((*temp).next)).prev = (*temp).prev;
    free(temp);
    return;
}


void insert_at(struct Head* head, int index, int x){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = (*head).start;
    if (temp == NULL){
        (*new_node).prev = NULL;
        (*new_node).data = x;
        (*new_node).next = NULL;
        return;
    }
    else if (index == 0){
        (*temp).prev = new_node;
        (*new_node).prev = NULL;
        (*new_node).data = x;
        (*new_node).next = (*head).start;
        (*head).start = new_node;
        return;
    }
    else{
        for (int i = 0; i < index; i++){
            if((*temp).next == NULL){
                (*temp).next = new_node;
                (*new_node).next = NULL;
                (*new_node).data = x;
                (*new_node).prev = (*head).end;
                (*head).end = new_node;
                return;
            }
            temp = (*temp).next;
        }
        (*new_node).prev = (*temp).prev;
        (*((*temp).prev)).next = new_node;
        (*new_node).data = x;
        (*temp).prev = new_node;
        (*new_node).next = temp;
        return;
    }
}
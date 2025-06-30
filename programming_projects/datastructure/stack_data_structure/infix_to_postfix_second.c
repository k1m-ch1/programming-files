#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node* next;
};

void push(struct Node** head, char x){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(*head == NULL){
        (*new_node).data = x;
        (*new_node).next = NULL;
        *head = new_node;
    }
    else{
        (*new_node).data = x;
        (*new_node).next = *head;
        *head = new_node;
    }
}

char pop(struct Node** head){
    if(*head == NULL){
        printf("You are worth nothing!\nYou should kill yourself NOW!\n");
        return NULL;
    }else{
        struct Node* temp = *head;
        *head = (*temp).next;
        free(temp);
        return (*(*head)).data;
    }
}

int isEmpty(struct Node* head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

char peak(struct Node* head){
    if(head == NULL){
        return '\0';
    }else{
        return (*head).data;
    }
}

int main(void){
    struct Node* head = NULL;
    char* a = "5+4+8*8*7-9+23*23";
    int input_len = strlen(a);
    char* results = (char*)malloc(sizeof(char)*input_len);
    int results_len = 0;
    for (int i = 0; i < input_len-2; i++){
        char current = a[i];
        if(current == '+' || current == '-' & isEmpty(head) == 1){
            push(&head, current);
        }
        else if(current == '+' || current == '-' & isEmpty(head) == 0){
            while(head != NULL){
                char operator = pop(&head);
                results_len = results_len + 1;
                results[results_len-1] = operator;
            }
        }
        else if(current == '*' || current == '/'){
            push(&head, current);
        }
        else{
            results_len = results_len + 1;
            results[results_len-1] = current;
        }
    }
    results_len = results_len + 1;
    results[results_len-1] = a[input_len-1];
    while(head != NULL){
        results_len = results_len + 1;
        results[results_len-1] = pop(&head);
    }
    printf("%c", results[0]);
    return 0;
}


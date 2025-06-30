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
        return '\0';
    }else{
        struct Node* temp = *head;
        *head = (*temp).next;
        char return_data = (*temp).data;
        free(temp);
        return return_data;
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

int stack_size(struct Node* head){
    int i = 0;
    while(head != NULL){
        head = (*head).next;
        i++;
    }
    return i;
}

char* infix_to_postfix(char* expression){
    int expression_len = strlen(expression);
    struct Node* temp_stack = NULL;
    int size_to_malloc = sizeof(char)*(expression_len)+sizeof(char)*expression_len/2 +sizeof(char)*3;
    char* results = (char*)malloc(size_to_malloc);
    int next_free_index = 0;
    for(int i = 0; i < expression_len-1; i++){
        char current = expression[i];
        if(current == '+' || current == '-'){
            results[next_free_index] = ',';
            next_free_index++;
            if(peak(temp_stack)=='\0' || peak(temp_stack) == '*' || peak(temp_stack) == '/'){
                while(temp_stack != NULL){
                    results[next_free_index] = pop(&temp_stack);
                    next_free_index++;
                }
            }
            push(&temp_stack, current);
        }
        else if(current == '*' || current == '/'){
            results[next_free_index] = ',';
            next_free_index++;
            push(&temp_stack, current);
        }
        else{
            results[next_free_index] = current;
            next_free_index++;
        }
    }
    results[next_free_index] = expression[strlen(expression)-1];
    next_free_index++;
    while(temp_stack != NULL){
        results[next_free_index] = pop(&temp_stack);
        next_free_index++;
    }
    results[next_free_index] = '\0';
    next_free_index++;
    return results;
}

int main(void){
    struct Node* head = NULL;
    char *word = "10-9*7+9*7-45";
    char* results_real = infix_to_postfix(word);
    printf("%s", results_real);
    return 0;
}
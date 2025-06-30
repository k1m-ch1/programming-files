#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node* next;
};

struct Node* push(struct Node* head, char x){
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

char get_top(struct Node* head){
    if(head == NULL){
        return '\0';
    }
    return (*head).data;

}

char* reverse(char* str){
    struct Node* head = NULL;
    char* new_string;
    for (int i = 0, len = strlen(str); i < len; i++){
        head = push(head, *(str+i));
    }
    for (int i = 0, len = strlen(str); i < len; i++){
        new_string[i] = (*head).data;
        head = pop(head);
    }
    new_string[strlen(str)] = '\0';
    return new_string;

}

int is_balanced(char* a){
    int len = strlen(a);
    struct Node* head = NULL;
    for(int i = 0; i < len; i++){
        char char_rn = *(a+i);
        if(char_rn == '(' || char_rn == '[' || char_rn == '{'){
            head = push(head, char_rn);
        }else if(char_rn == ')' || char_rn == ']' || char_rn == '}'){
            if (head == NULL){
                return 0;
            }
            else if(char_rn == ')' & (*head).data != '('){
                return 0;
            }
            else if(char_rn == ']' & (*head).data != '['){
                return 0;
            }
            else if(char_rn == '}' & (*head).data != '{'){
                return 0;
            }else{
                head = pop(head);
            }
        }
    }
    if(head == NULL){
        return 1;
    }
    return 0;
}


int main(){
    char *stuff = "}";
    printf("%d", is_balanced(stuff));

    

}
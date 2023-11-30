#include <stdio.h>
#include <stdlib.h>

//tihs sis garbage ong fr


struct Node{
    int data;
    struct Node* next;
};

void insert(struct Node** head, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(*head == NULL){
        (*temp).data = x;
        (*temp).next =NULL;
        *head = temp;
    }else{
        (*temp).data = x;
        (*temp).next = *head;
        *head = temp;
    }
}

void delete_top(struct Node** head){
    struct Node* temp = *head;
    if(temp == NULL){
        printf("There isn't shit to delete\n");
    }
    else if((*temp).next == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        free(*head);
        *head = (*temp).next;
    }
}

char pop(struct Node** head){
    if(head == NULL){
        return NULL;
    }else{
        struct Node* temp = *head;
        free(*head);
        *head = (*temp).next;
    }
}

int peak(struct Node* head){
    if(head == NULL){
        return NULL;
    }
}

int is_empty(struct Node* head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    struct Node* head = NULL;
    char* input = "4+3+2*8*12-21*4";
    int input_len = strlen(input);
    char* output = (char*)malloc(sizeof(char)*input_len);
    for(int i = 0; i < input_len-1; i++){
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
            if(input[i] == '+' || input[i] == '-' & is_empty(head) == 1){
                insert(head, (int)input[i]);
            }
            else if(input[i] == '*' || input[i] == '/'){
                insert(head, (int)input[i]);
            }
            else if(input[i] == '+' || input[i] == '-' & is_empty(head) == 0){
                
            }

        }

    }
    return 0;
}
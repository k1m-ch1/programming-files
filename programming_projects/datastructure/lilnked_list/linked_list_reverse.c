#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void print_list(struct Node* header);
void print_list_recursion(struct Node* header);
void print_list_reverse(struct Node* header);
struct Node* reverse_recursion(struct Node* header);
struct Node* insert_at(struct Node* header, int x, int index);
struct Node* delete_at(struct Node* header, int index);
struct Node* reverse(struct Node* header);


int main(void){
    struct Node* header = NULL;
    for (int i = 0; i < 10 ; i++){
        header = insert_at(header, i, i);
    }
    print_list_recursion(header);
    printf("\n");
    header = reverse_recursion(header);
    printf("\n");
    print_list_recursion(header);
    


}

struct Node* insert_at(struct Node* header, int x, int index){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    (*new).data = x;
    if (index == 0 || header == NULL){
        (*new).next = header;
        header = new;
        return header;
    } 
    else {
        struct Node* point = header;
        struct Node* prev_point;
        for (int i = 0; i < index & point != NULL; i++){
            prev_point = point;
            point = (*point).next;
        }
        (*prev_point).next = new;
        (*new).next = point;
        return header;
    }
}

void print_list(struct Node* header){
    struct Node* temp = header;
    printf("\nThis list contains: \n");
    printf("%d, ", (*temp).data);
    while ((*temp).next != NULL){
        temp = (*temp).next;
        printf("%d, ", (*temp).data);
    }
}

struct Node* delete_at(struct Node* header, int index){
    if (header == NULL){
        return header;
    }
    else if(index == 0){
        struct Node* new_header = (*header).next;
        free(header);
        return new_header;
    }
    else{
        struct Node* prev_value;
        struct Node* temp = header;
        for (int i = 0; i < index; i++){
            prev_value = temp;
            temp = (*temp).next;
        }
        (*prev_value).next = (*temp).next;
        free(temp);
        return header;
    }
}

struct Node* reverse(struct Node* header){
    struct Node* prev_temp = NULL;
    struct Node* temp = header;
    struct Node* next;
    while (temp != NULL){
        next = (*temp).next;
        (*temp).next = prev_temp;
        prev_temp = temp;
        temp = next;
    }
    return prev_temp;
}

void print_list_recursion(struct Node* header){
    struct Node* ptr = header;
    if (ptr == NULL){
        return;
    }
    printf("%d, ", (*ptr).data);
    print_list_recursion((*ptr).next);
}


void print_list_reverse(struct Node* header){
    if(header == NULL){
        return;
    }
    print_list_reverse((*header).next);
    printf("%d, ", (*header).data);
}

struct Node* reverse_recursion(struct Node* header){
    if((*header).next == NULL){
        return header;
    }
    struct Node* new_header = reverse_recursion((*header).next);
    struct Node* temp = header;
    struct Node* prev_temp;
    while((*temp).next != NULL){
        prev_temp = temp;
        temp = (*temp).next;
    }
    (*temp).next = prev_temp;
    (*prev_temp).next = NULL;
    return new_header;
}
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void print_list(struct Node* header);
struct Node* insert_at(struct Node* header, int x, int index);
struct Node* delete_at(struct Node* header, int index);


int main(void){
    struct Node* header = NULL;
    for (int i = 0; i < 10 ; i++){
        header = insert_at(header, i, i);
    }
    print_list(header);
    header = delete_at(header, 0);
    header = delete_at(header, 4);
    print_list(header);

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

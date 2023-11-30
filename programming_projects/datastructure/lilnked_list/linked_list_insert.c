#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void print_list(struct Node* header);
struct Node* insert_at(struct Node* header, int x, int index);

int main(void){
    struct Node* header;
    header = insert_at(header, 10, 10);
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
    printf("This list contains: \n");
    printf("%d, ", (*temp).data);
    while ((*temp).next != NULL){
        temp = (*temp).next;
        printf("%d, ", (*temp).data);
    }
}


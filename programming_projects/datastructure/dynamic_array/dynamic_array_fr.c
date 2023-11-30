#include <stdio.h>
#include <stdlib.h>

struct D_array{
    int size;
    int* ptr;
};

struct D_array* new_array();
void insert(struct D_array* a, int data);
void print(struct D_array* a);

int main(){
    struct D_array* a = new_array();
    insert(a, 10);
    insert(a, 20);
    insert(a, 30);
    insert(a, 40);
    insert(a, 50);
    int* num_at_i_two = (*a).ptr+2;
    printf("The number at index two contains %d", *num_at_i_two);

}

struct D_array* new_array(){
    struct D_array* ptr_to_a = (struct D_array*)malloc(sizeof(struct D_array));
    (*ptr_to_a).size = 0;
    (*ptr_to_a).ptr = NULL;
    return ptr_to_a;
}

void insert(struct D_array* a, int data){
    if((*a).ptr == NULL){
        (*a).ptr = (int*)malloc(sizeof(int));
        *((*a).ptr) = data;
        (*a).size = 1;
        return;
    }
    else{
        int new_size = (*a).size + 1;
        int* temp = (int*)malloc(sizeof(int) * new_size);
        for(int i = 0; i < (*a).size; i++){
            temp[i] = ((*a).ptr)[i];
        }
        temp[new_size-1] = data;
        printf("\n-------------------------------------------\n");
        free((*a).ptr);
        (*a).ptr = temp;
        (*a).size = new_size;
        return;
    }

}

void print(struct D_array* a){
    printf("This list contains: \n");
    for (int i = 0; i < (*a).size; i++){
        printf("%d, ", *((*a).ptr + i));

    }
}
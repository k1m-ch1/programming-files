#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Array_Info{
    int* ptr;
    int size;
};

void allocate_array(struct Array_Info* array, int size){
    (*array).ptr = (int*)malloc(sizeof(int)*size);
    (*array).size = size;
}

void insert_random(struct Array_Info* array, int range){
    if((*array).ptr == NULL || (*array).size == 0){
        return;
    }
    else{
        srand(time(NULL));
        for(int i = 0; i < (*array).size; i++){
            (*array).ptr[i] = (rand()+1)%range;
        }
    }
}

void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(struct Array_Info* array){
    int size = (*array).size;
    for(int i = 1; i < size; i++){
        int j = 0;
        int current = (*array).ptr[i];
        while(j < i && current > (*array).ptr[j]){
            j++;
        }
        for(int k = i; k >= j; k--){
            (*array).ptr[k] = (*array).ptr[k-1];
        }
        (*array).ptr[j] = current;
    }
}

struct Array_Info* bubble_sort(struct Array_Info* array){
    struct Array_Info* new_array = (struct Array_Info*)malloc(sizeof(struct Array_Info));
    allocate_array(new_array, (*array).size);
    for(int i = 0; i < (*array).size; i++){
        (*new_array).ptr[i] = (*array).ptr[i];
    }
    for(int i = 0; i < (*new_array).size - 1; i++){
        for(int j = 0; j < (*new_array).size - i - 1; j++){
            if((*new_array).ptr[j] > (*new_array).ptr[j+1]){
                swap((*new_array).ptr + j, (*new_array).ptr + j + 1);
            }
        }
    }
    return new_array;
}

void print_array(struct Array_Info temp, int new_line){
    for(int i = 0; i < temp.size; i++){
        printf("%d, ", temp.ptr[i]);
        if((i+1)%new_line == 0){
            printf("\n");
        }
    }
}

int main(){
    struct Array_Info new_array;
    allocate_array(&new_array, 1000);
    insert_random(&new_array, 10000);
    struct Array_Info* bubble_sorted_array = bubble_sort(&new_array);
    insertion_sort(&new_array);
    printf("\nBubble sorted array: \n");
    print_array(*bubble_sorted_array, 15);
    printf("\nInsertion sorted array: \n");
    print_array(new_array, 15);

}
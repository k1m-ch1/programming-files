#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Array_Info{
    int* ptr;
    int size;
};

void allocate_array(struct Array_Info* temp, int size){
    (*temp).ptr = (int*)malloc(sizeof(int)*size);
    (*temp).size = size;
}

void random_nums(struct Array_Info* temporary, int max){
    if(temporary -> ptr == NULL || temporary -> size == 0){
        return;
    }
    srand(time(NULL));
    for(int i = 0; i < temporary -> size; i++){
        temporary -> ptr[i] = rand() % max+1;
    }
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct Array_Info* array){
    if((*array).size < 2){
        return;
    }
    int exit = 0;
    while(exit != 1){
        exit = 1;
        for(int i = 0; i < (*array).size - 1; i++){
            int* current = (*array).ptr + i;
            int* next = (*array).ptr + i + 1;
            if(*current > *next){
                swap(current, next);
                exit = 0;
            }
        } 
    }
}

int main(){
    struct Array_Info new_array;
    new_array.ptr = NULL;
    new_array.size = 0;
    allocate_array(&new_array, 1000);
    random_nums(&new_array, 1000);
    sort(&new_array);
    for(int i = 0; i < new_array.size; i++){
        printf("%d, ", new_array.ptr[i]);
        if(i%10 == 0){
            printf("\n");
        }
    }
}
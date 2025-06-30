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

void bubble_sort(struct Array_Info* array){
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

void merge(struct Array_Info left, struct Array_Info right, struct Array_Info all){
    int index_l = 0; int index_r = 0; int index_all = 0;
    while(index_l < left.size && index_r < right.size){
        if(left.ptr[index_l] < right.ptr[index_r]){
            all.ptr[index_all] = left.ptr[index_l];
            index_l++;
        }else{
            all.ptr[index_all] = right.ptr[index_r];
            index_r++;
        }
        index_all++;
    }
    while(index_l < left.size){
        all.ptr[index_all] = left.ptr[index_l];
        index_l++;
        index_all++;
    }
    while(index_r < right.size){
        all.ptr[index_all] = right.ptr[index_r];
        index_r++;
        index_all++;
    }
}

void merge_sort(struct Array_Info array){
    if(array.size == 1){
        return;
    }
    struct Array_Info left;
    struct Array_Info right;
    left.size = array.size/2;
    right.size = array.size - left.size;
    left.ptr = (int*)malloc(sizeof(int)*(int)left.size);
    right.ptr = (int*)malloc(sizeof(int)*(int)right.size);
    for(int i = 0; i < left.size; i++){
        left.ptr[i] = array.ptr[i];
    }
    for(int i = 0; i < right.size; i++){
        right.ptr[i] = array.ptr[i+left.size];
    }
    merge_sort(left);
    merge_sort(right);
    merge(left, right, array);
}

int main(){
    struct Array_Info new_array;
    allocate_array(&new_array, 1000);
    random_nums(&new_array, 10000); 
    merge_sort(new_array);
    for(int i = 0; i < new_array.size; i++){
        printf("%d, ", new_array.ptr[i]);
        if((i+1)%10 == 0){
            printf("\n");
        }
    }
}

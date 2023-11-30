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

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubble_sort_fast(struct Array_Info* array){
    int j = (*array).size;
    int counter = 0;
    for(int i = 0; i < (*array).size; i++){
        j--;
        for(int k = 0; k < j; k++){
            if((*array).ptr[k]>(*array).ptr[k+1]){
                counter++;
                swap((*array).ptr + k, (*array).ptr + k + 1);
            }   
        }
    }
    return counter;
}

int main(void){
    clock_t start_time = clock();
    struct Array_Info new_array;
    new_array.ptr = NULL;
    new_array.size = 0;
    allocate_array(&new_array, 1000);
    insert_random(&new_array, 1000);
    int count = bubble_sort_fast(&new_array);
    for(int i = 0; i < new_array.size; i++){
        printf("%d, ", new_array.ptr[i]);
        if((i+1)%10 == 0){
            printf("\n");
        }
    }
    printf("\n%d swaps needed\n", count);
    printf("\nStart time is %d and end time is %d", (int)start_time, (int)clock());
    printf("\nTotal running time is %d\n", (int)clock() - (int)start_time);

}
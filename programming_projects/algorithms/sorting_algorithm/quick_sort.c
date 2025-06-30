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

int partition(int low, int high, int* array){
    int piviot = array[high];
    int p_index = 0;
    for(int i = p_index; i < high; i++){
        if(array[i] <= piviot){
            swap(array+i, &array[p_index]);
            p_index++;
        }
    }
    swap(&array[p_index], &array[high]);
    return p_index;
}

void quick_sort(int low, int high, int* array){
    if(low < high){
        int sorted_index = partition(low, high, array);
        quick_sort(low, sorted_index-1, array);
        quick_sort(sorted_index+1, high, array);
    }
}

int main(void){
    struct Array_Info a;
    allocate_array(&a, 1000);
    random_nums(&a, 10000);
    quick_sort(0, a.size-1, a.ptr);
    for(int i = 0; i < a.size; i++){
         printf("%d, ", a.ptr[i]); 
         if((i+1)%10 == 0){
            printf("\n");
         }
    }


    return 0;
}
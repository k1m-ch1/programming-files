#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


struct Array_Info{
  int* array_head;
  int size_of_array;
};

void swap(int* x, int* y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

struct Array_Info* create_array(int size_of_array){
  struct Array_Info* new_array = (struct Array_Info*)malloc(sizeof(struct Array_Info));
  (*new_array).array_head = (int*)malloc(sizeof(int)*size_of_array);
  (*new_array).size_of_array = size_of_array;
  return new_array;
}

void generate_nums(int max, struct Array_Info* target_array){
  for(int i = 0; i < (*target_array).size_of_array; i++){
    (*target_array).array_head[i] = (rand() + max + 1)%max;
  }
}

void print_all_nums(struct Array_Info * target_array){
  for(int i = 0; i < (*target_array).size_of_array; i++){
    printf("%d, ", (*target_array).array_head[i]);
    if ((i+10+1)%10 == 0){
      printf("\n");
    }
  }
}

void bubble_sort(struct Array_Info* target_array){
  for(int i = 0; i < target_array->size_of_array; i++){
    for(int j = 1; j < target_array->size_of_array-i; j++){
      if ((*target_array).array_head[j-1] >= (*target_array).array_head[j]){
        swap((*target_array).array_head+j-1, (*target_array).array_head+j);
      }
    }
  }
}



int main(void){
  struct Array_Info* my_array_info = create_array(100);
  time_t morbin_time;
  time(&morbin_time);
  srand(morbin_time*99);
  generate_nums(10000, my_array_info);
  bubble_sort(my_array_info);
  print_all_nums(my_array_info);

  return 0;
}
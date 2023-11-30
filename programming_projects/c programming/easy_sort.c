#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort_array(int array_size, int* array_ptr){
	for (int i = 0; i < array_size; i++){
		for(int j = i; j < array_size; j++){
			if (array_ptr[i] > array_ptr[j]){
				swap(array_ptr + i, array_ptr + j);
			}
		}
	}
}

int main(int argc, char** argv){
	int array_size = 100;
	int my_array[array_size];

	printf("Unsorted Array: \n");
	for(int i = 0; i < array_size; i++){
		my_array[i] = rand();
		printf("%i, \n", my_array[i]);
	}

	sort_array(array_size, my_array);

	printf("Sorted Array: \n");

	for(int i = 0; i < array_size; i++){
		printf("%i, \n", my_array[i]);
	}


	return 0;
}
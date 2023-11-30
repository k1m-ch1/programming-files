#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *ptr_to_array = (int*)malloc(5*sizeof(int));
    printf("List of malloc contains: \n");
    for (int i=0; i<5; i++){
        *(ptr_to_array+i) = i*3;
        printf("%d\n", *(ptr_to_array+i));
    }
    printf("List of realloc contains: \n");
    int *realloc_address = (int*)realloc(ptr_to_array,4);
    for (int i=0; i<10; i++){
        printf("%d\n", *(realloc_address+i));
    }
    printf("The address of prev ptr is %p, The address of reallocated ptr is at %p\n", ptr_to_array, realloc_address);
    printf("The value store din ptr_to_array is %d", *(ptr_to_array+4));

}
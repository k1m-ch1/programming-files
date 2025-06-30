#include <stdio.h>
#include <stdlib.h>

int main(void){
    int* ptr; 
    ptr = (int*)malloc(sizeof(int));
    printf("%d\n", *ptr);
    *ptr = 10;
    printf("%d\n", *ptr);
    free(ptr);
    printf("%d", *ptr);
 
}
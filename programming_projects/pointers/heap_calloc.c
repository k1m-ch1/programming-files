#include <stdio.h>
#include <stdlib.h>

int main(void){
    int* a = (int*)calloc(1, sizeof(int));
    printf("%d\n", *a);
    *a = 15;
    printf("%d\n", *a);
    free(a);
    printf("%d\n", *a);
}
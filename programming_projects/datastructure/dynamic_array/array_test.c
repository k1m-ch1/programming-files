#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[] = {12,21,232,3232,32323,444,3};
    int* b = (int*)malloc(sizeof(int)*7);
    for (int i = 0; i < 7; i++){
        *(b+i) = a[i];
    }
    for(int i = 0; i < 7; i++){
        printf("%d, ", b[i]);
    }
    free(b);
    for(int i = 0; i < 7; i++){
        printf("\n%d, ", *(b + i));
    }


}
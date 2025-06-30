#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a = malloc(3*sizeof(int));
    *a = 12;
    printf("%d", *a);
    free(a);
    printf("%d", *(a+0));
    printf("%d", *(a+1));

}
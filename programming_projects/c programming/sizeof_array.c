#include <stdio.h>

int main(void){
    int a[] = {1,2,3,4,5};
    printf("%d",(int)sizeof(a));
    printf("\n%d",*(a+1));
}
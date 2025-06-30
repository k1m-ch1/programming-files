#include <stdio.h>

int main(void){
    int a[] = {0,1,2,3,4,5,6,7,8,9,0};
    int* ptr = a;
    printf("The size of a is %d\n", sizeof(a));
    printf("The size of ptr is %d\n", sizeof(a));
}
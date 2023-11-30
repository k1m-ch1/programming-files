#include <stdio.h>

int main(void){
    int a = 5;
    int *ptr = &a;

    printf("The address of ptr to value is: %p", ptr);
    printf("\nThe value stored in ptr is: %d", *ptr);
    printf("\nThe address of ptr to value plus one is: %p", ptr+1);
    printf("\nThe value stored in ptr plus one is: %d", *(ptr+1));
    printf("\nThe size of an integer is: %d",(int)sizeof(int));

}
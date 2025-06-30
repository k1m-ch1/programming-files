#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a = 9;
    int *ptr = &a;
    printf("\nThe value stored in a is %d",a);
    printf("\nThe address of a is stored in ptr contains address %p",ptr);
    printf("\nPtr points to the address which contains this value: %d",*ptr);
    printf("\nThe address of the pointer is %p", &ptr);
    *ptr = 10;
    printf("\nThe value of a is now %d",a);
    printf("\n The address of a is stored in ptr that contains address %p",ptr);
    printf("\nPtr points to the address which contains this value: %d",*ptr);
    printf("\nThe address of the pointer is %p", &ptr);
    



}
#include <stdio.h>

int main(void){

    int x = 10;
    int* ptr = &x;
    int** ptr_to_ptr = &ptr;
    int*** ptr_to_ptr_to_ptr = &ptr_to_ptr;
    printf("\nAddress x using ptr %p", ptr); // give the address of x
    printf("\nValue x using ptr %d",*ptr); // gives the value of x
    printf("\nAddress of ptr %p",&ptr); // gives the address of ptr
    printf("\n");
    printf("\nAddress of ptr using ptr_to_ptr: %p", ptr_to_ptr); //gives the address of ptr
    printf("\nDereferencing ptr_to_ptr (*ptr_to_ptr) %p", *ptr_to_ptr); //gives the address of x
    printf("\nDereferencing twice (**ptr_to_ptr) %d", **ptr_to_ptr); //gives the value of x
    printf("\nAddress of ptr_to_ptr %p", &ptr_to_ptr);
    printf("\n");
    printf("\nAddress stored in ptr to ptr to ptr %p",ptr_to_ptr_to_ptr); // gies the address of ptr_to_ptr
    printf("\nAddress stored in *ptr_to_ptr_to_ptr %p",*ptr_to_ptr_to_ptr); // gives the value stored in ptr _to ptr or the address of ptr
    printf("\nAddress of ptr %p", **ptr_to_ptr_to_ptr); // gives the value stored in ptr or the address of x
    printf("\nAddress stored in ptr %d", ***ptr_to_ptr_to_ptr); // gives the value of x


    return 0;
}
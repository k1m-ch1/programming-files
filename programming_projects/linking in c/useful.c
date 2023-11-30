#include <stdio.h>
#include "header.h"

int main(void){
    print_hello_world();
    for(int i = 0; i < 15; i++){
        printf("The factorial of %d is %llu\n", i, factorial(i));
    }
}
#include <stdio.h>
#include "header.h"

void print_hello_world(void){
    printf("Hello, world!\n");
}

unsigned long long factorial(int data){
    unsigned long long sum = 1;
    for(int i = 1; i <= data; i++){
        sum = sum * i;
    }
    return sum;
}


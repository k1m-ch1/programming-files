#include <stdio.h>
#include <stdlib.h>

void print_aot_is_bad(){
    int x = 12;
    int y = 495;
    int z = 8904;
    printf("\n AOT IS CLEARLY ONE OF THE SHOWS OF THIS ERA");
    printf("\n %d %d %d", x, y, z);
}

int* add(int* x, int* y){
    int* c = (int*)malloc(sizeof(int));
    *c = *x + *y;
    return c;
}

int main(void){
    int a = 1000;
    int b = 1000;
    int* result;
    result = add( &a, &b);
    print_aot_is_bad();
    printf("\nThe sum of those two numbers is %d", *result);

    
}
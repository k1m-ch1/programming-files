#include <stdio.h>


void swap(int*a, int*b);

int main(void){
    char* x_value = "x contains this value: ";
    char* y_value = "y contains this value: ";
    
    int x = 10;
    int y = 20;

    printf("\n%s %d",x_value,x);
    printf("\n%s %d",y_value,y);
    swap(&x,&y);
    printf("\n%s %d",x_value,x);
    printf("\n%s %d",y_value,y);

    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
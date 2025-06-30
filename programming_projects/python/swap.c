#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int x,y;
    x = 1;
    y = 2;
    swap(&x,&y);
    printf("X contains %d, Y contains %d", x, y);
}
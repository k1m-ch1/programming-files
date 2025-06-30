#include <stdio.h>
#include <stdlib.h>

void print_aot_is_bad(){
    printf("\nAttack on titan is one of the shows of all time");
}

int* add(int x, int y){
    int* sum = (int*)malloc(sizeof(int));
    *sum = x + y;
    return sum;
}

int main(void){
    void (*ptr)(void) = *print_aot_is_bad;
    int* (*ptr_to_add)(int, int) = *add;
    ptr();
    int sum = *(ptr_to_add(10,10));
    printf("\nThe sum of 10 plus 10 is %d", sum);
    return 0;


}
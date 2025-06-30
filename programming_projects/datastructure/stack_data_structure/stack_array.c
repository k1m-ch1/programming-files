#include <stdio.h>
#include <stdlib.h>

void push(int* a, int x, int* top){
    (*top) = (*top) + 1;
    a[*top] = x;
}

void pop(int *a, int* top){
    if ((*top) < 0){
        printf("This ting is empty :(\n");
        return;
    }else{
    (*top) = (*top) - 1;
    }
}

void top_f(int *a, int top){
    if (top < 0){
        printf("This thin is empty\n" );
        return;
    }else{
        printf("\nTop is at position %d and contains %d\n", top, a[top]);
    }
}




int main(void){
    int top = -1;
    int a[100];
    push(a, 12, &top);
    push(a, 10, &top);
    pop(a, &top);
    push(a, 13, &top);
    push(a, 20, &top);
    pop(a, &top);
    pop(a, &top);
    pop(a, &top);
    pop(a, &top);
    top_f(a, top);

}
#include <stdio.h>

void swap(int &a, int &b);

int main(void){
    int x = 10;
    int y = 20;
    printf("\nx contains this value: %d",x);
    printf("\nY contains this value: %d",y);
    swap(x,y);
    printf("\nx now contains this value: %d",x);
    printf("\ny now contains this value: %d",y);

    return 0;

}

void swap(int &a, int &b){
    
    int temp = a;
    a = b;
    b = temp;
}
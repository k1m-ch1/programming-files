#include <stdio.h>

int main(void){
    int a[][3] = {{1,2,3},{2,3,4},{3,4,5},{4,5,6},{7,8,9}};
    printf("The inital list is store in location: %p", a[0]);
    printf("\nThe inital list consumes %d bytes", (int)sizeof(a[0]));

    // changing the element in a[1][1]
    a[1][1] = 4;
    printf("\n%d", a[1][1]);

    // changing the element in a[1][1] using pointers
    int* ptr = a[1]+1;
    *(ptr) = 5;
    printf("\n%d", a[1][1]); 

    




}
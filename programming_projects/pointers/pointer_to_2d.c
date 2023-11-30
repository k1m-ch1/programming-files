#include <stdio.h>

int main(void){
    int elements[][4] = {{1,2,3,4}, {2,3,4,5}, {3,4,5,6}, {4,5,6,7}, {5,6,7,8}};
    int (*ptr_to_2d)[4];
    ptr_to_2d = elements;
    printf("\nThe size of array is %d bytes", (int)sizeof(elements));
    printf("\nThe address store in ptr_to_2d is %p", elements);
    printf("\nThe size of array element in element is %d", sizeof(elements[2]));
    printf("\nThe value stored in ptr_to_2d is %d", *(*(ptr_to_2d+3)+2));
}
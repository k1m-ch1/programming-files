#include <stdio.h>

int sum(int* a, int size);

int main(void){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int size = (int)sizeof(a)/(int)sizeof(a[0]);
    printf("\nThis array can store %d values", size);
    printf("\nThe size of array a is: %d", (int)sizeof(a));
    printf("\n");
    printf("\nThe sum of the numbers in the array is %d", sum(a,size));

}

int sum(int* a, int size){
    int sum = 0;
    for(int i = 0; i<size; i++){
        sum = sum + *(a+i);
    }
    return sum;
}

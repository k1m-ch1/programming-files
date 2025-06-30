#include <stdio.h>

void print_elements(const int size, int (*b)[3]);


int main(void){
    int a[][3] = {{1,2,3}, {2,4,6}, {3,6,9}, {4,8,12}};
    print_elements(3, a);

}

void print_elements(const int size, int (*b)[3]){
    int len = sizeof(*b)/3;
    for(int i = 0; i < len; i++){
        int j = i;
        printf("Array number %d: ", i);
        for(int i = 0; i < size; i++){
            printf("%d, ", *(*(b+j)+i));
        }
        printf("\n");
    }

}

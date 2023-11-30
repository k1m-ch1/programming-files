#include <stdio.h>

int main(void){
    int count = 0;
    for (int i = 1; i < 101; i++){
        int j = i;
        if(j%5 == 0){
            j = j - 5;
            if(j%10 != 0 & j > 0){
                printf("%d\n", j);
                count++;
            }
        }
    }
    printf("count: %d", count);
}
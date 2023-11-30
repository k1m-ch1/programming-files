#include <stdio.h>
#include <time.h>

int main(void){
    clock_t begin_t;
    clock_t end_t;
    begin_t = clock();

    long long unsigned i = 0; 
    while(i < 1000000000){
        i++;
    }
    printf("%llu", i);
    end_t = clock();
    printf("\nThis program ran for %f seconds", (float)(end_t - begin_t)/1000);


}
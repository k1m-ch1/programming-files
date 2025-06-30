#include <stdio.h>

int main(void){
    for (long long i = 1; i < 100000; i++){

        long long results = 2*i -1;
        printf("At n = %lld, Number is: %lld", i, results);

    }
}
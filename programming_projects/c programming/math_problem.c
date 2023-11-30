#include <stdio.h>
#include <stdlib.h>

int main(void){
    int counter = 0;
    int five_counter = 0;
    for(int i = 0; i < 20; i++){
        int rand_int = rand()%7;
        printf("In roll number %d, number generated is %d\n", i+1, rand_int);
        if(rand_int == 5){
            five_counter++;
        }
    }
    printf("Number five counted is %d\n", five_counter);
}
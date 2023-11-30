#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_loc(char* a);

int main(void){
    char* a = "Hello ,World!";
    print_loc(a);

}

void print_loc(char* a){
    printf("This string contains %d character/characters\n", (int)strlen(a));
    for (int i = 0; *(a+i) != '\0'; i++){
        printf("At location %d, Character is %c \n", i, *(a+i));
    }
    printf("\n");
}
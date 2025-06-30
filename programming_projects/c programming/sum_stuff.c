#include <stdio.h>

int main(void){
    for(int i = 0; i < 141; i++){
        if(2001%((i/2)+(140-i))==0){
            printf("%d\n", ((i/2)+(140-i)));
            printf("%d\n", i);
            printf("%d", 2001/((i/2)+(140-i)));
            break;
        }
    }
    return 0;
}
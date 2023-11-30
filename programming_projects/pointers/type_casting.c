#include <stdio.h>

int main(void){
    //1025 to binary is 00000000 00000000 00000100 00000001
    int x = 1025;
    int *ptr = &x;
    char *char_ptr = (char*)ptr;
    printf("\nPointer plus one %p",ptr+1);
    printf("\nThe value that ptr points to is %d",*(ptr));
    printf("\nThe value that ptr plus one points to is %d",*(ptr+1));
    printf("\nCharacter pointer plus one %p",char_ptr+1);
    printf("\nThe value that char_ptr points to is %d",*(char_ptr));
    printf("\nThe value that char_ptr plus one points to is %d",*(char_ptr+1));

}
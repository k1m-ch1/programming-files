#include <stdio.h>

int main(void){
    int a[][3][4] = {{{1,2,3,4},{2,3,4,5},{3,4,5,6}},{{2,4,6},{4,6,8},{6,8,10}}};
    int (*ptr)[3][4];
    ptr = a;
    printf("%p %p %p %p", a, a[0], a[0][0], &a[0][0][0]);
    printf("\n%d", ***a);
    printf("\n %d %d %d", sizeof(a), sizeof(*a), sizeof(**a), sizeof(***a));
    printf("\n %d", sizeof(ptr));
    printf("\n %d", sizeof(*ptr));
    printf("\n %p %p", ptr, ptr+1);



}
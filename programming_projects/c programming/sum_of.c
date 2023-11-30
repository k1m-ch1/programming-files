#include <stdio.h>

int main(void){
    int a[30];
    int sum=0;
    int traffic_problem = -6;
    a[0] = traffic_problem;
    int i_global_kinda;
    for (int i = 1; i > -1 & traffic_problem < 64; i++){
        traffic_problem = traffic_problem + 5;
        a[i] = traffic_problem;
        i_global_kinda = i;
    }
    for (int i = 0; i < i_global_kinda + 1; i++){
        sum = sum + a[i];
    }
    printf("The result is %d\n", sum);

}
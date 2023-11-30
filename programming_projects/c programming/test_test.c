#include <stdio.h>
#include <stdlib.h>

int evaluate(int i_one, int i_two){
    if(i_one>=i_two){
        return i_one;
    }else{
        return i_two;
    }
}

int main(void) {
	// your code goes here
	int t, num_of_color;
    int* a;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
	    scanf("%d", &num_of_color);
	    a = (int*)malloc((int)sizeof(int)*num_of_color);
	    for(int j = 0; i < num_of_color; i++){
	        scanf("%d", a+j);
	    }
	}
    return 0;
}
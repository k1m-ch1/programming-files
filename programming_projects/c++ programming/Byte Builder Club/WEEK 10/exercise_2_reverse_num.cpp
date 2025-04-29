#include <iostream>
#include <cmath>

/*
2. Swapping Values Using a Temporary Variable  
Question:  
Declare two integer variables x = 12 and y = 25. Use a third variable to swap their values. What are the final values of x and y?
*/

int num_reverse(int input_num);

int main(int argc, char* argv[]){
    std::cout << num_reverse(123) << std::endl;
    return 0;
}

int num_reverse(int input_num){
    int output_num = 0;
    while(input_num > 0){
        output_num = output_num*10 + (input_num % 10);
        input_num /= 10;
    }
    return output_num;

}
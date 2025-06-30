#include <iostream>
#include <cmath>
/*
1. Digit Sum Function
Problem: Write a function that takes an integer and returns the sum of its digits.
Input: 12345
Output: 15
*/

int digit_sum(int input_num);

int main(int argc, char* argv[]){

    std::cout << digit_sum(123) << std::endl;
    return 0;
}

int digit_sum(int input_num){
    int output_num = 0;
    while(input_num > 0){
        output_num += input_num % 10;
        input_num /= 10;
    }
    return output_num;
}
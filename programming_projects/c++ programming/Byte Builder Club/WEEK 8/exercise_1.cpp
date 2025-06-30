/*
Exercise 1: Create two integer variables, take their values as input from the user, and then swap the values. 

Hint: Take 2 input as integers, and then swap the values. 
*/
#include <iostream>


int main(int argc, char* argv[]){
    int a, b;
    std::cout << "store value in a: ";
    std::cin >> a;
    std::cout << "store value in b: ";
    std::cin >> b;

    std::cout << "swapping..."<< std::endl;
    // property of xor: a = (a xor b) xor b
    // no temp swap with xor
    a = a ^ b;
    b = a ^ b; // b becomes a since a = (a xor b) xor b; (note: a and b represents the input, not the variables)
    a = a ^ b; // a becomes b since b = (a xor b) xor a

    // normal swap
    int c;
    c = a;
    a = b;
    b = c;
    delete &c;

    // no temp swap with additon and subtraction
    // property: a = a - b + b and b =  a - (a - b)
    a = a - b;
    b = a + b; // a = (a - b) + b and a is stored in b
    a = b - a; // b = a - (a - b) and b is stored in a
    
    std::cout << "a after swap: "<< a <<std::endl;
    std::cout << "b after swap: "<< b << std::endl;
    return 0;
}
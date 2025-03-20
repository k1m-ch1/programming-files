// Assignment

// Write a C++ program that initializes two integer variables, x = 15 and y = 4. Perform the following operations and print the results:

// -Add x and y, then store the result in x using the += operator.
// -Multiply x by y using the *= operator.
// -Find the remainder when x is divided by y using the % operator.
// -After that doing an Comparison Operator ( ==, !=, >, <, >=,<=).

// Output:
// x after +=: 19
// x after *=: 76
// Remainder of x / y: 0

#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[]){
    int x, y;
    if (argc == 3){
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }
    else{
        x = 15;
        y = 4;
    }

    x += y;
    std::cout << "x after +=: "<< x << std::endl;
    x *= y;
    std::cout << "x after *=: "<< x <<std::endl;
    int x_mod_y = x % y;
    std::cout << "Remainder of x / y:"<< x_mod_y <<std::endl<<std::endl;
    std::cout<< x << " == "<< y << " is " << (x == y) << std::endl;
    std::cout<< x << " != "<< y << " is " << (x != y) << std::endl;
    std::cout<< x << " > "<< y << " is " << (x > y) << std::endl;
    std::cout<< x << " < "<< y << " is " << (x < y) << std::endl;
    std::cout<< x << " >= "<< y << " is " << (x >= y) << std::endl;
    std::cout<< x << " <= "<< y << " is " << (x <= y) << std::endl;
    return 0;
}

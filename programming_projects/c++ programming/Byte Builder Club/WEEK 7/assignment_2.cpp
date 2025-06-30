
/*
Practices Exercise
2/.Write a program that allows the user to enter a number of quarters, dimes, 
and nickels and then outputs the monetary value of the coins in cents. For 
example, if the user enters 2 for the number of quarters, 3 for the number 
of dimes, and 1 for the number of nickels, then the program should 
output that the coins are worth 85 cents.

*/

#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[]){
    const int QUARTER = 25;
    const int DIME = 10;
    const int NICKLE = 5;

    int num_quarters, num_dimes, num_nickels;
    std::cout << "Enter the amount of quarters: ";
    std::cin >> num_quarters;
    std::cout << "Enter the amount of dimes: ";
    std::cin >> num_dimes;
    std::cout << "Enter the amount of nickels: ";
    std::cin >> num_nickels;

    std::cout << "Coins are worth: " << (QUARTER*num_quarters + DIME*num_dimes+ NICKLE*num_nickels) << std::endl;


    return 0;
}

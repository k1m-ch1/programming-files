#include <iostream>
#include <cstring>
// Write a program that asks the user to enter a word (up to 100 characters). 
//Then, using the C-string function strlen, output the number of characters in the input
int main(int argc, char* argv[]){
    char str[100];
    std::cout << "Enter a word (up to 100 characters): ";
    std::cin.get(str, 100);
    std::cout <<"Length of the world: "<< strlen(str)<<std::endl;
    return 0;
}
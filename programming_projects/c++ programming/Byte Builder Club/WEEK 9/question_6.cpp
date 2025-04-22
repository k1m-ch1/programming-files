#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    char str[100];

    char str_copy[100];

    std::cout << "Enter your full name: ";
    std::cin.getline(str, 100);

    strcpy(str_copy, str);

    std::cout << "Original: " << str <<std::endl;
    std::cout << "Copied: " << str_copy << std::endl;
    return 0;
}
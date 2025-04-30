#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    char foo[50];
    char bar[50];
    std::cout << "Enter first word: ";
    std::cin.getline(foo, 50);
    std::cout << "Enter second word: ";
    std::cin.getline(bar, 50);
    std::cout << "String is equal? " << strcmp(foo, bar) <<std::endl;
    std::cout << "If negative, foo < bar. If possitve foo > bar. If 0 then foo = bar."<< std::endl;
    return 0;
}
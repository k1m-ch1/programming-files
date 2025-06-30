#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    char my_char;
    std::cout << "Press any key: ";
    std::cin.get(&my_char, 2);
    std::cout << "You entered: " << my_char << std::endl; 
    std::cout << "ASCII value: " << int(my_char) <<std::endl;
    return 0;
}
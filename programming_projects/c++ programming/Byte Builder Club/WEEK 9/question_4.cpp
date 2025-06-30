#include <iostream>
#include <cstring>

int main(int argc, char* argv[]){
    char sentence[100];
    std::cout << "Enter a sentence: ";
    std::cin.getline(sentence, 100);
    std::cout << "You entered: " << sentence <<std::endl;
    std::cout << "Length: " << strlen(sentence) << std::endl;
    return 0;
}
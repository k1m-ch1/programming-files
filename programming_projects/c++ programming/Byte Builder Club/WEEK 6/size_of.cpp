#include <iostream>
#include <limits>



int main(int argc, char* argv[]){
    std::cout << sizeof(int) <<std::endl;

    std::cout << std::numeric_limits<int>::min() <<std::endl;
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>
int main(int argc, char* argv[]){
    srand(time(0));
    rand();

    std::cout << rand()%6 + 1 << std::endl; 


    return 0;
}
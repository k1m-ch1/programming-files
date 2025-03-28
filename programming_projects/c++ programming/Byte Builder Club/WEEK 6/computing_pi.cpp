#include <iostream>
#include <ctime>
#include <cstdlib>
// C standard library


int main(int argc, char* argv[]){
    // double n = double(time(0));
    srand(time(nullptr));
    for (int i = 0; i < 5; i++){
        std::cout <<" : " << rand() <<std::endl;
    }
    return 0;
}
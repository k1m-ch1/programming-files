#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[]){
    double* a = (double*)malloc(sizeof(double));
    *a = 10;
    double* b = (double*)malloc(sizeof(double));
    *b = 39;
    double* aux = a;
    std::cout<< "This is the value of a :"<< *a <<std::endl;
    std::cout<< "This is the value of b :"<< *b <<std::endl;
    std::cout<<" This is the size of a pointer"<< sizeof(aux) <<std::endl;
    a = b;
    b = aux;
    std::cout<< "This is the value of a :"<< *a <<std::endl;
    std::cout<< "This is the value of b :"<< *b <<std::endl;
    return 0;
}
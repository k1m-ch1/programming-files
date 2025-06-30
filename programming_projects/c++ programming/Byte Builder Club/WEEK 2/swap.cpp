#include <iostream>

int main(){
    int a = 0;
    int b = 1;
    int aux;
    std::cout << "This is the value of a: " << a <<std::endl;
    std::cout << "This is the value of b: " << b <<std::endl;

    aux = a;
    a = b;
    b = aux;
    std::cout << "This is the value of a: " << a <<std::endl;
    std::cout << "This is the value of b: " << b <<std::endl;

    return 0;
}
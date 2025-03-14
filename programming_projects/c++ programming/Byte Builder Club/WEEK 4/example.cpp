#include <iostream>
#include <math.h>

int main(int argc, char* argv[]){
    const float PI = 3.14, e = 2.71;

    float a = pow(PI, e);
    float b = pow(e, PI);

    std::cout<< a << " == "<< b << " is " << (a == b) << std::endl;
    std::cout<< a << " != "<< b << " is " << (a != b) << std::endl;
    std::cout<< a << " > "<< b << " is " << (a > b) << std::endl;
    std::cout<< a << " < "<< b << " is " << (a < b) << std::endl;
    std::cout<< a << " >= "<< b << " is " << (a >= b) << std::endl;
    std::cout<< a << " <= "<< b << " is " << (a <= b) << std::endl;



    return 0;
}
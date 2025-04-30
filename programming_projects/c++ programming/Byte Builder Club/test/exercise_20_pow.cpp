#include <iostream>
#include <cmath>

int main(int argc, char* argv[]){
	double a, b;

	std::cout << "Enter the base: ";
	std::cin >> a;
	std::cout << "Enter the exponent: ";
	std::cin >> b;
	
	std::cout << "This is the result: " << std::pow(a, b) << std::endl;	
	return 0;
}

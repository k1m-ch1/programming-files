#include <iostream>
#include <cmath>

int main(int argc, char* argv[]){
	double a, b, c;
	// c^2 = a^2 + b^2
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;
	c = std::sqrt(std::pow(a, 2) + std::pow(b, 2));
	std::cout << c << std::endl;
	return 0;
}

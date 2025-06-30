#include <iostream>
#include <cmath>
//write a progra that asks the user for a base and an exponent and then calculates the power using pow()

int main(int argc, char* argv[]){
	//pow(b, a) where b is the base and a is the exponent
	float a,b;
	std::cout << "Enter your base: ";
	std::cin >> b;
	std::cout << "Enter your exponent: ";
	std::cin >> a;
	std::cout << "Your number is : " << std::pow(b, a) <<std::endl;
	return 0;
}

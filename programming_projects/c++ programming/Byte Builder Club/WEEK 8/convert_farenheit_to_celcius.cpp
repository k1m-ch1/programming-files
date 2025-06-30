#include <iostream>
#include <iomanip>
int main(int argc, char* argv[]){
	double temp;

	std::cout << "Enter the temperature (farenheit): ";
	std::cin >> temp;

	// convert from farenheit to celcius
	// c = (f - 32)*5/9

	temp = (temp - 32)*5/9;
	std::cout << "This is that temperature in celcius: "<<std::setprecision(4)<<temp << std::endl;
	return 0;
}
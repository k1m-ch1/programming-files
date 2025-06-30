#include <iostream>
#include <cmath>

int main(int argc, char* argv[]){
	const double PI = 3.14159265359;
	double r;
	std::cout << "Enter the radius: ";
	std::cin >> r;
	double circum = 2*PI*r;
	double area = PI *r*r;
	std::cout << "This is the circumference: " << circum << std::endl;
	std::cout << "This is the area: " << area << std::endl;

	 
	return 0;
}

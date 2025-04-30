#include <iostream>
#include <cmath>

int main(int argc, char* argv[]){
	double deg;
	const double PI = 3.14159265359;
	std::cout << "Input your angle (in degrees):  ";
	std::cin >> deg;

	double rad = deg * PI / 180;
	std::cout << "This is the angle in radians: " << rad << std::endl;
	std::cout << "This is the sin of that angle: " << std::sin(rad) << std::endl;
	return 0;
}

//Write a program that takes an angle in degrees from the user, converts it to radians, and then calculates and print the sin, cos and tan

#include <iostream>
#include <cmath>
#include <iomanip>
int main(int argc, char* argv[]){
	float angle_deg;
	const double PI = 3.14159265359;
	std::cout << "Enter your angle (degrees): ";
	std::cin >> angle_deg;
	// to convert deg to rad, rad = deg/180 * pi	
	double angle_rad = PI * angle_deg / 180;
	std::cout << "This is your angle in radians: " << angle_rad << std::endl;
	
	std::cout << "sin: " << std::sin(angle_rad)<< std::endl
	<< "cos: " << std::cos(angle_rad) << std::endl
	<< "tan: " << std::tan(angle_rad) << std::endl;
	return 0;
}
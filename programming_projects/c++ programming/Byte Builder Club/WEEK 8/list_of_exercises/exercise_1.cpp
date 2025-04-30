#include <iostream>

// Write a program to calculate the area of a circle pi = 3.14
int main(int argc, char* argv[]){
	const float PI = 3.14;
			
	// A = pi r^2
	float r;
	std::cout << "Enter the radius of the circle (in centimeters): ";
	std::cin >> r;
	
	std::cout << "Area of the circle: "<< PI*r*r << " cm^2"<<std::endl;
	return 0;
}

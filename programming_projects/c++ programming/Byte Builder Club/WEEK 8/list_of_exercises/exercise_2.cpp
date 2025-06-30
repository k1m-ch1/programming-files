#include <iostream>
#include <cmath>
//write a program that take a number from user and calculates its square root using sqrt
int main(int argc, char* argv[]){
	unsigned float num;
	std::cout << "Enter your number: ";
	std::cin >> num;
	num = std::sqrt(num);
	std::cout << "The square root of your number is : "<<num <<std::endl;
	return 0;
}
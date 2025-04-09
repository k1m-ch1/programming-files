//write a program that takes a number from user and calculates its natural logarithm log() and log10()

#include <iostream>
#include <cmath>
int main(int argc, char* argv[]){
	float num;
	
	std::cout << "Enter your number: ";
	
	std::cin >> num;
	num = std::fabs(num);
	std::cout <<"The 'natural' logarithm of your number: "<<std::log(num)<< std::endl
	<<"The base 10 logarithm of your number: " << std::log10(num)<<std::endl;
	
	return 0;
	
}
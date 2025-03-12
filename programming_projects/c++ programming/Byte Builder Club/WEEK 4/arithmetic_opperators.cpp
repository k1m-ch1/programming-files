#include <iostream>

int main(){


	int a = 10;
	float b = 3;

	std::cout << "a + b = " << a + b <<std::endl;
	std::cout << "a - b = " << a - b <<std::endl;
	std::cout << "a * b = " << a * b <<std::endl;
	std::cout << "a / b = " << a / b <<std::endl;
	std::cout << "a % b = " << a % int(b) <<std::endl;
	std::cout << a++ <<std::endl;

	return 0;

}
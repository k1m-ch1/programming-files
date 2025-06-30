#include <iostream>
#include <string>
int main(int argc, char* argv[]){
	std::string names[3];
	std::cout << "Enter the first name: ";
	std::getline(std::cin, names[0]); 
	std::cout << "Enter the second  name: ";
	std::getline(std::cin, names[1]); 
	std::cout << "Enter the thrid name: ";
	std::getline(std::cin, names[2]); 

	std::cout << "This is the first name: " << names[0] << std::endl;
	return 0;
}

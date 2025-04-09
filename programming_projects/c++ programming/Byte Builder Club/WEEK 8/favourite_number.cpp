#include <iostream>

int main(int argc, char* argv[]){
	unsigned int num;
	std::cout << "Enter your favourite number between 1 and 100: ";
	std::cin >> num;
	std::cout << "Amazing!! That's my favourite number too!\n"
	<<"No really!!, "<<num<< " is my favourite number!"<<std::endl;
	

	return 0;
}
#include <iostream>

int main(int argc, char* argv[]){

	int data[3] = {7, 14, 21};

	std::cout <<*(data + 1) << "," << data[1] << std::endl;
	return 0;
}

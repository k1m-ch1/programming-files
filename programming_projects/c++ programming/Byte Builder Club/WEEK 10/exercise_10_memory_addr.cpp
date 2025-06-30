#include <iostream>


int main(){
	int data[3] = {7, 14, 21};

	std::cout << *data << "," << *(data + 1) << std::endl;

	return 0;
}

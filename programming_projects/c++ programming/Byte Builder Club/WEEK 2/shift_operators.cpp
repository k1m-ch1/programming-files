#include <iostream>


int main(){
	//16,8,4,2,1
	//1, 0, 1, 0, 1
	int num = 21;
	num = (num << 1);
	//101010 -> 32 + 8 + 2 = 36 + 10 = 42
	std::cout<< num << std::endl;
	return 0; 
}
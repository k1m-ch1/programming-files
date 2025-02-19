#include <iostream>


int main(){
	//10101
	int num = 21;
	num = (num << 1);
	//10110 -> 32 + 8 + 4 = 36 + 8 =
	std::cout<< num << std::endl;
	return 0; 
}
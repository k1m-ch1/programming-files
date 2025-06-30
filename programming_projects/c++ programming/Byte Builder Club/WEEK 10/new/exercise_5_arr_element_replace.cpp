#include <iostream>


int main(int argc, char* argv[]){
	int arr[3] = {1, 2, 3};

	arr[1] = arr[0] + arr[2];

	std::cout << arr[1] << std::endl;
	
	return 0;
}

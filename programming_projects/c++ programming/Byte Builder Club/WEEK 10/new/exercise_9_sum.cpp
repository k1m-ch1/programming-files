#include <iostream>


int main(int argc, char* argv[]){
	const int SIZE = 4;

	int values[SIZE] = {5, 10, 15, 20};

	int sum = 0;
	for (int i = 0; i < SIZE; i++){
		sum += values[i];
	}
	std::cout << "The sum of the numbers in the array: " << sum << std::endl;
	return 0;
}

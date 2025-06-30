#include <iostream>

int main(){

	const int SIZE = 4;

	int values[SIZE] = {5, 10, 15, 20};

	int sum = 0;
	for (int i = 0; i < SIZE; i++){
		sum += values[i];
	}

	std::cout << "the sum of numbers in the array: " << sum << std::endl;
	return 0;
}

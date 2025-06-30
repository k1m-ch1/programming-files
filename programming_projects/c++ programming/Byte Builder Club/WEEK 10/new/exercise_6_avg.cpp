#include <iostream>

int main(int argc, char* argv[]){
	const int SIZE = 3;
	int scores[SIZE] = {80, 90, 100};

	// sum / size

	int sum = 0;
	for (int i = 0; i < SIZE; i++){
		sum += scores[i];
	}

	float avg = sum / SIZE;
	std::cout <<"This is the average of numbers in the array: "<< avg << std::endl;
	
	return 0;
}

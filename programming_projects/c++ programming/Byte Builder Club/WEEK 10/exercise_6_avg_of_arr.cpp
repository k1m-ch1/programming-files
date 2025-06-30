#include <iostream>

int main(){
	const int SCORE_SIZE = 3;
	int scores[SCORE_SIZE] = {80, 90, 100};
	int sum = 0;
	// 80 + 90 + 100
	for (int i = 0; i < SCORE_SIZE; i++){
		sum += scores[i];
	}

	float avg = sum/SCORE_SIZE;

	std::cout << "the average score is: " << avg << std::endl;
	return 0;
}

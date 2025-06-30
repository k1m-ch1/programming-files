#include <iostream>

void swap(int* a, int* b){
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(){
	int nums[3] = {3, 1, 2};

	swap(&nums[0], &nums[1]);
	// {1, 3, 2}
	swap(&nums[1], &nums[2]);

	std::cout << nums[0] << "," << nums[1] << "," << nums[2] << std::endl;
	
	

	return 0;
}

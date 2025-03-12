#include <iostream>
#include <stdlib.h>
int main(int argc, char* argv[]){

	if (argc != 2 && argc != 3){
		std::cout<<"Please enter the number of pages and the number of pages per sides"
		<<std::endl
		<<"For example: './a.out 9 2' means printing 9 pages where each sides has 2 page"<<std::endl;
	}
	else{
		int pages = atoi(argv[1]);
		int page_per_side = atoi(argv[2]);
		int num_of_blocks = pages/page_per_side;
		int num_odd_pages = (num_of_blocks/2)*page_per_side + (num_of_blocks%2)*page_per_side + (pages%page_per_side);
		int num_even_pages = (num_of_blocks/2)*page_per_side;
		int* odd_pages = (int*)malloc(num_odd_pages);
		int* even_pages =  (int*)malloc(num_even_pages);
	
	}

	return 0;
}
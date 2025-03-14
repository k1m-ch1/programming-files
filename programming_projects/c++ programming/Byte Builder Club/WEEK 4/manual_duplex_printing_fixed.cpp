#include <iostream>
#include <stdlib.h>
int main(int argc, char* argv[]){

	if (argc != 2 && argc != 3){
		std::cout<<"Please enter the number of pages and the number of pages per side"
		<<std::endl
		<<"For example: './a.out 9 2' means printing 9 pages where each side has 2 pages"<<std::endl;
	}
	else{
		//storing the number of "pages" and the number of "pages_per_side"
		int pages = atoi(argv[1]);
		int pages_per_side = atoi(argv[2]);

		// blocks refer to the number of *full* sides there are
		// for example if pages_per_side = 3, then blocks must have all pages
		int num_of_blocks = pages/pages_per_side;
		// calculate the size of the array that stores the first batch and second batch
		int num_odd_pages = (num_of_blocks/2)*pages_per_side + (num_of_blocks%2)*pages_per_side + (num_of_blocks % 2 == 0? pages%pages_per_side:0);
		int num_even_pages = (num_of_blocks/2)*pages_per_side + (num_of_blocks % 2 == 1? pages%pages_per_side : 0);
		// std::cout << num_odd_pages << std::endl
		// << num_even_pages <<std::endl;

		//allocating the array to store the pages (bruh dumbass can't use c++)
		int* odd_pages = (int*)malloc(num_odd_pages*sizeof(int));
		int* even_pages =  (int*)malloc(num_even_pages*sizeof(int));

		// to keep track of the array
		int n_at_odd_pages_arr = 0, n_at_even_pages_arr = 0;


		for (int i = 0; i < num_of_blocks; i++){
			//looping through all the blocks
			if (i % 2 == 0){
				// logic to store the pages that should get printed
				for(int j = 0; j < pages_per_side; j++){
					odd_pages[n_at_odd_pages_arr] = i*pages_per_side + j + 1;
					n_at_odd_pages_arr++;
				}
			}
			else {
				for(int j = 0; j < pages_per_side; j++){
					even_pages[n_at_even_pages_arr] = i*pages_per_side + j + 1;
					n_at_even_pages_arr++;
				}
			}
		}
		//resolving the last few pages that should get printed
		if (num_of_blocks%2 == 0){
				for (int i = num_of_blocks*pages_per_side; i < pages; i++){
					odd_pages[n_at_odd_pages_arr] = i + 1;
					n_at_odd_pages_arr++;
			}	
		}
		else{
				for (int i = num_of_blocks*pages_per_side; i < pages; i++){
					even_pages[n_at_even_pages_arr] = i + 1;
					n_at_even_pages_arr++;
			}	
		}

		
		std::cout << "first batch: ";
		for (int i = 0; i < num_odd_pages; i++){
			std::cout <<odd_pages[i] << ",";
		}
		if((num_of_blocks + (pages%pages_per_side > 0? 1: 0)) % 2 == 1){
			std::cout<<std::endl<<"Note: after printing the first batch"<<std::endl
			<<"remove the last page before inserting it back into the printer";
		}
		std::cout << std::endl << "second batch: ";
		for (int i = num_even_pages - 1; i >= 0 ; i--){
			std::cout << even_pages[i] << ",";
		}
		std::cout << std::endl;
	}

	return 0;
}
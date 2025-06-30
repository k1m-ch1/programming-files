#include <iostream>
#include <stdlib.h>
void solve(unsigned int n, char from_tower, char aux_tower, char to_tower);

int main(int argc, char* argv[]){
	if (argc == 1){
		std::cout << "Input sth plz" <<std::endl;
	}
	else {
		solve(atoi(argv[1]), 'a', 'b', 'c');
	}
	return 0;
}

void solve(unsigned int n, char from_tower, char aux_tower, char to_tower){
	if (n == 1){
		std::cout << "Move disk " << n << " from "<< from_tower
		<< " to "<< to_tower <<std::endl;
	}

	else {
		solve(n-1, from_tower, to_tower, aux_tower);
		std::cout <<"Move disk " << n << " from "<< from_tower
		<< " to "<< to_tower <<std::endl;
		solve(n-1, aux_tower, from_tower, to_tower);
	}
}

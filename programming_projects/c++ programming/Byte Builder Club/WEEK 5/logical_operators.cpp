#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	int a = 3,b = 5, c = 7, d = 8;

	// for a = 3, b = 5, c = 7; 3 + 5 > 7 (true), 3 * 5 > 7 (true)
	cout << "(a + b > c) or (a * b > c) is " << ((a + b > c) || (a * b > c)) <<endl;
	cout << "(a + b > c) and (a * b > c) is " << ((a + b > c) && (a * b > c)) <<endl;

	cout << endl;

	// for a = 3, b = 5, d = 8; 3 + 5 > 8 (false), 3 * 5 > 8 (true)
	cout << "(a + b > d) or (a * b > d) is " << ((a + b > d) || (a * b > d)) << endl;
	cout << "(a + b > d) and (a * b > d) is " << ((a + b > d) && (a * b > d)) << endl;

	cout << endl;

	// for a = 3, b = 5, d = 8; 3 + 5 == 8 (true), 3 * 5 != 8 (true)
	cout << "(a + b == d) or (a * b != d) is " << ((a + b == d) || (a * b != d)) << endl;
	cout << "(a + b == d) and (a * b != d) is " << ((a + b == d) && (a * b != d)) << endl;

	cout << endl;

	return 0;
}
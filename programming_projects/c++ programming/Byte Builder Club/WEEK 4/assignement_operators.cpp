#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
	int a = 10, b = 2;

	a += b;
	std::cout <<"+= " << a <<std::endl;

	a -= b;
	std::cout <<"-= " <<a <<std::endl;

	a *= b;
	std::cout <<"*= "<< a <<std::endl;

	a /= b;
	std::cout <<"/= "<< a <<std::endl;

	a %= b;
	std::cout <<"%= "<< a <<std::endl;
	return 0;
}
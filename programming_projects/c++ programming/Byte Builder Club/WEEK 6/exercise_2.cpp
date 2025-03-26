#include <iostream>
using namespace std;

// Exercise 2: Encode and Decode a Number (Bitwise & Arithmetic Manipulation)
// Write a C++ program that:

// Declares and initializes an integer num = 23.

// Encodes num using the following transformations:

// Left shift num by 2 bits.

// XOR the result with 0b10101 (21 in decimal).

// Add 42 to the result.

// Stores the encoded value in encodedNum.

// Decodes encodedNum to retrieve the original num, applying the reverse of the transformations.

// Prints both encodedNum and the decoded number.

// 💡 Challenge: You must retrieve num exactly as 23 without using conditional statements.

// output:

// Encoded Number: 145  
// Decoded Number: 23

int main(int argc, char* argv[]){
	// to encode num
	int num = 23;
	// 10111

	num = (num << 2);
	// 1011100
	num = num ^ 0b10101;
	// 1011100
	// 0010101
	//---------
	// 1001001_2
	// = 73
	num += 42;
	// 73 + 42 = 115
	int encodedNum = num;
	
	// to decode encodedNum
	encodedNum -= 42;
	// 73 = 1001001_2
	encodedNum = 0b10101 ^ encodedNum;
	// 1001001
	// 0010101
	// -------
	// 1011100
	encodedNum = (encodedNum >> 2);
	// 10111

	// printing both the encoded number and the decoded number
	cout <<"Encoded number: " << num << endl;
	cout <<"Decoded number: " <<  encodedNum <<endl; 

	return 0;
}
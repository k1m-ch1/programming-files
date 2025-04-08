/*
Exercise 2: Take 2 inputs from user, length and width of a Rectangle from the user and then calculate its Perimeter and Area. 

Hint: Take 2 input as integers, then calculate the area and perimeter using its own formula.
*/

#include <iostream>

int main(int argc, char* argv[]){
    unsigned int l, w;
    std::cout << "Enter the length of rectangle: ";
    std::cin >> l;
    std::cout << "Enter the width of the rectangle: ";
    std::cin >> w;

    std::cout << "The perimeter is : " << 2*(l + w) <<std::endl;
    std::cout << "The area is : " << l * w << std::endl;
    return 0;
}
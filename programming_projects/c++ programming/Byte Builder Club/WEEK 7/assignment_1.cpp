/*
Practices Exercise
1/. Write a C++ program that reads in two integers and then outputs both 
their sum and their product. One way to proceed is to start with the 
program in Display 1.8 and to then modify that program to produce the 
program for this project. Be certain to type the first line of your program 
exactly the same as the first line in Display 1.8. In particular, be sure that 
the first line begins at the left-hand end of the line with no space before 
or after the # symbol. Also, be certain to add the symbols \n to the last 
output statement in your program. For example, the last output statement 
might be the following:
 cout << "This is the end of the program.\n";
 (Some systems require that final \n, and your system may be one of 
these.)

*/

#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int a,b;
    std::cout << "Enter your first number: " ;
    std::cin >> a;
    std::cout << "Enter your second number: ";
    std::cin >> b;

    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a * b: " << (a*b) << std::endl;
    return 0;
}

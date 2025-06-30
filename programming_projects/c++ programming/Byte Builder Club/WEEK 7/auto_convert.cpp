#include <iostream>
using namespace std;
int main(int argc, char* argv[]){

    // short -> double
    // double -> int
    // int -> double
    // double -> short
    // short -> int
    // int -> short
    
    short num_short = 9;
    double num_double;
    int num_int;
    num_double = num_short;
    num_int = num_double;
    num_double = num_int;
    num_short = num_double;
    num_short = num_double;
    num_int = num_short;
    num_short = num_int;





    cout << "short: "<< num_short << endl
    << "int: " << num_int << endl
    << "double: "<< num_double <<endl;
    return 0;
}
#include <iostream>
#include <stdlib.h>
#include <iomanip>

int main (int argc, char* argv[]){
    // argument 1 is the max width
    if (argc > 1){
        int n = atoi(argv[1]);
        std::string s = "";
        for(int i = 0; i < n; i++){
            s += "*";
            std::cout << std::setw(n) << s << std::endl;
        } 

    }

    return 0;
}
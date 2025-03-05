#include <iostream>
#include <cmath>


int main(int argc, char* argv[]){
    std::cout<<"welcome!" <<std::endl;
    if (argc != 2 | argc != 3){
        std::cout << "Please enter the amount of pages and the number of pages per side (optional. 1 is selected as default)."<<std::endl;
    }
    else{
        int pages = atoi(argv[1]);
        int pages_per_side = 1;
        if (argc == 3){
            pages_per_side = atoi(argv[2]);
        }
        
        for(int i = 0; i < std::ceil(pages/(pages_per_side*2.0)); i++){
            for(int j = 0; j < pages_per_side && (pages_per_side*(2*i + 1) + j + 1) >= pages; j++){
                std::cout<<pages_per_side*(2*i + 1) +j + 1<<",";
            }
        }
        
        for(int i = 0; i < std::ceil(pages/(pages_per_side*2.0)); i++){
            for(int j = 0; j < pages_per_side && (pages_per_side*i*2 + j + 1) >= pages; j++){
                std::cout<<pages_per_side*i*2 + j + 1<<",";
            }
        }
    }
    return 0;
}
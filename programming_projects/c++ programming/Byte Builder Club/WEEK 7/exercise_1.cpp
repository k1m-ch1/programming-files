#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]){
    int cpp_students = 100;
    int js_students = 50;
    int cell_len = 15;
    int total_width = cell_len*2 + 1;
    std::string s = "";
    for (int i = 0; i < total_width; i++){
        s += "-";
    }
    std::cout << std::setw(cell_len) << std::left << "Course" << "|" << std::setw(cell_len) << std::right << "Students" << std::endl;
    std::cout << s << std::endl;
    std::cout << std::setw(cell_len) << std::left << "C++" << "|" << std::setw(cell_len) << std::right << cpp_students << std::endl;
    std::cout << std::setw(cell_len) << std::left << "JavaScript" << "|" << std::setw(cell_len) << std::right << js_students << std::endl;
    return 0;
}
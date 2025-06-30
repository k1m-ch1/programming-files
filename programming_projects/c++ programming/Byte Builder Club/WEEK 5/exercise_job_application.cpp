#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    string citizen = "US";
    string degree = "high school";
    int work_experience = 2;
    bool requirement_check = (citizen == "US" && (degree == "bachelor" || work_experience >= 2));
    cout << "Is the job requirement met? Answer: " <<boolalpha << requirement_check << endl;
    return 0;
} 
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){

    unsigned int age = 18;
    bool highschool_degree = true; 
    float ielts = 5.5; //0 if don't have ielts
    unsigned int toefl = 0; //0 if don't have toefl

    bool requirement_check = (age >= 18 && highschool_degree && (ielts >= 5.5 || toefl >= 45));
    cout << "Is the college application requirement met? Answer: " << boolalpha << requirement_check <<endl;

    return 0;
}
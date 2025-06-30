#include <iostream>

int main(int argc, char* argv[]){
    int total_sale = 95000;
    double state_tax = total_sale * 0.04;
    double country_tax = state_tax * 0.02;
    double total_tax = state_tax + country_tax;

    std::cout << "Total Sale: $" << total_sale << std::endl
    << "Country Tax: $"<< country_tax << std::endl
    << "State Tax: $" << state_tax << std::endl
    << "Total Tax: $" << total_tax << std::endl;

    return 0;
}
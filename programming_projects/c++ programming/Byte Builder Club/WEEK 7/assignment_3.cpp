/*
Write a program that allows the user
to enter a time in seconds and then
outputs how far an object would drop
if it is in freefall for that length of time.
Assume that the object starts at rest, there is no friction or
resistance from air, and there is a constant acceleration of 32 feet per second due to gravity.
use the equation: d = (1/2)at^2
*/

#include <iostream>

double get_uniform_acceleration_displacement(double time, double acceleration = 32);


int main(int argc, char* argv[]){
    double time;
    std::cout << "Enter the time in freefall: ";
    std::cin >> time;
    std::cout << get_uniform_acceleration_displacement(time) << std::endl;
    return 0;
}

double get_uniform_acceleration_displacement(double time, double acceleration){
    // calculate distance in feet given the acceleration (default to 32 feet/second squared) and time in seconds
    return 0.5 * acceleration * time * time;
}
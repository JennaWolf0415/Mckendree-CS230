//File: lab1_p2.cpp
//Description: This program calculates how much the ocean level will rise after three, six, and eleven years with the 
// measurment of 1.05 millimeters being how much it rises each year.
//Student ID: 0347845
//Date: January 20th, 2023
#include <iostream>

using namespace std;

int main()
{
    double threeYears;                //Holds ocean level after three years
    double sixYears;                  //Holds ocean level after six years
    double elevenYears;               //Holds ocean level after eleven years
    const double OCEAN = 1.05;   //The ocean level
    
    //Explains to the user what the program is doing
    cout << "The oceans level is currently rising 1.05 millimeters per year. This program will tell the user" << endl;
    cout << "how much higher the ocean level will be in three years, six years, and eleven years" << endl << endl;
    
    //Calculates the values(equations for ocean levels)
    threeYears = 3 * OCEAN;
    sixYears =  6 * OCEAN;
    elevenYears = 11 * OCEAN;
    
    //Displays the ocean levels after three, six, and eleven years
    cout << "The ocean level after three years will be " << threeYears << " millimeters higher." << endl;
    cout << "The ocean level after six years will be " << sixYears << " millimeters higher." << endl;
    cout << "The ocean level after eleven years will be " << elevenYears << " millimeters higher." << endl;

    return 0;
}

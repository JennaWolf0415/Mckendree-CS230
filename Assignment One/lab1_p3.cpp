//File: lab1_p3.cpp
//Description: This program takes in the diameter from the user and calculates the amount of slices a pizza
// will have before displaying the amount of slices to the user.
//Student ID: 0347845
//Date: January 20th, 2023
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double diameter;                    //holds the diameter data value
    double radius;                      //holds the radius data value
    double area;                        //holds the area data value
    double slices;                      //holds the slice data value
    const double PI = 3.1416;           //holds the PI data value as 3.1416
    const double SLICEAREA = 11.625;    //holds the SLICEAREA data value as 11.625
    
    //Tells the user what the program does
    cout << "This program determins the number of slices for any sized pizza for Joe's Pizza Place. " << endl << endl;
    
    //Has the user input the diameter of the pizza
    cout << "Please enter the diameter (in inches) of the pizza you want: ";
    cin >> diameter;
    
    //Checks to make sure the diameter is above 1
    while (diameter < 0  ||  diameter == 0)
        {
            cout << "Please enter a diameter above 0!" << endl;
            cin >> diameter;
        }

    //Does the calculations to determine how many slices the pizza will have
    radius = diameter / 2;
    area = PI * (radius * radius);
    slices = area / SLICEAREA;
    
    //Sets the precision of the answer to one decimal point
    cout << fixed << showpoint << setprecision(1);
    
    //displays the amount of slices the pizza will have
    cout << "a pizza with a diameter of " << diameter << " inches will have " << slices << " slices!";
    return 0;
}

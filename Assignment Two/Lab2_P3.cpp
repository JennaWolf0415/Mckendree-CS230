//File: lab2_p3.cpp
//Description: This program lets a user choose from a menu to find which area of a specific shape they want to find.
// It also makes sure proper numbers are entered and displays error messages if they are not.
//Student ID: 0347845
//Date: January 23rd, 2023


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int option;                 //holds the option data value
    double radius;              //holds the radius data value
    double area;                //holda the area data value
    double length;              //holds the length data value
    double width;               //holds the width data value
    const double PI = 3.1416;   //holds the PI data value at 3.1416
    
    
    //Tells the user what the program does
    cout << "This program will give you the choice on what area of a shape you want to find." << endl;
    cout << "Keep in mind you must use proper numbers with your choices (no negative and only -4 for the menu!)" << endl;
    
    //Displays the options the user can pick
    cout << "Pick one of the options below (type the number): " << endl;
    cout << "1.Calculate the Area of a Circle" << endl;
    cout << "2.Calculate the Area of a Rectangle" << endl;
    cout << "3.Calculate the Area of a Triangle" << endl;
    cout << "4.Quit" << endl;
    
    //Takes in users input
    cin >> option;
    cin.ignore(10,'\n');
    
    //Makes sure the user picked a proper input (between 1 and 4), if it is,
    //then does the calculations and such that go with the users input.
    switch (option < 1)
    {
        case 0:
            switch (option > 4)
            {
                case 0:
                    switch (option > 3)
                    {
                        case 0:
                            switch (option > 2)
                            {
                                case 0:
                                    switch (option > 1)
                                    {
                                        case 0:
                                            //Asks the user for the information needed to calculate the area of a circle
                                            cout << "You have chosen the area of a circle!" << endl;
                                            cout << "what is the radius of your circle?" << endl;
                                            cin >> radius;
                                            cin.ignore(10,'\n');
                                            
                                            // Makes sure radius entered is above 0
                                            switch (radius < 0)
                                            {
                                                case 0:
                                                    //Performs the calculation
                                                    area = pow (PI * radius, 2);
                                            
                                                    //outputs the area of the circle
                                                    cout << "The area of a circle with a radius of " << radius << " is " << area << "." << endl;
                                            break;
                                                case 1:
                                                
                                                    //Displays an error message when radius is below 0
                                                    cout << "You cannot enter a negative number for the radius!" << endl;
                                                    break;
                                            }
                                            break;
                                        case 1:
                                        
                                            //Asks the user for the information needed to calculate the area of a rectangle
                                            cout << "You have chosen the area of a rectangle!" << endl;
                                            cout << "what is the length of your rectangle?" << endl;
                                            cin >> length;
                                            cin.ignore(10,'\n');
                                            cout << "what is the width of your rectangle?" << endl;
                                            cin >> width;
                                            cin.ignore(10,'\n');
                                            
                                            // Makes sure length & width entered is above 0
                                            switch (length < 0)
                                            {
                                                case 0:
                                                    switch (width < 0)
                                                    {
                                                        case 0:
                                                        
                                                        //Performs the calculation
                                                        area = length * width;
                                            
                                                        //outputs the area of the rectangle
                                                        cout << "The area of a rectangle with a length of " << length;
                                                        cout << " and a width of " << width << " is " << area << "." << endl;
                                                        break;
                                                        
                                                        case 1:
                                                            
                                                            //Displays an error message when width is less than 0
                                                            cout << "You cannot enter a negative number for the width!" << endl;
                                                            break;
                                                    }
                                                    break;
                                                case 1:
                                                
                                                    //Displays an error message when length is less than 0
                                                    cout << "You cannot enter a negative number for the length!" << endl;
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                                case 1:
                                
                                    //Asks the user for the information needed to calculate the area of a traingle
                                    cout << "You have chosen the area of a traingle!" << endl;
                                    cout << "what is the length of your triangle?" << endl;
                                    cin >> length;
                                    cin.ignore(10,'\n');
                                    cout << "what is the width of your triangle?" << endl;
                                    cin >> width;
                                    cin.ignore(10,'\n');
                                            
                                    // Makes sure length & width entered is above 0
                                    switch (length < 0)
                                    {
                                        case 0:
                                            switch (width < 0)
                                            {
                                                case 0:
                                                        
                                                //Performs the calculation
                                                area = length * width * 0.5;
                                            
                                                //outputs the area of the triangle
                                                cout << "The area of a triangle with a length of " << length;
                                                cout << " and a width of " << width << " is " << area << "." << endl;
                                                break;
                                                        
                                                case 1:
                                                            
                                                    //Displays an error message when width is less than 0
                                                    cout << "You cannot enter a negative number for the width!" << endl;
                                                    break;
                                            }
                                            break;
                                        case 1:
                                                
                                            //Displays an error message when length is less than 0
                                            cout << "You cannot enter a negative number for the length!" << endl;
                                            break;
                                    }
                                    break;
                            }
                            break;
                        case 1:
                            cout << "Goodbye!" << endl;
                            break;
                    }
                    break;
                case 1:
                    cout << "You did not pick one of the options!" << endl;
                    break;
            }
            break;
        case 1:
            cout << "You did not pick one of the options!" << endl;
            break;
    }
    

    return 0;
}
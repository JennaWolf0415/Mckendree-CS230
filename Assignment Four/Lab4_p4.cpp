//File: Lab4_p4
//Purpose: Calculate the product of a number while using a recursive function
//Author: Jenna Wolf
//ID: 0347845
//Date: February 6th, 2023
#include <iostream>

using namespace std;
float multiply(int, int);
int main()
{
    float x;    // holds the x data
    float y;    // holds the y data
    float ans;  // holds the answer data
    
    //describes what the program does.
    cout << "type in any two intergers and this program will find the product of them!" << endl;
    
    //takes in the first integer
    cout << "What is your first value? ";
    cin >> x;
    cin.ignore(10,'\n');
    
    //takes in the second integer
    cout << "What is your second value? ";
    cin >> y;
    cin.ignore(10,'\n');
    
    //calls the function multiply so the product of the two integers can be found
    ans = multiply(x, y);
    
    //displys the answer of x * y
    cout << x << " times " << y << " is " << ans;
    
    return 0;
}

//purpose: the purpose of this function is to find the product of x * y. It does this usings a recursive function,
//which means it calls its self over and over, adding y to itself x amount of times.
//parameters: the parameter x and y are sent over so the function can find the product of the 2. y is added to itself
//over and over x amount of times. x is used to determin how many times y is added to itself.
float multiply(int x, int y)
{
    //used to test weather or not another y needs to be added. If it does, it adds y and calls the function again.
    if(0 < x)
        y = y + multiply(x - 1, y);
    else
        return 0;
    return y;
}
//File: lab1_p1.cpp
//Description: This program gets and tells the user how many bytes each data type uses (does this by using the sizeof command)
//Student ID: 0347845
//Date: January 20th, 2023
#include <iostream>

using namespace std;

int main()
{
     
    //This tells the user what the purpose of the code is (to find the bytes of different data types)
    cout << "This program determins how many bytes are in the data types of char, int, float, and double." << endl;
    
    //Tells the user the amount of bytes for the char data type
    cout << "For the data type of char, there are " << sizeof(char) << " bytes" << endl;
    
    //Tells the user the amount of bytes for the int data type
    cout << "For the data type of int, there are " << sizeof(int) << " bytes" << endl;
    
    //Tells the user the amount of bytes for the float data type
    cout << "For the data type of float, there are " << sizeof(float) << " bytes" << endl;
    
    //Tells the user the amount of bytes for the double data type
    cout << "For the data type of double, there are " << sizeof(double) << " bytes" << endl;
    
    return 0;
}

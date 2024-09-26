/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int numDigits(int, int);
int main()
{
    int number = 6570;
    int digits = 0;

    cout << "the sum of the digits in " << number << " is " << numDigits(number, digits);
    
    return 0;
}

int numDigits(int number,int digits)
{
    if(number > 0)
    {
        digits = digits + (number % 10);
        return numDigits(number / 10, digits);
    }
    else
        return digits;
}
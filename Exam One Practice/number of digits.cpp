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
    int number = 986754;
    int digits = 0;

    cout << "there are " << numDigits(number, digits) << " digits in " << number << endl;
    
    return 0;
}

int numDigits(int number,int digits)
{
    if(number > 0)
        return numDigits(number / 10, digits + 1);
    else
        return digits;
}
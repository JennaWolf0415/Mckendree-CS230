//file:lab5_p1
//purpose: Take a function that uses refrences and switch it to pointers. Then display/do something with said function
//author: Jenna Wolf
//student id: 0347845
//date: 2/23/2023

#include <iostream>

using namespace std;
int doSomething(int *, int *);
int main()
{
    int x = 7;  //holds the data for x
    int y = 8;  //holds the data for y
    int * ptr1; //holds the data for ptr1 (is a pointer)
    int * ptr2; //holds the data for ptr2 (is a pointer)
    
    //tells the user what the program does
    cout << "This program uses pointers in a function to produce a number." << endl;
    
    ptr1 = &x;  //makes ptr1 point to x address
    ptr2 = &y;  //makes ptr2 point to y address
    
    //calls the function doSomething and displays its return value as well as the pointers
    cout << "the function using numbers " << *ptr1 << " and " << *ptr2 << " produce the number " << doSomething(ptr1, ptr2);
    
    return 0;
}

//purpose: The purpose of this is to change the values that the pointers are pointing to.
//arguments: ptr1 and ptr2 and pointing to the values that are being changed (needed for calculations)
int doSomething(int * ptr1, int * ptr2)
{
    int temp = *ptr1;   //holds the data for temp
    
    //changes the values of ptr1 and ptr2 (times each of them by 10)
    *ptr1 = *ptr2 * 10;
    *ptr2 = temp * 10;
    
    //returns the values of the pointers added together
    return *ptr1 + *ptr2;
}
//File: Lab6_p1
//purpose: This function creates an array of random size and fills it with random values. It then takes in a value
//from the user and tells the user weather that value belongs to the array or not
//author: Jenna Wolf
//id: 0347845
//date: March 1st, 2023

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool belongTo(int *, int, int, int);
int main()
{
    int * ptr;      //holds the ptr data (is a pointer)
    int size;       //holds the size data
    int value;      //holds the value data
    int i = 0;      //holds the i data (set to 0)
    
    //tells the user what the program does
    cout << "this program takes in a size of an array from the user and fills it with random intergers" << endl;
    cout << "under 100. It then asks the user for a number and will tell the user weather or not that number is" << endl;
    cout << "in the array or not." << endl << endl;
    
    //takes in a size from the user
    cout << "What is the size of the array? ";
    cin >> size;
    
    //sets ptr to a new int of size
    ptr = new int [size];
    
    //fills the *ptr with random numbers under 100
    srand(time(0));
    for(int i = 0; i < size; i++)
        ptr[i] = (rand() % 101);
    
    //takes in a value from the user
    cout << "enter a value to see if it is in the array: ";
    cin >> value;
    
    //calls the belongTo function. if true is returned, then display the value belongs to the array.
    //if false is returned, then display the value doesn't belong to the array.
    if(belongTo(ptr, value, i, size))
        cout << value << " belongs to the array";
    else
        cout << value << " doesn't belong to the array";
    return 0;
}

//purpose: the purpose of this function is to check the array sent over to see if the value also sent over is
//in the array or not
//arguments: *ptr is sent because it holds the values being checked. val is sent over because it is What
//is being searched for. i is being sent because it increments through the array. Size is sent over so i doesn't go past array values
bool belongTo(int *ptr, int val, int i, int size)
{
    //checks to see if i is greater than size (if it is, return false). Then checks to see if ptr[i] equals the value.
    //(if it is, return true). If neither, then calls the function again and adds 1 to I.
    if(i > size)
        return false;
    else if(ptr[i] == val)
        return true;
    else
        return belongTo(ptr, val, i + 1, size);
}
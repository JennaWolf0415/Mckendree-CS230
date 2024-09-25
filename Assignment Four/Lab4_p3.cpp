//File: Lab4_p3
//Purpose: calculate random integers for all elements of an array. Then calculates the sum of all those integers and displays it.
//Author: Jenna Wolf
//ID: 0347845
//Date: February 6th, 2023
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int findSum(int, int, int[]);
const int SIZE = 100;    //holds the SIZE data which is 100
int main()
{
    int sum;            //holds the sum data
    int array[SIZE];    //holds the array data (array has a size based on the constant size)
    int x = SIZE;       //holds the x data which is equal to SIZE

    //explains what this program does
    cout << "This program takes and array with a determined size and fills its elements with random integers. It then" << endl;
    cout << "adds all the elements of that array together and displays it. " << endl;
    
    //Makes sure random values are actually random
    srand(time(0));
    
    //Fills all elements of the array with random integers between 1 and 10
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 11;
    }
    
    //calls the findSum function to find the sum of all array elements
    sum = findSum(x, sum, array);
    
    //outputs the sum of all array variables
    cout << "The sum of all the elements in the array (which has a size of " << SIZE << ") is " << sum << endl;
    return 0;
}

//purpose: the purpose of this function is to calculate the sum of all the variables in an array.
//parameters: int x is used to go through each element in the array. It is also used to stop the recursive function after all
//elements have gone through. int sum is used to hold the sum of all the elements in the array. int array is used to hold all
//the elements in the array seperatly (it is what is stepped through).
int findSum(int x, int sum, int array[])
{
    //used to test weather or not all elements of the array have been stepped through. If it hasn't, then findSum is called again.
    //if it has, then the function returns a zero and sum is found.
    if(x > 0)
    {
        sum = findSum(x - 1, sum, array) + array[x - 1];
    }
    else
        return 0;
        
    //returns the sum after it is found.
    return sum;
}
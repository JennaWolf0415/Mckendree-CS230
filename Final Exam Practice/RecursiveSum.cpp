//program: Recursive Sum
//purpose: use recursion to find the sum of all the numbers in an array
//name: Jenna Wolf
//id: 0347845
//date: May 2nd, 2023

#include <iostream>

using namespace std;
void findSum(int, int [], int &);
int main()
{
    const int SIZE = 10;                                            //holds the SIZE data (is a const) and is set to 10
    int array[SIZE] = {15, 20, 25, 27, 11, 17, 19, 18, 37, 5};      //holds the array data and is size SIZE (has data)
    int sum = 0;                                                    //holds the sum data and is set to 0
    
    //explains what this program does
    cout << "This program uses recursion to find the sum of all values in an array" << endl;
    
    findSum(SIZE, array, sum);  //calls the findSum function
    
    cout << sum;    //displays sum
    
    return 0;
}

//purpose: this function finds the sum of all values in the array sent over to it
//arguments: size is the size of the array, array holds the values being added, and sum holds the sum of the values in the array
void findSum(int size, int array[], int &sum)
{
    //checks to see if size is bigger than 0
    if(size > 0)
    {
        sum = sum + array[size - 1];    //sets sum to sum plus the value in the array at size - 1
        findSum(size - 1, array, sum);  //calls the findSum function
    }
}
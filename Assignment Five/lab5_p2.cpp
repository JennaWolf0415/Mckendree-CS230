//file:lab5_p2
//purpose: This program takes and array and sees which of its values are repeated the most. If none of the values are repeated
//more than once, then the program says that.
//author: Jenna Wolf
//student id: 0347845
//date: 2/23/2023

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int multipleNum(int *, int);
int main()
{
    int size = 20;      //holds the size data
    int top;            //holds the top data
    int * ptr;          //holds the ptr data (is a pointer)
    int array[size];    //holds the array data (is an array)
    
    //explains what the program does
    cout << "This program takes an array that has been filled with numbers between 1 and 10 and tells the user" << endl;
    cout << "which (if any) of those number occurs the most. If they all appear the same amount, then the program says so" << endl << endl;
    
    //This fills the array with random numbers between 1 and 10
    srand(time(0));
    for(int i = 0; i < size; i++)
        array[i] = (rand() % 11);
    
    ptr = array;    //sets the ptr to the arrays address
    
    //displays the array by using the pointer
    cout << "The array: ";
    for(int i = 0; i < size; i++)
        cout << ptr[i] << " ";
    cout << endl;
    
    //calls the multipleNum array and has it equal top
    top = multipleNum(ptr, size);
    
    //sees if top equals anything other than -1 (meaning weather a number appeared more than the others).
    //if yes, then it displays which number appears the most. If not, it says they all occur the same
    if(top != -1)
        cout << "the number that occured the most is " << top << endl;
    else
        cout << "each number occured the same amount of times" << endl;
    return 0;
}

//purpose: the purpose of this array is to find which number in the array appears the most.
//if all numbers appear the same, then that is said.
//arguments: ptr is taken because it points to the array. It is what is being checked. s is used for size
//so that we know how many elements are in the array/pointer.
int multipleNum(int * ptr, int s)
{
    int same;       //holds the same data
    int most = 0;   //holds the most data
    int top;        //holds the top data
    
    //for loop used to go through each element so each can be tested
    for(int i = 0; i < s; i++)
    {
        same = 0;   //sets same to 0 
        //for loop used to compare each element of the array/pointer to each other element and see if they are the same
        for(int j = 0; j < s; j++)
        {
            //tests to see if elements are the same. If they are, then 1 is added to same
            if(ptr[i] == ptr[j] && i != j)
                same++;
        }
        //tests to see if currenet element had more repeats than the current most. If so, most is set to same and top is sent to
        //the current element.
        if(same > most)
        {
            most = same;
            top = ptr[i];
        }
    }
    //tests to see if most is still 0. If it is, then no element was repeated and top is set to -1
    if(most == 0)
        top = -1;
        
    //returns the element that was repeated the most
    return top;
}
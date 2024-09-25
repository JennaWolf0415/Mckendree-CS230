//file: lab5_p4
//purpose: this program is used to take in data for a survey of a number of students. It then finds the average and mode
//of the data entered about how podcasts students listen to.
//author: Jenna Wolf
//student id: 0347845
//date: 2/23/2023

#include <iostream>

using namespace std;
int *getNum(int *, int);
int average(int *, int);
int mode(int *, int);
int main()
{
    int * ptr;  //holds the ptr data (is a pointer)
    int size;   //holds the size data
    int top;    //holds the top data
    
    //tells what the program does
    cout << "This program takes in how many students were surveyed and the data for each student surveyed. It then calculates" << endl;
    cout << "and displays the average and mode of the data enetered. The survey is for how many podcasts students listen to" << endl << endl;
    
    //takes in the size/amount of students surveyed
    cout<<"Enter a how many students were surveyed: ";
    cin >> size;
    
    //makes sure size is a positive number
    while(size < 0)
    {
        cout << "please enter a number above 0!";
        cin >> size;
    }
    
    ptr = new int[size]; //sets ptr to point to a new int array of size

    //calls the getNum function and sets ptr to the results
    ptr = getNum(ptr, size);
    
    //calls the average function and displays the results
    cout << "the average of those surveyed is: " << average(ptr, size) << endl;
    
    //calls the mode function and sets top to the result
    top = mode(ptr, size);
    
    //sees if top equals anything other than -1 (meaning weather a number appeared more than the others).
    //if yes, then it displays which number appears the most. If not, it says they all occur the same
    if(top != -1)
        cout << "the number that occured the most from those surveyed is " << top << endl;
    else
        cout << "each number from those surveyed occured the same amount of times" << endl;
    
    //deletes what the ptr is pointing to
    delete []ptr;
    return 0;
}

//purpose: the purpose of this function is to get the data of the survey from the user and put it in the array ptr
//is pointing to
//arguments: ptr is used to enter data into since it is pointing to the array. size is used to tell how many elements
//are in the array
int *getNum(int * ptr, int size)
{
    //for loop used to get data for each element of ptr
    for(int i = 0; i < size; i++)
    {
        //takes in the amount of podcasts a student has listened to
        cout << "How many podcasts has student " << i + 1 << " listened to?: ";
        cin >> ptr[i];
        
        //makes sure the entered amount is positive
        while(ptr[i] < 0)
        {
            cout << "please enter a number above 0!";
            cin >> size;
        }
    }
    //creates a space
    cout << endl;
    
    //returns what ptr is pointing to
    return ptr;
}

//purpose: the purpose of this function is the find the average of all the data in ptr
//arguments: ptr is used because it is pointing to the array that is being averaged. size is used to see how many
//elements are in the array as well as calculate the average
int average(int * ptr, int size)
{
    int a;  //holds the a data
    
    //adds all elements of ptr together
    for(int i = 0; i < size; i++)
        a = a + ptr[i];
    
    //takes a and divides it by the size
    a = a/size; 
    
    //returns the average
    return a;
}

//purpose: the purpose of this array is to find which number in the array appears the most.
//if all numbers appear the same, then that is said.
//arguments: ptr is taken because it points to the array. It is what is being checked. s is used for size
//so that we know how many elements are in the array/pointer.
int mode(int * ptr, int s)
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
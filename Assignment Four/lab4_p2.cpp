//File: Lab4_p2
//Purpose: take in data from a file into two seperate parallel arrays. then sort that info based on population and display
//it. Finally display the amount of swaps each sort function used.
//Author: Jenna Wolf
//ID: 0347845
//Date: February 6th, 2023
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 37;        //holds the SIZE data (set to 37)
void readFile(int [], string [], int [], int [], int [], int [], int []);
void bubbleSort(string [], int [], int [], int [], int [], int [], int &);
void selectionSort(string [], int [], int [], int [], int [], int [], int &);
void display(int [], string [], int [], int [], int [], int [], int []);
int main()
{
    int reccount1[SIZE];    //holds the recount1 data (parallel array 1)
    string name1[SIZE];     //holds the name1 data (parallel array 1)
    int totcase1[SIZE];     //holds the totcase1 data (parallel array 1)
    int newcase1[SIZE];     //holds the newcase1 data (parallel array 1)
    int totdeath1[SIZE];    //holds the totdeath1 data (parallel array 1)
    int newdeath1[SIZE];    //holds the newdeath1 data (parallel array 1)
    int pop1[SIZE];         //holds the pop1 data (parallel array 1)
    int totswap1 = 0;       //holds the totswap1 data 
    int reccount2[SIZE];    //holds the recount2 data (parallel array 2)
    string name2[SIZE];     //holds the name2 data (parallel array 2)
    int totcase2[SIZE];     //holds the totcase2 data (parallel array 2)
    int newcase2[SIZE];     //holds the newcase2 data (parallel array 2)
    int totdeath2[SIZE];    //holds the totdeath2 data (parallel array 2)
    int newdeath2[SIZE];    //holds the newdeath2 data (parallel array 2)
    int pop2[SIZE];         //holds the pop2 data (parallel array 2)
    int totswap2 = 0;       //holds the totswap2 data 

    //Describes what this program does
    cout << "this program reads in data from a file into two seperate parallel arrays. One set of parallel arrays is sent to a ";
    cout << endl << "bubble sort function while the other is sent to a linear search function. This program then displays each";
    cout << endl << "sorted parallel arrays and tells the user how many times values in the arrays were swapped." << endl << endl;
    
    //sends each set of parallel arrays to the readFile function
    readFile(reccount1, name1, totcase1, newcase1, totdeath1, newdeath1, pop1);
    readFile(reccount2, name2, totcase2, newcase2, totdeath2, newdeath2, pop2);
    
    //sends each set of parallel arrays to a seperate sort function
    bubbleSort(name1, totcase1, newcase1, totdeath1, newdeath1, pop1, totswap1);
    selectionSort(name2, totcase2, newcase2, totdeath2, newdeath2, pop2, totswap2);
    
    //displays each set of parallel arrays
    display(reccount1, name1, totcase1, newcase1, totdeath1, newdeath1, pop1);
    cout << endl << endl;
    display(reccount2, name2, totcase2, newcase2, totdeath2, newdeath2, pop2);
    cout << endl << endl;
    
    //displays how many times each sort function swapped values
    cout << "The bubble sort took a total of " << totswap1 << " swaps" << endl;
    cout << "The selection sort took a total of " << totswap2 << " swaps" << endl;;
    return 0;
}

//purpose: the purpose of this function is to read in data from the file into each set of parallel arrays
//parameters: reccount, name, totcase, newcase, totdeath, newdeath, and pop are all sent over so they can hold
//the data from the files.
void readFile(int reccount[SIZE], string name[SIZE], int totcase[SIZE], int newcase[SIZE], 
                int totdeath[SIZE], int newdeath[SIZE], int pop[SIZE])
{
    //Opens the file
    ifstream infile;
    infile.open("covid.txt");
    
    //Makes sure file is opened correctly. Error is sent out if it is not
    if(!infile)
    {
        cout << "File failed to open, try again" << endl;
        exit(EXIT_FAILURE);
    }
    
    //Reads in data from the file to each variable
    for(int i = 0; i < SIZE; i++)
    {
        infile >> reccount[i];
        infile >> name[i];
        infile >> totcase[i];
        infile >> newcase[i];
        infile >> totdeath[i];
        infile >> newdeath[i];
        infile >> pop[i];
    }
    
    //closes the file
    infile.close();
}

//purpose:Uses the bubble sort method to sort the data from each array in order based on ascending new deaths. 
//parameters: reaccount, name, totcase, newcase, totdeath, newdeath, and pop are all sent over because they are what
//is being sorted. totswap is sent used to keep track of the total swaps performed by the program.
void bubbleSort(string name[SIZE], int totcase[SIZE], int newcase[SIZE], 
                int totdeath[SIZE], int newdeath[SIZE], int pop[SIZE], int &totswap)
{
    int max; //used to hold the max data
    
    //tests to see if array has gone through each element. If it has, then loop ends
    for(max = SIZE - 1; max > 0; max--)
    {
        //tests to see if array has gone through each element. If it has, then loop ends
        for(int i = 0; i < max; i++)
        {
            //Tests to see in current array element is higher than the element after it. if it is, swaps the two elements (in
            //each parallel array as well). Also adds 1 to total swaps.
            if(pop[i] > pop[i + 1])
            {
                swap(name[i],name[i + 1]);
                swap(totcase[i],totcase[i + 1]);
                swap(newcase[i],newcase[i + 1]);
                swap(totdeath[i],totdeath[i + 1]);
                swap(newdeath[i],newdeath[i + 1]);
                swap(pop[i],pop[i + 1]);
                totswap = totswap + 1;
                
            }
        }
    }
}

//purpose:Uses the selection sort method to sort the data from each array in order based on ascending new deaths. 
//parameters: reaccount, name, totcase, newcase, totdeath, newdeath, and pop are all sent over because they are what
//is being sorted. totswap is sent used to keep track of the total swaps performed by the program.
void selectionSort(string name[SIZE], int totcase[SIZE], int newcase[SIZE], 
                int totdeath[SIZE], int newdeath[SIZE], int pop[SIZE], int &totswap)
{
    int minI;   //holds the minI data
    int minV;   //holds the minV data
    
    //tests to see if all elements of the array have been stepped through. If they have, loop ends.
    for (int start = 0; start < (SIZE - 1); start ++)
    {
        //sets minI and minV to the current element of the array we are testing.
        minI = start;
        minV = pop[start];
        
        //steps through each element on the array, testing them. After all elements have been stepped through, loop stops
        for (int i = start + 1; i < SIZE; i ++)
        {
            //tests to see if a element is smaller than the current element in its spot. If it is, minV and minI are set to
            //the current elements spot (to soon be swapped if it is the smalest)
            if(pop[i] < minV)
            {
                minV = pop[i];
                minI = i;
            }
        }
        
        //swaps elements of the array to fit ascending newdeath order. also adds 1 to totalswap
        swap(name[minI],name[start]);
        swap(totcase[minI],totcase[start]);
        swap(newcase[minI],newcase[start]);
        swap(totdeath[minI],totdeath[start]);
        swap(newdeath[minI],newdeath[start]);
        swap(pop[minI],pop[start]);
        totswap = totswap + 1;
    }
}

//purpose:swaps two varaibles
//parameters:a and b are used (along with temp) to swap the value of two variables/elements.
void swap(int &a,int &b)
{
    int temp = a;   //used to hold temp data (set to a)
    
    //sets a to b and b to temp (which is a)
    a = b;
    b = temp;
}

//purpose: The purpose of this function is to display both parallel arrays in a organized form.
//parameters: reaccount, name, totcase, newcase, totdeath, and newdeath are all sent over so they can be displayed in table form
void display(int reccount[SIZE], string name[SIZE], int totcase[SIZE], int newcase[SIZE], 
                int totdeath[SIZE], int newdeath[SIZE], int pop[SIZE])
{
    //displays a header for the table
    cout << "No. | " << " Country " << "    | " << " Total Cases " << " | " << " New Cases " << " | ";
    cout << " Total Deaths " << " | " << " New Deaths " << " | " << " Population " << " | ";
    cout << endl << "-------------------------------------------------------------------------------------------------" << endl;
    
    //displays parallel array info in a table format
    for(int i = 0; i < SIZE; i++)
    {
        cout << left << setw(3) << reccount[i] << " | ";
        cout << left << setw(12) << name[i] << " | ";
        cout << left << setw(13) << totcase[i] << " | ";
        cout << left << setw(11) << newcase[i] << " | ";
        cout << left << setw(14) << totdeath[i] << " | ";
        cout << left << setw(12) << newdeath[i] << " | ";
        cout << left << setw(12) << pop[i] << " | ";
        cout << endl << "-------------------------------------------------------------------------------------------------" << endl;
    }
}
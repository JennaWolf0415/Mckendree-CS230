//File: Lab4_p1
//Purpose: Take in information from a file and store it in a pallel array. Then use a linear search to search for
//the country with 95 death as well as asking the user for the amount of deaths they want to search for. Do the same
//thing while using the binary search algorithm. Display how long it took for each search to find their values
//Author: Jenna Wolf
//ID: 0347845
//Date: February 6th, 2023

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
const int SIZE = 37;        //holds the SIZE data at 37
void readFile(int [], string [], int [], int [], int [], int [], int []);
void linSearch(int [], string [], int [], int [], int [], int [], int []);
void binarySearch(int [], string [], int [], int [], int [], int [], int []);
void sort(string [], int [], int [], int [], int [], int []);
int main()
{
    int reccount[SIZE];     //holds the reccount data (parallel array)
    string name[SIZE];      //holds the name data (parallel array)
    int totcase[SIZE];      //holds the totcase data (parallel array)
    int newcase[SIZE];      //holds the newcase data (parallel array)
    int totdeath[SIZE];     //holds the totdeath data (parallel array)
    int newdeath[SIZE];     //holds the newdeath data (parallel array)
    int pop[SIZE];          //holds the pop data (parallel array)

    //describes what this program does
    cout << "this program reads in data from a file into a parallel array. It then uses a linear search algorithm to search";
    cout << endl << "for 95 death and then lets you search for any death amount. It does the same thing with a binary search";
    cout << endl << "algorithm as well. It also keeps track of how many searches are performed each time and displays it." << endl;
    
    //goes to readFile function so data can be read into the arrays
    readFile(reccount, name, totcase, newcase, totdeath, newdeath, pop);
    
    //sends arrays to each search function so each one can perform their searches
    linSearch(reccount, name, totcase, newcase, totdeath, newdeath, pop);
    binarySearch(reccount, name, totcase, newcase, totdeath, newdeath, pop);
    
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
//purpose:the purpose of this function is to use a linear search to search for the value of 95 in the newdeath array. It then
//also lets the user search for any value in the newdeath array.
//parameters: reccount, name, totcase, newcase, totdeath, newdeath, and pop are all sent over since they are the arrays
//being displayed when a value is found (display all info for when a value is found). Newdeath is the array we
//use to search for a value in this function.
void linSearch(int reccount[SIZE], string name[SIZE], int totcase[SIZE], int newcase[SIZE], 
                int totdeath[SIZE], int newdeath[SIZE], int pop[SIZE])
{
    int count = 0;          //holds the count data (set to 0)
    int val = 95;           //holds the val data (set to 95)
    bool found = false;     //holds the found data (set to false)
    int position = -1;      //holds the position data (set to -1)
    int searches;           //holds the search data
    char awn;               //holds the awn data
    
    //a do while loop that tests at the end weather or not the user wants to search for a value
    do
    {
        //tests to see if all elements of the array have been stepped trough. Once they have, loop stops
        for(int i = 0; i < SIZE; i++)
        {
            //Test to see if element of the array equals the val that is beingsearched for
            if(newdeath[i] == val)
            {
            //if the element is the value, position is set to said element location, found is set to ture, and searches is set
            //to the current count
                found = true;
                position = i;
                searches = count;
                
            }
            //if the element is not the value, count adds 1
            else
                count = count + 1;
        }
        
        //if the value was found, all information for said country that fits the val is printed
        if(found)
        {
            cout << "Information for country that has " << val << " deaths: " << endl;
            cout << "#" << reccount[position] << endl;
            cout << "name: " << name[position] << endl;
            cout << "total cases: " << totcase[position] << endl;
            cout << "new cases: " << newcase[position] << endl;
            cout << "total deaths: " << totdeath[position] << endl;
            cout << "new deaths: " << newdeath[position] << endl;
            cout << "population: " << pop[position] << endl;
            cout << "this took " << searches << " searches to find" << endl;
            cout << endl << endl;
        }
        //if the value was not found, not found message is sent
        else
            cout << "There is no country with " << val << " deaths" << endl << endl;
        
        //count is reset to zero
        count = 0;
        
        //asks the user if they want to go again and takes in their answer
        cout << "Would you like to search for a value (y for yes, n for no)? ";
        cin >> awn;
        cin.ignore(10,'\n');
        
        //makes sure user typed a proper answer
        while(awn != 'y' && awn != 'n')
        {
            cout << "please enter a correct answer! (y for yes, n for no!)";
            cin >> awn;
            cin.ignore(10,'\n');
        }
        
        //if user said yes, takes in value user wants to find and sets found back to false.
        if(awn == 'y')
        {
            cout << "What is the number of deaths today you would like to search for? ";
            cin >> val;
            found = false;
        }
    }
    //if answer is no, then loop ends
    while(awn != 'n');
}

//purpose:the purpose of this function is to use a binary search to search for the value of 95 in the newdeath array. It then
//also lets the user search for any value in the newdeath array.
//parameters: reccount, name, totcase, newcase, totdeath, newdeath, and pop are all sent over since they are the arrays
//being displayed when a value is found (display all info for when a value is found). Newdeath is the array we
//use to search for a value in this function.
void binarySearch(int reccount[SIZE], string name[SIZE], int totcase[SIZE], int newcase[SIZE], 
                int totdeath[SIZE], int newdeath[SIZE], int pop[SIZE])
{
    int first;          //holds the first data
    int last;           //holds the last data
    int middle;         //holds the middle data
    int position;       //holds the position data
    bool found = false; //holds the found data (set to false)
    int val = 95;       //holds the val data (set to 95)
    int count = 0;      //holds the count data (set to 0)
    char awn;           //holds the awn data
    
    //calls the sort function so binarysearch can be used
    sort(name, totcase, newcase, totdeath, newdeath, pop);
    
    //a do while loop that tests at the end weather or not the user wants to search for a value
    do
    {
        //sets first to 0 (start of array) last to SIZE - 1 (end of array) and position to -1
        first = 0;
        last = SIZE - 1;
        position = -1;
        
        //starts a while loop that will loop until val is found or first and last cross (no values left in middle)
        while(!found && first <= last)
        {
            //sets middle to middle value of first and last
            middle = (first + last) / 2;
            
            //checks to see if middle of array is the val
            if(newdeath[middle] == val)
            {
                //if it is, found is set to true and position is set to middle
                found = true;
                position = middle;
            }
            //if not, test to see if middle of array is greater than or less than val
            else if (newdeath[middle] > val)
                //if greater than, last moves down
                last = middle - 1;
            else
                //if less than, first moves up
                first = middle + 1;
            //adds 1 to count
            count = count + 1;
        
        }
        
        //if the value was found, all information for said country that fits the val is printed
        if(found)
        {
            cout << "Information for country that has 95 deaths: " << endl;
            cout << "#" << reccount[position] << endl;
            cout << "name: " << name[position] << endl;
            cout << "total cases: " << totcase[position] << endl;
            cout << "new cases: " << newcase[position] << endl;
            cout << "total deaths: " << totdeath[position] << endl;
            cout << "new deaths: " << newdeath[position] << endl;
            cout << "population: " << pop[position] << endl;
            cout << "this took " << count << " searches to find" << endl;
            cout << endl << endl;
        }
        //if the value was not found, not found message is sent
        else
            cout << "There is no country with " << val << " deaths" << endl << endl;
        
        //count is reset to zero
        count = 0;
        
        //asks the user if they want to go again and takes in their answer
        cout << "Would you like to search for a value (y for yes, n for no)? ";
        cin >> awn;
        cin.ignore(10,'\n');
        
        //makes sure user typed a proper answer
        while(awn != 'y' && awn != 'n')
        {
            cout << "please enter a correct answer! (y for yes, n for no!)";
            cin >> awn;
            cin.ignore(10,'\n');
        }
        
        //if user said yes, takes in value user wants to find and sets found back to false.
        if(awn == 'y')
        {
            cout << "What is the number of deaths today you would like to search for? ";
            cin >> val;
            found = false;
        }
    }
    //if answer is no, then loop ends
    while (awn != 'n');
}

//purpose:Uses the selection sort method to sort the data from each array in order based on ascending new deaths. 
//parameters: reaccount, name, totcase, newcase, totdeath, newdeath, and pop are all sent over because they are what
//is being sorted. totswap is sent used to keep track of the total swaps performed by the program.
void sort(string name[SIZE], int totcase[SIZE], int newcase[SIZE], 
                int totdeath[SIZE], int newdeath[SIZE], int pop[SIZE])
{
    int minI;   //holds the minI data
    int minV;   //holds the minV data
    
    //tests to see if all elements of the array have been stepped through. If they have, loop ends.
    for (int start = 0; start < (SIZE - 1); start ++)
    {
        //sets minI and minV to the current element of the array we are testing.
        minI = start;
        minV = newdeath[start];
        
        //steps through each element on the array, testing them. After all elements have been stepped through, loop stops
        for (int i = start + 1; i < SIZE; i ++)
        {
            //tests to see if a element is smaller than the current element in its spot. If it is, minV and minI are set to
            //the current elements spot (to soon be swapped if it is the smalest)
            if(newdeath[i] < minV)
            {
                minV = newdeath[i];
                minI = i;
            }
        }
        //swaps elements of the array to fit ascending newdeath order.
        swap(name[minI],name[start]);
        swap(totcase[minI],totcase[start]);
        swap(newcase[minI],newcase[start]);
        swap(totdeath[minI],totdeath[start]);
        swap(newdeath[minI],newdeath[start]);
        swap(pop[minI],pop[start]);
    }
}

//purpose:swaps two varaibles
//parameters:a and b are used (along with temp) to swap the value of two variables/elements.
void swap(int &a,int &b)
{
    int temp = a;   //used to hold temp data (set to a)
    
    //sets a to b and b to temp (which is a)
    a = b;
    a = b;
    b = temp;
}
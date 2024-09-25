//assignment: lab7_p3
//purpose: This program takes in covid data from a file into a structure. it then finds the average, highest, and lowest
//of each data in the structure as well as the deaths per million people of each country.
//name: Jenna Wolf
//student ID: 0347845
//date: March 14th, 2023
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct Covid
{
    string name;
    int tcase;
    int ncase;
    int tdeath;
    int ndeath;
    int pop;
};

int numOfCountry();
void getFileData(Covid *, int);
int avgTotCase(Covid *, int);
int avgNewCase(Covid *, int);
int avgTotDeath(Covid *, int);
int avgNewDeath(Covid *, int);
int highTotCase(Covid *, int);
int highNewCase(Covid *, int);
int highTotDeath(Covid *, int);
int highNewDeath(Covid *, int);
int lowTotCase(Covid *, int);
int lowNewCase(Covid *, int);
int lowTotDeath(Covid *, int);
int lowNewDeath(Covid *, int);
void deathPerMil(Covid *, int);
int main()
{
    Covid * ptr;    //holds the ptr data (is a pointer)
    int c;          //holds the c data
    
    //explains what this program does
    cout << "This program will take in covid data from a file. It will find the average, highest, and lowest of total cases,"
    cout << endl << "new cases, total deaths, and new deaths as well as finding the deaths per million of each country" << endl << endl;
    
    c = numOfCountry(); //calls the numOfCountry function and sets c to it
    
    ptr = new Covid[c]; //sets ptr to a covid array of size c
    
    //calls the getFileData function
    getFileData(ptr, c);
    
    //calls the average functions and displays their outcomes
    cout << "The average of the total cases is " << avgTotCase(ptr, c) << endl;
    cout << "The average of the new cases is " << avgNewCase(ptr, c) << endl;
    cout << "The average of the total deaths is " << avgTotDeath(ptr, c) << endl;
    cout << "The average of the new deaths is " << avgNewDeath(ptr, c) << endl;
    
    //calls the highest functions and displays their outcomes
    cout << "The country with the highest amount of total cases is " << ptr[highTotCase(ptr, c)].name << endl;
    cout << "The country with the highest amount of new cases is " << ptr[highNewCase(ptr, c)].name << endl;
    cout << "The country with the highest amount of total deaths is " << ptr[highTotDeath(ptr, c)].name << endl;
    cout << "The country with the highest amount of new deaths is " << ptr[highNewDeath(ptr, c)].name << endl;
    
    //calls the lowest functions and displays their outcomes
    cout << "The country with the lowest amount of total cases is " << ptr[lowTotCase(ptr, c)].name << endl;
    cout << "The country with the lowest amount of new cases is " << ptr[lowNewCase(ptr, c)].name << endl;
    cout << "The country with the lowest amount of total deaths is " << ptr[lowTotDeath(ptr, c)].name << endl;
    cout << "The country with the lowest amount of new deaths is " << ptr[lowNewDeath(ptr, c)].name << endl;
    
    //calls the death per million function
    deathPerMil(ptr, c);
    
    return 0;
}

//purpose: the purpose of this function is to check how many lines are in the file (see how much data the file has) and
//set c to that amount
//arguments: no arguments
int numOfCountry()
{
    int lines;                  //holds the lines data
    string temp;                //holds the temp data
    ifstream infile;            //holds the infile data
    infile.open("covid.txt");    //opens the file
    
    //Makes sure file is opened correctly. Error is sent out if it is not
    if(!infile)
    {
        cout << "File failed to open, try again" << endl;
        exit(EXIT_FAILURE);
    }
    
    //goes through each line of the file until their is no data left. adds one to lines each time
    while(getline(infile, temp))
        lines += 1;
    
    //returns lines
    return lines;
    
}

//purpose: gets the data from the file and sets it to ptr
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
void getFileData(Covid * ptr, int c)
{
    int temp;                   //holds the temp data
    ifstream infile;            //holds the infile data
    infile.open("covid.txt");    //opens the file
    
    //Makes sure file is opened correctly. Error is sent out if it is not
    if(!infile)
    {
        cout << "File failed to open, try again" << endl;
        exit(EXIT_FAILURE);
    }
    
    //steps through the info in the file and sets it to ptr
    for(int i = 0; i < c; i++)
    {
        infile >> temp;
        infile >> ptr[i].name;
        infile >> ptr[i].tcase;
        infile >> ptr[i].ncase;
        infile >> ptr[i].tdeath;
        infile >> ptr[i].ndeath;
        infile >> ptr[i].pop;
    }
    
}

//purpose: gets the average of the data held in the ptr tcase array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int avgTotCase(Covid * ptr, int c)
{
    int a = 0;  //holds the a data
    
    //steps through each element of the array
    for(int i = 0; i < c; i++)
    {
        //adds all elements to a
        a += ptr[i].tcase;
    }
        
    a = a/c;    //divides a by c (the size of the array)
    
    //returns a
    return a;
}

//purpose: gets the average of the data held in the ptr ncase array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int avgNewCase(Covid * ptr, int c)
{
    int a = 0;  //holds the a data
    
    //steps through each element of the array
    for(int i = 0; i < c; i++)
    {
        //adds all elements to a
        a += ptr[i].ncase;
    }
        
    a = a/c;    //divides a by c (the size of the array)
    
    //returns a
    return a;
}

//purpose: gets the average of the data held in the ptr tdeath array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int avgTotDeath(Covid * ptr, int c)
{
    int a = 0;  //holds the a data
    
    //steps through each element of the array
    for(int i = 0; i < c; i++)
    {
        //adds all elements to a
        a += ptr[i].tdeath;
    }
        
    a = a/c;    //divides a by c (the size of the array)
    
    //returns a
    return a;
}

//purpose: gets the average of the data held in the ptr ndeath array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int avgNewDeath(Covid * ptr, int c)
{
    int a = 0;  //holds the a data
    
    //steps through each element of the array
    for(int i = 0; i < c; i++)
    {
        //adds all elements to a
        a += ptr[i].ndeath;
    }
        
    a = a/c;    //divides a by c (the size of the array)
    
    //returns a
    return a;
}

//purpose: gets the highest of the data held in the ptr tcase array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int highTotCase(Covid * ptr, int c)
{
    int high = 0;   //holds the high data
    
    //steps through each element of the array
    for(int i = 1; i < c; i++)
    {
        //checks the see if the current high variable is less than the current variable. if it is, high is set to i.
        if(ptr[high].tcase < ptr[i].tcase)
            high = i;
    }
    
    //returns high
    return high;
}

//purpose: gets the highest of the data held in the ptr ncase array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int highNewCase(Covid * ptr, int c)
{
    int high = 0;   //holds the high data
    
    //steps through each element of the array
    for(int i = 1; i < c; i++)
    {
        //checks the see if the current high variable is less than the current variable. if it is, high is set to i.
        if(ptr[high].ncase < ptr[i].ncase)
            high = i;
    }
    
    //returns high
    return high;
}

//purpose: gets the highest of the data held in the ptr tdeath array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int highTotDeath(Covid * ptr, int c)
{
    int high = 0;   //holds the high data
    
    //steps through each element of the array
    for(int i = 1; i < c; i++)
    {
        //checks the see if the current high variable is less than the current variable. if it is, high is set to i.
        if(ptr[high].tdeath < ptr[i].tdeath)
            high = i;
    }
    
    //returns high
    return high;
}

//purpose: gets the highest of the data held in the ptr ndeath array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int highNewDeath(Covid * ptr, int c)
{
    int high = 0;   //holds the high data
    
    //steps through each element of the array
    for(int i = 1; i < c; i++)
    {
        //checks the see if the current high variable is less than the current variable. if it is, high is set to i.
        if(ptr[high].ndeath < ptr[i].ndeath)
            high = i;
    }
    
    //returns high
    return high;
}

//purpose: gets the lowest of the data held in the ptr tcase array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int lowTotCase(Covid * ptr, int c)
{
    int low = 0;    //holds the low data
    
    //steps through each element of the array
    for(int i = 1; i < c; i++)
    {
        //checks the see if the current low variable is more than the current variable. if it is, low is set to i.
        if(ptr[low].tcase > ptr[i].tcase)
            low = i;
    }
    
    //returns low
    return low;
}

//purpose: gets the lowest of the data held in the ptr ncase array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int lowNewCase(Covid * ptr, int c)
{
    int low = 0;    //holds the low data
    
    //steps through each element of the array
    for(int i = 1; i < c; i++)
    {
        //checks the see if the current low variable is more than the current variable. if it is, low is set to i.
        if(ptr[low].ncase > ptr[i].ncase)
            low = i;
    }
    
    //returns low
    return low;
}

//purpose: gets the lowest of the data held in the ptr tdeath array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int lowTotDeath(Covid * ptr, int c)
{
    int low = 0;    //holds the low data
    
    //steps through each element of the array
    for(int i = 1; i < c; i++)
    {
        //checks the see if the current low variable is more than the current variable. if it is, low is set to i.
        if(ptr[low].tdeath > ptr[i].tdeath)
            low = i;
    }
    
    //returns low
    return low;
}

//purpose: gets the lowest of the data held in the ptr ndeath array
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
int lowNewDeath(Covid * ptr, int c)
{
    int low = 0;    //holds the low data
    
    //steps through each element of the array
    for(int i = 1; i < c; i++)
    {
        //checks the see if the current low variable is more than the current variable. if it is, low is set to i.
        if(ptr[low].ndeath > ptr[i].ndeath)
            low = i;
    }
    
    //returns low
    return low;
}

//purpose: gets the deaths per million for each country and displays it
//arguments: ptr is what holds the data being checked, c is the size and is what is steped through during checks
void deathPerMil(Covid * ptr, int c)
{
    double m;   //holds the m data

    //steps through each element of the array
    for(int i = 0; i < c; i++)
    {
        //sets m to the total deaths divided by the population times 10 to the power of 6
        m = (static_cast<double>(ptr[i].tdeath) / static_cast<double>(ptr[i].pop)) * pow(10,6);
        
        //displays the calculated amount of deaths per million people
        cout << "The amount of deaths per million people for " << ptr[i].name << " is " << m << endl;
    }
}
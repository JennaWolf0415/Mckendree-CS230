//assignment: lab7_p1
//purpose: this program takes in a string of digits from the user and finds the sum of those digits, the highest of those digits,
//and the lowest of those digits
//name: Jenna Wolf
//student ID: 0347845
//date: March 14th, 2023
#include <iostream>
#include <cctype>
#include <string>

using namespace std;
int sum(string);
int high(string);
int low(string);
int main()
{
    string digs;    //holds the digs data
    bool wrong;     //holds the wrong data
    
    //explains what the program does
    cout << "this program will take a line of numbers that the user enters and find the sum of all those numbers!" << endl;
    cout << "this program also finds the lowest and highest digit the user entered!" << endl;
    
    //gets the input from the user
    cout << "Enter a line of digits ";
    getline(cin, digs);
    
    //checks to make sure only digits are entered. Sends out an error message if non digits were entered
    do
    {
        wrong = false;  //sets wrong to false
        
        //goes through each variable in the string and checks if they are a digit
        for(int i = 0; i < digs.length(); i++)
        {
            //checks to see if the current variable is a digit. if not, wrong is set to true
            if(!isdigit(digs[i]))
                wrong = true;
        }
        
        //if wrong was set to true, then it gets a new input from the user
        if(wrong)
        {
            cout << "please enter only digits! ";
            getline(cin, digs);
        }
    }
    while(wrong);   //loop repeats while wrong is set to true
    
    //calls the sum function and displays the output
    cout << "the sum of all the digits is " << sum(digs) << endl;
    
    //calls the high and low function and displays the output
    cout << "the highest digit is " << digs[high(digs)] << endl;
    cout << "the lowest digit is " << digs[low(digs)] << endl;
    
    return 0;
}

//purpose:
//arguments: string is sent over because it is what is being checked
int sum(string digs)
{
    int s = 0;  //holds the data for s
    
    //goes through each varaible of the string and adds them to s.
    for(int i = 0; i < digs.length(); i++)
    {
        s += digs[i] - 48;
    }
    
    //returns s (or the sum)
    return s;
}

//purpose:
//arguments: string is sent over because it is what is being checked
int high(string digs)
{
    int high = 0;   //holds the high data
    
    //goes through each variable of the string
    for(int i = 0; i < digs.length(); i++)
    {
        //checks to see if the current variable is higher than the current high variable. if it is, high is set to said varaible.
        if(digs[i] > digs[high])
            high = i;
    }
    
    //returns high
    return high;
}

//purpose:
//arguments: string is sent over because it is what is being checked
int low(string digs)
{
    int low = 0;    //holds the low data
    
    //goes through each variable of the string
    for(int i = 0; i < digs.length(); i++)
    {
        //checks to see if the current variable is higher than the current high variable. if it is, high is set to said varaible.
        if(digs[i] < digs[low])
            low = i;
    }
    
    //returns low
    return low;
}
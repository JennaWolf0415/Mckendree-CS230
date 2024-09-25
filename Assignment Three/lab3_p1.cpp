//File:lab3_p1
//Description: Generate a random number between 100 and 500. Then try to guess the number. Display weather you got the number,
//your guess is too high, or your guess is too low. Loop over and over until the right number is inputted.
//Author: Jenna Wolf
//Student ID: 0347845
//Date: January 31st, 2023
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int number;             // holds the number value
    int guess;              // holds the guess value
    bool correct;           // holds the correct value
    const int MAX = 501;    // holds the man value at 501
    const int MIN = 99;     //holds the min value at 99
    
    //Explains what this program is for
    cout << "This program picks a random number between 100 and 500. It is your job to guess that number!" << endl;
    
    //Assigns a random number to number (gets the number to be guessed). Is a loop to make sure number is between 100 and 500
    srand(time(0));
    number = rand() % 401 + 100;
    
    //The loop that keeps going until the correct value is guessed
    do
    {
        
        //Lets the user input a guess
        cout << "What is your guess? ";
        cin >> guess;
        cin.ignore(10,'\n');
        
        
        //Checks to see if number is correct. If it is, displays that it is correct and sets correct to true.
        if (guess == number)
        {
            cout << "Congrats! You guessed the number right!";
            correct = true;
        }
        
        //Checks to see if number is too high. If it is, displays that number is too high
        else if (guess > number)
            cout << "Too high, try again!" << endl;
            
        //Displays that number is too low
        else
            cout << "Too low, try again!" << endl;
    
    }
    while (correct == false);

    return 0;
}
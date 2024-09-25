//File: lab2_p2.cpp
//Description: This program takes in the amount of books the user has read for the month and tells them how many points they earned
//Student ID: 0347845
//Date: January 23rd, 2023
#include <iostream>

using namespace std;

int main()
{
    int books;      //holds the books data 
    
    //Tells the user what this program does
    cout << "This program takes the amount of books the user has read each month and tells them how many" << endl;
    cout << "points they have earned this month!" << endl;
    
    //Takes in the amount of books the user has read this month
    cout << "How many books have you bought this month?: ";
    cin >> books;
    cin.ignore(10,'\n');
    
    //Displays to the user how many books they have read and how many points they have got
    switch (books > 4)
    {
        case 1:
            cout << "You bought 5 or more books this month. You got 50 points!" << endl;
            break;
        case 0:
            switch (books > 2)
            {
                case 1:
                    cout << "You bought 3 or 4 books this month. You got 25 points!" << endl;
                    break;
                case 0:
                    switch (books > 1)
                    {
                        case 1:
                            cout << "You bought 2 books this month. You got 12 points!" << endl;
                            break;
                        case 0:
                            switch (books > 0)
                            {
                                case 1:
                                    cout << "You bought 1 books this month. You got 7 points!" << endl;
                                    break;
                                case 0:
                                    switch (books > -1)
                                    {
                                        case 1:
                                            cout << "You bought 0 books this month. You got 0 points!" << endl;
                                            break;
                                        case 0:
                                            cout << "Please enter a number above 0 next time!" << endl;
                                            break;
                                        
                                    }
                                
                            }
                            break;
                    }
                    break;
            }
            break;
        
    }

    return 0;
}
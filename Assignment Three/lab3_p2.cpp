//File:lab3_p2
//Description: Takes in banking information from the user (the starting balance, annual interest rate, months since the
//account has been open, and deposits and withdrawals from each month) and calculates the total amount in the account,
//the amount deposited/withdrawn each month, and how much was earned off of interest.
//Author: Jenna Wolf
//Student ID: 0347845
//Date: January 31st, 2023
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    
    double balance;         // holds the balance value
    double annintrate;      // holds the annual interest rate value
    double monthintrate;    // holds the monthly interest rate value
    double interest;        // holds the interest value
    int months;             // holds the months value
    double deposite;        // holds the deposites value
    double withdraw;        // holds the withdrawals value
    double intearned = 0;   // holds the total interest value (starts at 0)
    double deps = 0;        // holds the total deposites value (starts at 0)
    double withs = 0;       // holds the total withdrawal value (starts at 0)
    
    //Explains what the program does
    cout << "This program will take in your banking information (your starting balance, annual interest rate, months since the account";
    cout << endl << "has been open, and how much you add/take out each month) and will calculate the current amount in your account ";
    cout << endl << "along with how much you have deposited, withdrawn, and how much you have earned from interest!" << endl << endl;
    
    //Gets the starting balance
    cout << "What is your starting balance? ";
    cin >> balance;
    cin.ignore(10,'\n');
    while(balance < 0)
    {
        cout << "please enter a positive number! ";
        cin >> balance;
    }
    
    //Gets the annual interest rate
    cout << "What is your annual interest rate? (must be 0-100 percent, cannot be higher or lower) ";
    cin >> annintrate;
    cin.ignore(10,'\n');
    while(annintrate < 0 || annintrate > 100)
    {
        cout << "please enter a percentage between 0 and 100! ";
        cin >> annintrate;
    }
    
    //Gets the monthly interest rate and puts it in decimal form
    monthintrate = annintrate / 12;
    monthintrate = monthintrate / 100;
    
    //Takes in how many months its been since the account was created
    cout << "How many months have passed since the account was created? ";
    cin >> months;
    cin.ignore(10,'\n');
    while(months < 0)
    {
        cout << "Please enter a positive number! ";
        cin >> months;
    }

    //takes in depsoites and withdraws and performs calculations for each month.
    for(int num = 0; num < months; num++)
    {
        //Takes in deposites and withdraws. Makes sure they are positive.
        cout << "For month " << num+1 << ", how much did you deposite into your account? ";
        cin >> deposite;
        while(deposite < 0)
        {
            cout << "Please enter a positive number! ";
            cin >> deposite;
        }
        deps = deps + deposite;
        cout << "For month " << num+1 << ", how much did you withdraw of your account? ";
        cin >> withdraw;
        while(withdraw < 0)
        {
            cout << "Please enter a positive number! ";
            cin >> withdraw;
        }
        withs = withs + withdraw;
        
        //calculates the new balance and how much interest there has been.
        balance = balance + deposite;
        balance = balance - withdraw;
        interest = balance * monthintrate;
        balance = interest + balance;
        intearned = intearned + interest;
        
        //adds a empty line
        cout << endl;
    }
    
    //sets answers to 2 decimal points
    cout << fixed << showpoint << setprecision(2);
    
    //displays banking/calculated info
    cout << endl << std::left << setw(40) << "Ending Balance:" << "$" << balance << endl;
    cout << setw(40) << "Total amount of deposites:" << "$" << deps << endl;
    cout << setw(40) << "Total amount of withdrawals:" << "$" << withs << endl;
    cout << setw(40) << "Total amount of interest earned: " << "$" << intearned << endl;
    
    
    return 0;
}

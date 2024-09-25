//File: lab2_p1.cpp
//Description: Take in information about a loan from the user, calculate the amount paid per month, the amount paid
//back in total, and how much of the total payment was interest and display all information to the user.
//Student ID: 0347845
//Date: January 23rd, 2023
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double payment;             //holds the payment value
    double rate;                //holds the rate value
    int numpay;                 //holds the number of payments value
    double loan;                //holds the loan value
    double APB;                 //holds the amount paid back value
    double interest;            //holds the interest value
    
    //Explains what the program does
    cout << "This program will ask the user for their Loan amount, their monthly interest rate, and their number of payments." << endl;
    cout << "After getting that information, the program will calculate the users monthly payment, their amount paid back in total, " << endl;
    cout << "and how much of that was interest." << endl;

    //Takes in information about the loan from the user
    cout << "What is your loan amount: ";
    cin >> loan;
    cin.ignore(10,'\n');
    cout << "What is your monthly interest rate: ";
    cin >> rate;
    cin.ignore(10,'\n');
    cout << "How many payments will you have (number of payments): ";
    cin >> numpay;
    cin.ignore(10,'\n');
    
    //Performs the calculations
    rate = rate / 100;
    payment = ((rate * pow((1 + rate),numpay)) / (pow((rate + 1),numpay) - 1)) * loan;
    APB = numpay * payment;
    interest = APB - loan;
    
    //sets answers to 2 decimal spots
    cout << fixed << showpoint << setprecision(2);
    
    //output of all the information in chart form
    cout << std::left << setw(30) << "Loan amount: "<< "$ " << loan << endl;
    cout << setw(30) << "Monthly Interest Rate: " << "$ " << rate << endl;
    cout << setw(30) << "Number of Payments: " << "$ " << numpay << endl;
    cout << setw(30) << "Monthly Payment: " << "$ " << payment << endl;
    cout << setw(30) << "Amount Paid Back: " << "$ " << APB << endl;
    cout << setw(30) << "Interest Paid: " << "$ " << interest << endl;
    return 0;
}

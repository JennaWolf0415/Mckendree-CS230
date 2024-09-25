//File:lab3_p4
//Description: Lets the user select either inpatient or outpatient. Then takes in data and calculates the total cost based on the selection.
//Author: Jenna Wolf
//Student ID: 0347845
//Date: January 31st, 2023

#include <iostream>

using namespace std;

double patient(int, double, double, double);
double patient(double, double);
int main()
{
    int awn;            //holds the awn data
    double total;       //holds the total data
    int dayspent;       //holds the days spent data
    double dailyrate;   //holds the daily rate data
    double medcharge;   //holds the medication charge data
    double hospservice; //holds the hospital service data
    
    //Tells the user what this program Does
    cout << "This program lets you choose weather you were an inpatient or outpatient. It will then take in your data"
    cout << endl << "based on that selection and tell you your total charge" << endl;
    
    //Allows user to select inpatient or outpatient
    cout << "Choose one option:"<<endl;
    cout << "1.Inpatient"<<endl;
    cout << "2.Outpatient"<<endl;
    cin >> awn;
    cin.ignore(10,'\n');
    
    //Makes sure user picked a proper option
    while(awn < 1 || awn > 2)
        {
        cout << "Pick a proper option!"<<endl;
        cin >> awn;
        cin.ignore(10,'\n');
        }
        
    //Inpatient choice
    if(awn == 1)
        {
            
            //Takes in data for days spent and makes sure its positive.
            cout << "How many days did you stay at the hospital? ";
            cin >> dayspent;
            cin.ignore(10,'\n');
            while(dayspent < 0)
                {
                cout << "Please enter a positive number! ";
                cin >> dayspent;
                cin.ignore(10,'\n');
                }
            
            //Takes in data for daily rate and makes sure its positive.
            cout << "What was your daily rate? ";
            cin >> dailyrate;
            cin.ignore(10,'\n');
            while(dailyrate < 0)
                {
                cout << "Please enter a positive number! ";
                cin >> dailyrate;
                cin.ignore(10,'\n');
                }
                
            //Takes in data for medication charges and makes sure its positive.
            cout << "How much were your meication charges? ";
            cin >> medcharge;
            cin.ignore(10,'\n');
            while(medcharge < 0)
                {
                cout << "Please enter a positive number! ";
                cin >> medcharge;
                cin.ignore(10,'\n');
                }
            
            //Takes in data for hospital service charges and makes sure its positive.
            cout << "How much were your hospital service charges? ";
            cin >> hospservice;
            cin.ignore(10,'\n');
            while(hospservice < 0)
                {
                cout << "Please enter a positive number! ";
                cin >> hospservice;
                cin.ignore(10,'\n');
                }    
            
            //Sends info to patient function to calculate total
            total = patient(dayspent, dailyrate, medcharge, hospservice);
            
            //Displays the total to the user
            cout << "The total for this patient is $"<<total<<endl<<endl;
        }
        
    //Outpatient choice
    else
        {
            //Takes in data for medical charges and makes sure its positive.
            cout << "How much were your meication charges? ";
            cin >> medcharge;
            cin.ignore(10,'\n');
            while(medcharge < 0)
                {
                cout << "Please enter a positive number! ";
                cin >> medcharge;
                cin.ignore(10,'\n');
                }
            
            //Takes in data for hospital services and makes sure its positive.
            cout << "How much were your hospital service charges? ";
            cin >> hospservice;
            cin.ignore(10,'\n');
            while(hospservice < 0)
                {
                cout << "Please enter a positive number! ";
                cin >> hospservice;
                cin.ignore(10,'\n');
                }
            
            //Sends info to patient function to calculate total
            total = patient(medcharge, hospservice);
            
            //Displays the total to the user
            cout << "The total for this patient is $"<<total<<endl<<endl;
        }
    return 0;
}

//Purpose: The purpose of this function is to take in the data for an inpatient and calculate their total.
//It then sends back that total.
//Parameters: The days, rate, med, and service are all made to hold the data sent over from main so that the function
//can perform the calculations and send back the results of said caluclations.
double patient(int days, double rate, double med, double service)
{
    int tot;    //holds the total data
    
    //Does the calculation then returns the total amount.
    tot = (days * rate) + med + service;
    return tot;
}

//Purpose: The purpose of this function is to take in the data for an outpatient and calculate their total.
//It then sends back that total.
//Parameters: The days and rate are all made to hold the data sent over from main so that the function
//can perform the calculations and send back the results of said caluclations.
double patient(double med, double service)
{
    int tot;    //holds the total data
    
    //Does the calculation then returns the total amount.
    tot = med + service;
    return tot;
}
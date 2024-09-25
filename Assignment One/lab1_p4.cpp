//File: lab1_p4.cpp
//Description: This program calculates and displays the amount of customers from random soft drink company that
//purchase an energy drink each and week and that perfer citrus flavored energy drinks
//Student ID: 0347845
//Date: January 20th, 2023
#include <iostream>

using namespace std;

int main()
{
    
    int energyDrinkCustomers;               //Holds the data value for people who drink energy drinks
    int citrusCustomers;                    //Holds the data value for people who like citrus
    const int CUSTOMERS = 18200;            //Holds the CUSTOMER data value as 18200
    const double ENERGYDRINKS = 0.19;       //Holds the ENERGYDRINKS data value as the percentage 0.19
    const double CITRUS = 0.73;             //Holds the CITRUS data value as the percentage 0.73
    
    //Explains the purpose of the program
    cout << "This program displays how many customers for random soft drink company drink energy drinks and how" << endl;
    cout << "many perfer citrus flavored energy drinks." << endl << endl;
    
    //Does the calculations for the amount of customers who drink energy drinks and who perfer citrus
    energyDrinkCustomers = CUSTOMERS * ENERGYDRINKS;
    citrusCustomers = energyDrinkCustomers * CITRUS;
    
    //Displays the amount of people who drink energy drinks and who perfer citrus
    cout << "out of " << CUSTOMERS << " customers, " << energyDrinkCustomers << " customers purchase one of more" << endl;
    cout << "energy drinks per week. Out of those customers, " << citrusCustomers << " perfer citrus flavors.";

    return 0;
}

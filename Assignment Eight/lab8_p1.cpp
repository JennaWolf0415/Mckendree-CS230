//file: lab8_p1
//description: This program will take in input from the user about how much they spent in each catagory for the
//month. It will then compare these amount to the budget the student has set up for each month and tell them
//if they were overbudget or underbudget in each catagory as well as if they are overbudget or underbudget for 
//the combined amounts
//author: Jenna Wolf
//id: 0347845
//date: March 22nd, 2023
#include <iostream>
#include <iomanip>

using namespace std;

struct MonthlyBudget
{
    double house;       //holds the house data
    double utilities;   //holds the utilities data
    double houseexp;    //holds the household expenses data
    double trans;       //holds the transportation data
    double food;        //holds the food data
    double med;         //holds the medical data
    double insur;       //holds the insurance data
    double entert;      //holds the entertainment data
    double cloth;       //holds the clothing data
    double mic;         //holds the miscellaneous data
};
const double HOUSEB = 500;      //holds the HOUSEB data as a constant at 500
const double UTILB = 150;       //holds the UTILB data as a constant at 150
const double HOUSEEXPB = 65;    //holds the HOUSEEXPB data as a constant at 65
const double TRANSB = 50;       //holds the TRANSB data as a constant at 50
const double FOODB = 250;       //holds the FOODB data as a constant at 250
const double MEDB = 30;         //holds the MEDB data as a constant at 30
const double INSURB = 100;      //holds the INSURB data as a constant at 100
const double ENTERTB = 150;     //holds the ENTERTB data as a constant at 150
const double CLOTHB = 75;       //holds the CLOTHB data as a constant at 75
const double MICB = 50;         //holds the MICB data as a constant at 50

void money(MonthlyBudget &);
void display(MonthlyBudget);
int main()
{
    MonthlyBudget student;  //holds the student data
    
    //explains what the program does
    cout << "this program will take in input from the user on how much they spent in each catagory for the month.";
    cout << endl << "the program will then calculate if the user was overbudget or underbudget in each catagory";
    cout << endl << "as well as if they were overbudget or underbudget overall!" << endl << endl;
    
    money(student);     //calls the money function
    display(student);   //calls the display function
    return 0;
}

//purpose: this function takes in data from the user for each variable in the student data type.
//arguments: student is sent over because it is what is holding the data that is entered
void money(MonthlyBudget &student)
{
    //gets input from the user for house budget and makes sure it is positive
    cout << "Enter the amount you spent on housing this month: $";
    cin >> student.house;
    while(student.house < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.house;
    }
    
    //gets input from the user for utilities budget and makes sure it is positive
    cout << "Enter the amount you spent on utilities this month: $";
    cin >> student.utilities;
    while(student.utilities < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.utilities;
    }
    
    //gets input from the user for household expenses budget and makes sure it is positive
    cout << "Enter the amount you spent on household expenses this month: $";
    cin >> student.houseexp;
    while(student.houseexp < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.houseexp;
    }
    
    //gets input from the user for transportation budget and makes sure it is positive
    cout << "Enter the amount you spent on transportation this month: $";
    cin >> student.trans;
    while(student.trans < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.trans;
    }
    
    //gets input from the user for food budget and makes sure it is positive
    cout << "Enter the amount you spent on food this month: $";
    cin >> student.food;
    while(student.food < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.food;
    }
    
    //gets input from the user for medical budget and makes sure it is positive
    cout << "Enter the amount you spent on medical this month: $";
    cin >> student.med;
    while(student.med < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.med;
    }
    
    //gets input from the user for insurance budget and makes sure it is positive
    cout << "Enter the amount you spent on insurance this month: $";
    cin >> student.insur;
    while(student.insur < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.insur;
    }
    
    //gets input from the user for entertainment budget and makes sure it is positive
    cout << "Enter the amount you spent on entertainment this month: $";
    cin >> student.entert;
    while(student.entert < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.entert;
    }
    
    //gets input from the user for clothing budget and makes sure it is positive
    cout << "Enter the amount you spent on clothing this month: $";
    cin >> student.cloth;
    while(student.cloth < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.cloth;
    }
    
    //gets input from the user for miscellaneous budget and makes sure it is positive
    cout << "Enter the amount you spent on miscellaneous this month: $";
    cin >> student.mic;
    while(student.mic < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> student.mic;
    }
}

//purpose: displays the catagory, amount left in the catagory, and weather the user was underbudget
//or overbudget for each catagory in type monthlybudget
//arguments:student is sent over because it's data is being used/displayed
void display(MonthlyBudget student)
{
    //holds the money data and sets it to the constant's added together minus the students data added together
    double money = (HOUSEB + UTILB + HOUSEEXPB + TRANSB + FOODB + MEDB + INSURB + ENTERTB + CLOTHB + MICB) - 
        (student.house + student.utilities + student.houseexp + student.trans + student.food + 
        student.med + student.insur + student.entert + student.cloth + student.mic);
        
    cout << fixed << showpoint << setprecision(2);  //makes sure decimals are set to 2 places
    
    //displays headers for the columns
    cout << endl << std::left << setw(20) << "Catagory" << setw(15) << "Amount left" << "over/underbudget" << endl;
    
    //checks to see is house was over/underbudget. displays catagory, amount left, and result of if statement
    if(HOUSEB - student.house < 0)
        cout << std::left << setw(20) << "housing: " << setw(15) << HOUSEB - student.house << " YOU WERE OVERBUDGET" << endl;
    else
         cout << std::left << setw(20) << "housing: " << setw(15) << HOUSEB - student.house << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is utilities was over/underbudget. displays catagory, amount left, and result of if statement     
    if(UTILB - student.utilities < 0)
        cout << setw(20) << "utilities: " << setw(15) << UTILB - student.utilities << " YOU WERE OVERBUDGET" << endl;
    else
         cout << setw(20) << "utilities: " << setw(15) << UTILB - student.utilities << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is household expenses was over/underbudget. displays catagory, amount left, and result of if statement     
    if(HOUSEEXPB - student.houseexp < 0)
        cout << setw(20) << "house expenses: " << setw(15) << HOUSEEXPB - student.houseexp << " YOU WERE OVERBUDGET" << endl;
    else
         cout << setw(20) << "house expenses: " << setw(15) << HOUSEEXPB - student.houseexp << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is transportation was over/underbudget. displays catagory, amount left, and result of if statement     
    if(TRANSB - student.trans < 0)
        cout << setw(20) << "transportation: " << setw(15) << TRANSB - student.trans << " YOU WERE OVERBUDGET" << endl;
    else
         cout << setw(20) << "transportation: " << setw(15) << TRANSB - student.trans << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is food was over/underbudget. displays catagory, amount left, and result of if statement     
    if(FOODB - student.food < 0)
        cout << setw(20) << "food: " << setw(15) << FOODB - student.food << " YOU WERE OVERBUDGET" << endl;
    else
         cout << setw(20) << "food: " << setw(15) << FOODB - student.food << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is medical was over/underbudget. displays catagory, amount left, and result of if statement
    if(MEDB - student.med < 0)
        cout << setw(20) << "medical: " << setw(15) << MEDB - student.med << " YOU WERE OVERBUDGET" << endl;
    else
         cout << setw(20) << "medical: " << setw(15) << MEDB - student.med << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is insurance was over/underbudget. displays catagory, amount left, and result of if statement
    if(INSURB - student.insur < 0)
        cout << setw(20) << "insurance: " << setw(15) << INSURB - student.insur << " YOU WERE OVERBUDGET" << endl;
    else
         cout << setw(20) << "insurance: " << setw(15) << INSURB - student.insur << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is entertainment was over/underbudget. displays catagory, amount left, and result of if statement     
    if(ENTERTB - student.entert < 0)
        cout << setw(20) << "entertainment: " << setw(15) << ENTERTB - student.entert << " YOU WERE OVERBUDGET" << endl;
    else
         cout << setw(20) << "entertainment: " << setw(15) << ENTERTB - student.entert << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is clothing was over/underbudget. displays catagory, amount left, and result of if statement     
    if(CLOTHB - student.cloth < 0)
        cout << setw(20) << "clothing: " << setw(15) << CLOTHB - student.cloth << " YOU WERE OVERBUDGET" << endl;
    else
         cout << setw(20) << "clothing: " << setw(15) << CLOTHB - student.cloth << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is miscellaneous was over/underbudget. displays catagory, amount left, and result of if statement     
    if(MICB - student.mic < 0)
        cout << setw(20) << "miscellaneous: " << setw(15) << MICB - student.mic << " YOU WERE OVERBUDGET" << endl;
    else
         cout << setw(20) << "miscellaneous: " << setw(15) << MICB - student.mic << " YOU WERE UNDERBUDGET" << endl;
    
    //checks to see is money was over/underbudget. displays catagory, amount left, and result of if statement
    if(money < 0)
        cout << setw(20) << "money left: " << setw(15) << money << " YOU WERE OVERBUDGET";
    else
        cout << setw(20) << "money left: " << setw(15) << money << " YOU WERE UNDERBUDGET";
    
}
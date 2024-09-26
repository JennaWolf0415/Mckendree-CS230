//program: Stockbroker
//purpose: This program uses friends and static variables to calculate the total amount Brian makes with stocks and bonds
//name: Jenna Wolf
//id: 0347845
//date: May 4th, 2023

#include <iostream>

using namespace std;

class Stocks
{
    private:
        string name;            //holds the name data
        int number;             //holds the number data
        double costPerShare;    //holds the costPerShare data
    public:
        Stocks(string, int, double);
        double calcProfit(double) const;
        string getName();
};

class Bonds
{
    private:
        string name;            //holds the name data
        int number;             //holds the number data
        double faceValue;       //holds the faceValue data
        double interestRate;    //holds the interestRate data
    public:
        Bonds(string, int, double, double);
        double calcProfit(int, double) const;
        string getName();
};

class Brian
{
    private:
        static double totalProfit;  //holds the totalProfit data
    public:
        friend double Stocks::calcProfit(double) const;
        friend double Bonds::calcProfit(int, double) const;
        double getTotalProfit();
};

double Brian::totalProfit = 0;  //sets totalProfit to 0
int main()
{
    Stocks stock("Apple", 4, 6);        //holds the stock data and sets it in the constructor
    Bonds bond("German", 5, 8, .05);    //holds the bond data and sets it in the constructor
    Brian b;                            //holds the b data
    double num1 = 18;                   //holds the num1 data and sets it to 18
    int num2 = 12;                      //holds the num2 data and sets it to 12
    double num3 = 0.02;                 //holds the num3 data and sets it to 0.02
    
    //tells the user what the program does
    cout << "This program caculates and displays what Brian made on his Stocks and his Bonds" << endl;
    
    //caculates and displays what stocks and bonds made. Also displays Brians total profits
    cout << "Stocks: " << stock.getName() << " " << stock.calcProfit(num1) << endl;
    cout << "Bonds: " << bond.getName() << " " << bond.calcProfit(num2, num3) << endl;
    cout << "Brian's Total Profit: " << b.getTotalProfit() << endl;

    return 0;
}

//purpose: constructor that sets the varaibles of stocks to the values sent over
//arguments: str, a, and b are the data the variables in stocks will be set to
Stocks::Stocks(string str, int a, double b)
{
    name = str;         //sets name to str
    number = a;         //sets number to a
    costPerShare = b;   //sets down costPerShare to b
}

//purpose: caculates the profit that Stocks made and adds it to Brian's total profits
//arguments:  salesPrice is used to caculate how much stocks made
double Stocks::calcProfit(double salePrice) const
{
    double temp = 0;    //holds the temp data
    
    //caculates the amount the stocks made and sets it to temp
    temp = (salePrice * number) - (costPerShare * number);
    Brian::totalProfit += temp;     //set totalProfit to itself plus temp
    
    return temp;    //returns the value stored in temp
}

//purpose: returns the value stored in name
//arguments: no arguments
string Stocks::getName()
{
    return name;    //returns the value stored in name
}

//purpose: constructor that sets the values in bonds to the values sent over
//arguments: str, a, b, and c are what the variables in bonds are set to
Bonds::Bonds(string str, int a, double b, double c)
{
    name = str;         //sets name to str
    number = a;         //sets number to a
    faceValue = b;      //sets faceValue to b
    interestRate = c;   //sets interestRate to c
}

//purpose: caculates the profit that Bonds made and adds it to Brian's total profits
//arguments:  numOfYears and inflationRate are used to caculate how much bonds made
double Bonds::calcProfit(int numOfYears, double inflationRate) const
{
    double temp = 0;    //holds the temp data
    
    //caculates the amount the bonds made and sets it to temp
    temp = faceValue * number * numOfYears * (interestRate - inflationRate);
    Brian::totalProfit += temp;     //set totalProfit to itself plus temp
    
    return temp;        //returns the value stored in temp
}

//purpose: returns the value stored in name
//arguments: no arguments
string Bonds::getName()
{
    return name;    //returns the value stored in name
}

//purpose: returns the value stored in totalProfit
//arguments: no arguments
double Brian::getTotalProfit()
{
    return totalProfit;     //returns the value stored in totalProfit
}
//file: lab8_p5
//description: This program has a class of type Inventory and holds private members and public functions.
//(this program is used for practice of constructors)
//author: Jenna Wolf
//id: 0347845
//date: March 22nd, 2023
#include <iostream>

using namespace std;
class Inventory
{
    private:
        int itemNumber;         //holds itemNumber data
        int quanity;            //holds quanity data
        double cost;            //holds cost data
        double totalCost;       //holds totalCost data
    public:
        Inventory();
        Inventory(int, int, double);
        void setItemNumber(int);
        void setQuanity(int);
        void setCost(double);
        void setTotalCost();
        int getItemNumber() const;
        int getQuanity() const;
        double getCost() const;
        double getTotalCost() const;
};

int main()
{
    //displays what this program does
    cout << "this program is practice for classes and constructors." << endl;
    
    return 0;
}

//purpose:  This is a default constructor that sets all quanities of Inventory to 0
//arguments: no arguments
Inventory::Inventory()
{
    itemNumber = 0; //sets itemNumber to 0
    quanity = 0;    //sets quanity to 0
    cost = 0;       //sets cost to 0
    totalCost = 0;  //sets totalCost to 0
}
//purpose:  This is a constructor that sets all quanities of Inventory to the value that is sent over (totalCost is set to 0)
//arguments: a, b, and c hold the data the objects are being set to
Inventory::Inventory(int a, int b, double c)
{
    itemNumber = a;     //sets itemNumber to a
    quanity = b;        //sets quanity to b
    cost = c;           //sets cost to c
    totalCost = 0;      //sets totalCost to 0
}

//purpose: this function sets itemNumber to the quanity that is sent over
//arguments: a holds the data that itemNumber is set to
void Inventory::setItemNumber(int a)
{
    itemNumber = a; //sets itemNumber to a
}

//purpose: this function sets quanity to the quanity that is sent over
//arguments: a holds the data that quanity is set to
void Inventory::setQuanity(int a)
{
    quanity = a;    //sets quanity to a
}

//purpose: this function sets cost to the quanity that is sent over
//arguments: a holds the data that cost is set to
void Inventory::setCost(double a)
{
    cost = a;       //sets cost to a
}

//purpose: this function sets totalCost to the quanity that is sent over from getQuanity and getCost
//arguments: no arguments
void Inventory::setTotalCost()
{
    totalCost = getQuanity() * getCost();   //sets totalCost to the value sent from getQuanity and getCost
}

//purpose: This function returns the value stored in itemNumber
//arguments: no arguements
int Inventory::getItemNumber() const
{
    return itemNumber;  //returns the value stored in itemNumber
}

//purpose: This function returns the value stored in quanity
//arguments: no arguements
int Inventory::getQuanity() const
{
    return quanity;     //returns the value stored in quanity
}

//purpose: This function returns the value stored in cost
//arguments: no arguements
double Inventory::getCost() const
{
    return cost;        //returns the value stored in cost
}

//purpose: This function returns the value stored in totalCost
//arguments: no arguements
double Inventory::getTotalCost() const
{
    return totalCost;   //returns the value stored in totalCost
}
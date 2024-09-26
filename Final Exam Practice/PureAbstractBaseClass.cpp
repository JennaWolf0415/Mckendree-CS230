//program: Stockbroker
//purpose: This program uses abstract base classes and pure virtual functions to calculate the commision rate for both 
//mechanical and electrical sales persons.
//name: Jenna Wolf
//id: 0347845
//date: May 4th, 2023

#include <iostream>

using namespace std;

class salesPerson
{
    protected:
        string name;    //holds the name data
        double sales;   //holds the sales data
    public:
        virtual double calcCommision() = 0;     //pure virtual function
        void setName(string);
        void setSales(double);
        string getName();
};

class mechanicalSalesPerson : public salesPerson
{
    private:
    public:
        double calcCommision();
};

class electricalSalesPeron : public salesPerson
{
    private:
    public:
        double calcCommision();
};

int main()
{
    salesPerson * ptr;      //holds the ptr data (is a pointer)
    
    //describes what this program does
    cout << "This program uses abstract base classes and pure virtual function to calculate and display the commision";
    cout << endl << "for mechanical and electrical sales persons." << endl;
    
    ptr = new mechanicalSalesPerson;    //sets ptr to a new mechanicalSalesPerson
    ptr->setName("Job");                //sets the name of ptr
    ptr->setSales(17500);               //sets the sales of ptr

    //displays the name and commision for ptr
    cout << ptr->getName() << " " << ptr->calcCommision() << endl;
    
    ptr = new electricalSalesPeron;     //sets ptr to a new electricalSalesPeron
    ptr->setName("Job");                //sets the name of ptr
    ptr->setSales(17500);               //sets the sales of ptr
    
    //display sthe name and commision of ptr
    cout << ptr->getName() << " " << ptr->calcCommision() << endl;
    
    return 0;
}

//purpose: sets the name data to the string sent over to the function
//arguments: str is what name is set to
void salesPerson::setName(string str)
{
    name = str;     //sets name to str
}

//purpose: sets the sales data to the double sent over to the function
//arguments: a is what sales is set to
void salesPerson::setSales(double a)
{
    sales = a;      //sets sales to a
}

//purpose: returns the data stored in name
//arguments: no arguments
string salesPerson::getName()
{
    return name;    //returns the name data
}

//purpose: This function caluclates the commision of a mechanical job
//arguments: no arguments
double mechanicalSalesPerson::calcCommision()
{
    double com = sales;     //holds the com data and sets it to sales
    
    //checks if com is less than 10000
    if(com < 10001)
        com = com * 0.1;    //caculates com times 10 percent
        
    //checks if com is less than 25000
    else if(com < 25001)
        com = com * 0.15;   //caculates com times 15 percent
        
    else
        com = com * 0.2;    //caculates com times 20 percent
    
    return com;     //returns the data stored in coms
}

//purpose: This function caluclates the commision of a electrical job
//arguments: no arguments
double electricalSalesPeron::calcCommision()
{
    double com = sales;     //holds the com data and sets it to sales
    
    //checks if com is less than 5000
    if(com < 5001)
        com = com * 0.12;   //caculates com times 12 percent
        
    //checks if com is less than 15000
    else if(com < 15001)
        com = com * 0.2;    //caculates com times 20 percent
    else
        com = com * 0.25;   //caculates com times 25 percent
    
    return com;     //returns the data stored in coms
}
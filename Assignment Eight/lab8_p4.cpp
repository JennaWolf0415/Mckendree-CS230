//file: lab8_p4
//description: Create a class employee that has constructors and set up three employee's
//information and display it
//author: Jenna Wolf
//id: 0347845
//date: March 22nd, 2023
#include <iostream>
#include <iomanip>

using namespace std;
class Employee
{
    private:
        string name;        //holds the name data
        int idNumber;       //holds the idNumber data
        string department;  //holds the department data
        string position;    //holds the position data
    public:
        Employee(string, int, string, string);
        Employee(string, int);
        Employee();
        void setName(string);
        void setIdNum(int);
        void setDepartment(string);
        void setPosition(string);
        string getName() const;
        int getIdNum() const;
        string getDepartment() const;
        string getPosition() const;
        void display();
};

int main()
{
    Employee one("Susan Meyers", 47899, "Vice President", "Accounting");    //holds the one data and uses the constructor to set the data
    Employee two("Mark Jones", 39119, "Programmer", "IT");                  //holds the two data and uses the constructor to set the data
    Employee three("Joy Rogers", 81774, "Engineer", "Manufactoring");       //holds the three data and uses the constructor to set the data
    
    //tells the user what the program does
    cout << "this is a test program that uses classes and has constructors. It display data set by the constructors" << endl << endl;
    
    one.display();      //calls display and sends over the one data
    two.display();      //calls display and sends over the two data
    three.display();    //calls display and sends over the three data
    return 0;
}

//purpose: This constructor uses its parameters to set the data of Employee data
//arguments: a, b, c, and d and the data that is being set
Employee::Employee(string a, int b, string c, string d)
{
    name = a;
    idNumber = b;
    position = c;
    department = d;
}

//purpose: This constructor uses its parameters to set the data of Employee data. Also sets some data to blanks
//arguments: a and b are the data that is being set
Employee::Employee(string a, int b)
{
    name = a;
    idNumber = b;
    position = " ";
    department = " ";
}
//purpose: This constructor sets all data to blanks
//arguments: no arguments
Employee::Employee()
{
    name = " ";
    department = " ";
    position = " ";
    idNumber = 0;
}

//purpose: this function sets name to a (or the data being sent over)
//arguments a is the data that name is being set to
void Employee::setName(string a)
{
    name = a;       //sets name to a
}

//purpose: this function sets idnumber to a (or the data being sent over)
//arguments a is the data that idnumber is being set to
void Employee::setIdNum(int a)
{
    idNumber = a;   //sets idNumber to a
}

//purpose: this function sets position to a (or the data being sent over)
//arguments a is the data that position is being set to
void Employee::setPosition(string a)
{
    position = a;   //sets position to a
}

//purpose: this function sets department to a (or the data being sent over)
//arguments a is the data that department is being set to
void Employee::setDepartment(string a)
{
    department = a; //sets department to a
}

//purpose: this function returns the data that is in name
//arguments: no arguments
string Employee::getName() const
{
    return name;    //returns name data
}

//purpose: this function returns the data that is in idnumber
//arguments: no arguments
int Employee::getIdNum() const
{
    return idNumber;    //returns idnumber data
}

//purpose: this function returns the data that is in position
//arguments: no arguments
string Employee::getPosition() const
{
    return position;    //returns position data
}

//purpose: this function returns the data that is in department
//arguments: no arguments
string Employee::getDepartment() const
{
    return department;  //returns department data
}

//purpose: displays the data in Employee
//arguments: no arguments
void Employee::display()
{
    //displays a line of headers and the displays the data stored in Employee
    cout << std::left << setw(20) << "Name" << setw(10) << "ID Num" << setw(20) << "Position" << setw(20) << "Department" << endl;
    cout << setw(20) << name << setw(10) << idNumber << setw(20) << position << setw(20) << department <<endl << endl;
}
//lab: lab9_p3
//purpose: This program has a class that holds work hours and days. It takes in the hours and converts them to days.
// it also has operators that can add two work hours together, find the difference between two work hours, and either
//increment or decrement work hours
//name: Jenna Wolf
//student id: 0347845
//date: April 12th, 2023
#include <iostream>

using namespace std;

class NumDays
{
    private:
        double workHours;   //holds the workHours data
        double days;        //holds the days data
    public:
        NumDays();
        void setWorkHours(double);
        void setDays(double);
        double getWorkHours();
        double getDays();
        NumDays operator+(const NumDays &);
        NumDays operator-(const NumDays &);
        NumDays operator++();
        NumDays operator--();
};

int main()
{
    double temp;        //holds the temp data
    NumDays week1;      //holds the week1 data
    NumDays week2;      //holds the week2 data
    NumDays week3;      //holds the week3 data
    
    //describes the program
    cout << "This program takes in the hours of a work week and converts it to days. It also has operators that can" << endl;
    cout << "add/subtract work hours together or increment/decrement work hours" << endl;
    
    //takes in hours for week1
    cout << "week 1 hours: ";
    cin >> temp;
    week1.setWorkHours(temp);   //sets workhours
    week1.setDays(temp);        //sets days
    
    //takes in hours for week2
    cout << "week 2 hours: ";
    cin >> temp;
    week2.setWorkHours(temp);   //sets workhours
    week2.setDays(temp);        //sets days
    
    //displays the hours and days of each week
    cout << "week 1 in hours: " << week1.getWorkHours() << "   in days: " << week1.getDays() << endl;
    cout << "week 2 in hours: " << week2.getWorkHours() << "   in days: " << week2.getDays() << endl;
    
    //adds together week 1 and week 2 hours
    week3 = week1 + week2;
    //displays the total
    cout << week3.getWorkHours() << " hours total" << endl;
    cout << week3.getDays() << " days total" << endl;
    
    //finds the difference between week 1 and week 2 hours
    if(week1.getWorkHours() > week2.getWorkHours())
        week3 = week1 - week2;
    else
        week3 = week2 - week1;
    
    //displays the difference
    cout << week3.getWorkHours() << " hours difference" << endl;
    cout << week3.getDays() << " days difference" << endl;
    
    ++week1;    //increments week 1
    
    //displays the increment
    cout << "increment week 1: " << endl;
    cout << "hours: " << week1.getWorkHours() << "     days: " << week1.getDays() << endl;
    
    --week2;    //decrements week 2
    
    //displays the decrement
    cout << "decrement week 2: " << endl;
    cout << "hours: " << week2.getWorkHours() << "     days: " << week2.getDays() << endl;
    
    return 0;
}

//purpose:  this constructor sets workHours and days to 0
//arguments: none
NumDays::NumDays()
{
    workHours = 0;
    days = 0;
}

//purpose: this function sets workHours to a
//arguments: a is what workHours is set to
void NumDays::setWorkHours(double a)
{
    workHours = a;  //sets workHours to a
}

//purpose: this function sets days to a
//arguments: a is what days is set to
void NumDays::setDays(double a)
{
    days = a / 8;   //sets days to a diveded by 8
}

//purpose: this function returns the value in workHours
//arguments: none
double NumDays::getWorkHours()
{
    return workHours;   //returns workHours
}

//purpose: this function returns the value in days
//arguments: none
double NumDays::getDays()
{
    return days;    //returns days
}

//purpose: this operator adds together the workHours sent over and finds the new total days
//arguments: val is a refrence and holds the value that is being added
NumDays NumDays::operator+(const NumDays &val)
{
    NumDays temp;   //holds the temp data
    
    temp.workHours = workHours + val.workHours; //sets temp.workHours to workHours + val.workHours
    temp.days = temp.workHours / 8;             //set temp.days to temp.workHours / 8
    return temp;    //returns the values in temp
}

//purpose: this operator finds the difference in the workHours sent over and finds the new total days
//arguments: val is a refrence and holds the value that is being subtracted
NumDays NumDays::operator-(const NumDays &val)
{
    NumDays temp;   //holds the temp data
    
    temp.workHours = workHours - val.workHours; //sets temp.workHours to workHours - val.workHours
    temp.days = temp.workHours / 8;             //set temp.days to temp.workHours / 8
    return temp;    //returns the values in temp
}

//purpose: this operator adds one to the workHours of the NumDays sent over to it. It then recaculates the days
//arguments: none
NumDays NumDays::operator++()
{
    NumDays temp;   //holds the temp data
    
    temp.workHours = workHours; //sets temp.workHours to workHours
    temp.days = workHours / 8;  //sets temp.days to workHours / 8
    ++workHours;                //adds 1 to workHours
    days = workHours / 8;       //sets days to workHours / 8

    return temp;    //returns temp
}

//purpose: this operator subtracts one to the workHours of the NumDays sent over to it. It then recaculates the days
//arguments: none
NumDays NumDays::operator--()
{
    NumDays temp;   //holds the temp data
    
    temp.workHours = workHours; //sets temp.workHours to workHours
    temp.days = workHours / 8;  //sets temp.days to workHours / 8
    --workHours;                //subtracts 1 from workHours
    days = workHours / 8;       //sets days to workHours / 8

    return temp;    //returns temp
}

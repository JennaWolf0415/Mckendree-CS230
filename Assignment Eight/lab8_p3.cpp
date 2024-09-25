//file: lab8_p3
//description: This program will take a date entered by the user (the day, month, and year in number form) and display
//the date three ways: month/day/year in number form, month/day/year in word form, and day/month/year in word form.
//author: Jenna Wolf
//id: 0347845
//date: March 22nd, 2023#include <iostream>
#include <iostream>

using namespace std;

class Date
{
    private:
        int month;      //holds the month data
        int day;        //holds the day data
        int year;       //holds the year data
    public:
        void setM (int);
        void setD (int);
        void setY (int);
        int getM () const;
        int getD () const;
        int getY () const;
        void numPrint () const;
        void monPrint (string []) const;
        void dayPrint (string []) const;
};

int main()
{
    Date date;      //hold the date data
    int m;          //holds the m data
    int d;          //holds the d data
    int y;          //holds the y data
    //holds the month data in an array of 12 and sets each member of the array
    string months [12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                        "October", "November", "December"};
                      
    //tells the user what the program does  
    cout << "This program will take a date entered by the user (the day, month, and year in number form) and display" << endl;
    cout << "the date three ways: month/day/year in number form, month/day/year in word form, and day/month/year in word form.";
    cout << endl << endl;
    
    //takes in the number of months and makes sure its between 1 and 12
    cout << "enter the number for the month: ";
    cin >> m;
    while(m < 1 || m > 12)
    {
        cout << "please enter a proper number for month: ";
        cin >> m;
    }
    date.setM(m);   //calls the setM function through date
    
    //takes in the number of days and makes sure its between 1 and 31
    cout << "enter the number for the day: ";
    cin >> d;
    while(d < 1 || d > 31)
    {
        cout << "please enter a proper number for day: ";
        cin >> d;
    }
    date.setD(d);   //cals the setD function through data
    
    //takes in the number of years and makes sure its higher that 0
    cout << "enter the number for the year: ";
    cin >> y;
    while(y < 0)
    {
        cout << "please enter a proper number for year: ";
        cin >> y;
    }
    date.setY(y);   //calls the setY function through date
    
    date.numPrint();        //calls the numPrint function through date
    date.monPrint(months);  //calls the monPrint function through date
    date.dayPrint(months);  //calls the dayPrint function through date
    
    return 0;
}

//purpose: sets month to the value that is sent over
//arguments: a sent over because it is what month is being set to
void Date::setM(int a)
{
    month = a;  //sets month to a
}

//purpose: sets day to the value that is sent over
//arguments: a sent over because it is what day is being set to
void Date::setD(int a)
{
    day = a;    //sets day to a
}

//purpose: sets year to the value that is sent over
//arguments: a sent over because it is what year is being set to
void Date::setY(int a)
{
    year = a;   //sets year to a
}

//purpose: returns the value that is stored in month
//arguments: no arguments
int Date::getM() const
{
    return month;   //returns the value in month
}

//purpose: returns the value that is stored in day
//arguments: no arguments
int Date::getD() const
{
    return day;     //returns the value in day
}

//purpose: returns the value that is stored in year
//arguments: no arguments
int Date::getY() const
{
    return year;    //returns the value in year
}

//purpose: daisplay the values of month, day, and year in the order month/day/year in number form
//arguments: no arguments
void Date::numPrint() const
{
    //displays month/day/year (numbers for all three)
    cout << month << "/" << day << "/" << year << endl; 
}

//purpose: daisplay the values of month, day, and year in the order month/day/year in word form
//arguments: month is used to match up with what month is set to and is displayed (displays month's
//value in words instead of numbers)
void Date::monPrint(string mon[]) const
{
    //checks each value in the array and displays the one that matches month value
    for(int i = 0; i < 12; i++)
    {
        if (i == month - 1)
            cout << mon[i];
    }
    //displays day, year (numbers)
    cout << " " << day << ", " << year << endl;
}

//purpose: daisplay the values of month, day, and year in the order day/month/year in word form
//arguments: month is used to match up with what month is set to and is displayed (displays month's
//value in words instead of numbers)
void Date::dayPrint(string mon[]) const
{
    //displays day (number)
    cout << day << " ";
    
    //checks each value in the array and displays the one that matches month value
    for(int i = 0; i < 12; i++)
    {
        if (i == month - 1)
            cout << mon[i];
    }
    //dispalys year (number)
    cout << " " << year << endl;
}
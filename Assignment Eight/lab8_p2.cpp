//file: lab8_p2
//description: This program takes in how many students and how many tests there are from the user. It then takes in
//the name, student id, and grade for each test for each of the students. It then finds the average and course grade
//for each student. Finally, it displays the name, student if, average test score, and course grade for each student.
//author: Jenna Wolf
//id: 0347845
//date: March 22nd, 2023
#include <iostream>
#include <iomanip>

using namespace std;
struct student
{
    string name;        //holds the name data
    int idnum;          //holds the idnum data
    double * tests;     //holds the tests data (is a pointer)
    double average;     //holds the average data
    char grade;         //holds the grade data
};

void getInfo(student *, int, int);
void getAverage(student *, int, int);
void getCourseGrade(student *, int, int);
void displayInfo(student *, int, int);
int main()
{
    student * ptr;      //holds the ptr data (is a pointer)
    int stu;            //holds the stu data
    int testnum;        //holds the testnum data
    
    //tells the user what the program does
    cout << "description: This program takes in how many students and how many tests there are from the user. It then takes in";
    cout << endl << "the name, student id, and grade for each test for each of the students. It then finds the average and course grade";
    cout << endl << "for each student. Finally, it displays the name, student if, average test score, and course grade for each student.";
    cout << endl << endl;

    //takes in how many students there are and makes sure it is positive
    cout << "how many students are there? ";
    cin >> stu;
    while (stu < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> stu;
    }

    //takes in how many tests there are and makes sure it is positive
    cout << "how many tests are there? ";
    cin >> testnum;
    while (testnum < 0)
    {
        cout << "please enter a number above 0! ";
        cin >> testnum;
    }
    
    //set ptr to a dynamically allocated array of stu size
    ptr = new student[stu];
    
    //sets each test in ptr to a dynamically allocated array of testnum size
    for(int i = 0; i < testnum; i++)
        ptr[i].tests = new double[testnum];
    
    getInfo(ptr, stu, testnum);         //calls the getInfo function
    getAverage(ptr, stu, testnum);      //calls the getAverage function
    getCourseGrade(ptr, stu, testnum);  //calls the getCourseGrade function
    displayInfo(ptr, stu, testnum);     //calls the displayInfo function
    return 0;
}

//purpose: this function gets the info for each student (there name, id number, and test grades)
//argument: ptr is sent over because it is what holds the information entered. stu and testnum
//are sent over because they are used as checks for size (makes sure you don't go over the
//number of students and tests)
void getInfo(student * ptr, int stu, int testnum)
{
    //for loop that goes through each student in ptr
    for(int i = 0; i < stu; i++)
    {
        //tells the user what student they are on
        cout << "please enter the information for student " << i + 1 << ": " << endl;
        cin.ignore();   //clears the input
        
        //gets the name from the user
        cout << "name: ";
        getline(cin, ptr[i].name);
        
        //gets the id from the user and makes sure its positive
        cout << "student ID: ";
        cin >> ptr[i].idnum;
        while(ptr[i].idnum < 0)
        {
            cout << "please enter a number above 0! ";
            cin >> ptr[i].idnum;
        }
        
        //goes through each test for each student
        for(int j = 0; j < testnum; j++)
        {
            //gets the test score and makes sure it is between 0 and 100
            cout << "test " << j + 1 << ": ";
            cin >> ptr[i].tests[j];
            while(ptr[i].tests[j] < 0 || ptr[i].tests[j] > 100)
            {
                cout << "please enter a number between 0 and 100! ";
                cin >> ptr[i].tests[j];
            }
        }
    }
}

//purpose: get the average of all test scores for each student
//argument: ptr has the data being used and is what is being inputed to. stu and testnum
//are sent over because they are used as checks for size (makes sure you don't go over the
//number of students and tests)
void getAverage(student * ptr, int stu, int testnum)
{
    double avg = 0; //holds the avg data and sets it to 0
    
    //goes through each student in pt
    for(int i = 0; i < stu; i++)
    {
        //goes trough each test for each student. adds each test score to avg
        for(int j = 0; j < testnum; j++)
            avg += ptr[i].tests[j];
        
        avg = avg / testnum;    //divides avg by the number of tests
        ptr[i].average = avg;   //sets current students average to avg
        avg = 0;                //resets avg to 0
    }
}

//purpose: this function checks the average of each student and assigns them a overall course grade
//argument: ptr has the data being used and is what is being inputed to. stu and testnum
//are sent over because they are used as checks for size (makes sure you don't go over the
//number of students and tests)
void getCourseGrade(student * ptr, int stu, int testnum)
{
    //goes trough each student in ptr
    for(int i = 0; i < stu; i++)
    {
        //checks to see what the average is and assigns a letter grade based on what it is
        if(ptr[i].average > 90)
            ptr[i].grade = 'A';
        else if(ptr[i].average > 80)
            ptr[i].grade = 'B';
        else if(ptr[i].average > 70)
            ptr[i].grade = 'C';
        else if(ptr[i].average > 60)
            ptr[i].grade = 'D';
        else
            ptr[i].grade = 'F';
    }
}

//purpose: displays the information of each student (there name, id, average test score, and course grade)
//argument: ptr has the information that is being displayed. stu and testnum
//are sent over because they are used as checks for size (makes sure you don't go over the
//number of students and tests)
void displayInfo(student * ptr, int stu, int testnum)
{
    cout << fixed << showpoint << setprecision(2);  //makes sure each number is only to the 2 decimal point
    
    //goes through each student in ptr
    for(int i = 0; i < stu; i++)
    {
        //displays lines and the name, id, average test score, and coures grade for each student
        cout << "----------------------------------------" << endl;
        cout << std::left << setw(25) << "student name: " << ptr[i].name << endl;
        cout << setw(25) << "student ID: " << ptr[i].idnum << endl;
        cout << setw(25) << "average test score: " << ptr[i].average << endl;
        cout << setw(25) << "course grade: " << ptr[i].grade << endl;
        cout << "----------------------------------------" << endl;
    }
}
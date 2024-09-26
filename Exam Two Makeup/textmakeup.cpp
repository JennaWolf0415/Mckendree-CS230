//lab:testmakeup
//purpose:This is a makeup for the test. It takes in data from a file and lets the user search for a last name in the data,
//sort the data by salary and output it to a file, or display all the data
//name:Jenna Wolf
//id:0347845
//date:April 8th, 2023
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Employee
{
    string SSN;     //holds the SSN data
    string fname;   //holds the fname data
    string lname;   //holds the lname data
    double salary;  //holds the salary data
    char gender;    //holds the gender data
    double inc;     //holds the inc data
};

int getSize();
void readFile(Employee *, int);
void search(Employee *, int);
void sort(Employee *, int);
void swap(Employee &, Employee &);
void outputToFile(Employee *, int);
void display(Employee *, int);
int main()
{
    int size;       //holds the size data
    int answer;     //holds the answer data
    Employee * ptr; //holds the ptr data (is a pointer)

    //displays what the program does
    cout << "This program takes in employee data from a file. The user can then either search for an employee's" << endl;
    cout << "last name, sort the data by salary and output it to a file, or display all the data" << endl << endl;
    
    size = getSize();           //calls the getSize function and sets size to it
    ptr = new Employee[size];   //sets ptr to a dynamically allocated array of size
    readFile(ptr, size);        //calls the readFile function

    //loop that keeps going until user enters 4
    do{
        //displays a menu of the users options and takes in their answer
        cout << "select one option below" << endl;
        cout << "1.Search for an employee by their last name" << endl;
        cout << "2.Sort by salary and output to file" << endl;
        cout << "3.Display all information" << endl;
        cout << "4.Quit" << endl;
        cin >> answer;
        
        //makes sure a proper answer is entered
        while(answer > 4 || answer < 0)
        {
            cout << "please enter a proper answer" << endl;
            cin >> answer;
        }
        
        //calls a certain function based on what the user answered
        if(answer == 1)
            search(ptr, size);
        else if (answer == 2)
            sort(ptr, size);
        else if (answer == 3)
            display(ptr, size);
        
        
    }while(answer != 4);
    
    return 0;
}

//purpose: this function gets the size of the text.txt file and returns it
//argmuents: no arguments
int getSize()
{
    int size;       //holds the size data
    string temp;    //holds the temp data
    
    //opens the infile text.txt
    ifstream infile;
    infile.open("text.txt");
    
    //makes sure the file opens properly
    if(!infile)
    {
        cout << "FILE FAILED TO OPEN!" << endl;
        exit(EXIT_FAILURE);
    }
    
    //adds one to size for every line in the file
    while(getline(infile, temp))
        size += 1;
        
   
    infile.close(); //closes the file
    
    return size;    //returnes size
}

//purpose: This file reads in the data from the file and sets it to the elements in ptr
//argmuents: ptr is what the data is being set to, size is the size of ptr and is used for checks
void readFile(Employee * ptr, int size)
{
    string temp;            //holds the temp data
    int pos;                //holds the pos data
    int pos2;               //holds the pos2 data
    
    //opens the infile text.txt
    ifstream infile;        
    infile.open("text.txt");
    
    //makes sure file opens properly
    if(!infile)
    {
        cout << "FILE FAILED TO OPEN!" << endl;
        exit(EXIT_FAILURE);
    }
    
    //loop that goes through each line in the file 
    for(int i = 0; i < size; i++)
    {
        //sets the SSN number to before the comma
        getline(infile, temp);
        pos = temp.find(",", 0);
        ptr[i].SSN = temp.substr(0, pos);
        
        //sets the first name (before the space) and last name (after the space) to before the comma
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        pos2 = temp.find(" ", 1);
        ptr[i].fname = temp.substr(0, pos2);
        ptr[i].lname = temp.substr(pos2 + 1, pos - pos2 - 1);
        
        //sets the salary to before the comma
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        ptr[i].salary = stod(temp.substr(0, pos));
        
        //sets the gender to before the comma
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        ptr[i].gender = temp[pos - 1];
        
        //sets the inc to after the comma
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        ptr[i].inc = stod(temp.substr(0, pos));
    }
    
    infile.close(); //closes the file
}

//purpose: This function searches for an employee by their last name. If that last name exists, all data is outputted.
//if not, it tells the user that their is no employee with that last name
//argmuents: ptr is what is being searched, size is the size of ptr and is used for checks
void search(Employee * ptr, int size)
{
    string name;        //holds the name data
    int num = 0;        //holds the num data and is set to 0
    bool found = false; //holds the found data and is set to false
    
    //gets the name from the user
    cout << "please enter the name your searching for: ";
    cin >> name;
    
    //loop repeats while num is less than size
    while(num < size)
    {
        //if the ptr lname matches the name entered, then all data is displayed and found is set to true
        if(ptr[num].lname == name)
        {
            cout << "found: " << endl;
            cout << "XXXXX" << ptr[num].SSN[5] << ptr[num].SSN[6] << ptr[num].SSN[7] << ptr[num].SSN[8] << " ";
            cout << setw(10) << ptr[num].fname << " " << setw(10) << ptr[num].lname << " " << setw(12) << ptr[num].salary/12;
            cout << " " << setw(7) << ptr[num].gender << " " << (ptr[num].inc / 100) * ptr[num].salary << endl;
            found = true;
        }
        
        num++;  //adds 1 to num
    }
    
    //if found is not true, than message is displayed
    if(!found)
            cout << "that last name is not in our data base!" << endl;
}

//purpose:  this function sorts the data in ptr by salary and then calls the outputToFile function
//argmuents: ptr is what is being sorted, size is the size of ptr and is used for checks
void sort(Employee * ptr, int size)
{
    int index;      //holds the index data
    int variable;   //holds the variable data
    
    //for loop that repeats until i is bigger than size
    for(int i = 0; i < size; i++)
    {
        //sets index to i and variable to ptr salary
        index = i;
        variable = ptr[i].salary;
        
        //for loop that repeats until f is bigger than size
        for(int f = i + 1; f < size; f++)
        {
            //if ptr salary is bigger than vairable, than index is set to f and variable is set to ptr salary
            if(ptr[f].salary > variable)
            {
                index = f;
                variable = ptr[f].salary;
            }
        }
        swap(ptr[index], ptr[i]);   //calls the swap function
    }
    
    outputToFile(ptr, size);    //calls the outputToFile function
}

//purpose: This function swaps the two values sent to it
//argmuents: a and b are swaped
void swap(Employee &a, Employee &b)
{
    Employee temp = a;  //holds the temp data and sets to a 
    a = b;              //a is set to b
    b = temp;           //b is set to temp
}

//purpose: This function outputs the data in ptr to a file
//argmuents: ptr is the data being outputted, size is the size of ptr and is used for checks
void outputToFile(Employee * ptr, int size)
{
    //opens the outfile sortedEmp.txt
    ofstream outfile;
    outfile.open("sortedEmp.txt");
    
    //makes sure the file opens
    if(!outfile)
    {
        cout << "FILE FAILED TO OPEN!" << endl;
        exit(EXIT_FAILURE);
    }
    
    //for loop that repeats until i is bigger than size
    for(int i = 0; i < size; i++)
    {
        //outputs all the data in ptr to a file with commas and spaces
        outfile << ptr[i].SSN << ", " << ptr[i].fname << " " << ptr[i].lname << ", " << ptr[i].salary;
        outfile << ", " << ptr[i].gender << ", " << ptr[i].inc << endl;
    }
    
    outfile.close();    //closes the file
}

//purpose: This function displays the data in ptr
//argmuents: ptr is the data being displayed, size is the size of ptr and is used for checks
void display(Employee * ptr, int size)
{
    //displays a header with all catagories in ptr
    cout << std::left << setw(11) << "SSN" << setw(21) << "name" << setw(13) << "salary" << setw(8) << "gender" << "increase" << endl;
    
    //for loop that repeats until i is bigger than size
    for(int i = 0; i < size; i++)
    {
        //displays the data in ptr for each catagory
        cout << "XXXXX" << ptr[i].SSN[5] << ptr[i].SSN[6] << ptr[i].SSN[7] << ptr[i].SSN[8] << " ";
        cout << setw(10) << ptr[i].fname << " " << setw(10) << ptr[i].lname << " " << setw(12) << ptr[i].salary/12;
        cout << " " << setw(7) << ptr[i].gender << " " << (ptr[i].inc / 100) * ptr[i].salary << endl;
    }
}
//lab: lab9_p2
//purpose: This program takes in a number between 0 and 9999 and displays the number in word form
//name: Jenna Wolf
//student id: 0347845
//date: April 10th, 2023

#include <iostream>
#include <string>

using namespace std;

class Numbers
{
    private:
        int number;     //holds the number data
    public:
        Numbers();
        Numbers(int);
        void setNumber(int);
        int getNumber();
        void print(Numbers);
        static string lessThan20[20];
        static string hundred;
        static string thousand;
        static string tens[8];
};


int main()
{
    int answer;     //holds the answer data
    Numbers num;    //holds the num data
    
    //describes what the program does
    cout << "this program takes any number between 0 and 9999 and turns it into word form!" << endl;
    
    //takes in number from user
    cout << "Please enter a number between 0 and 9999: ";
    cin >> answer;
    
    //makes sure number is between 0 and 9999
    while(answer > 9999 || answer < 0)
    {
        cout << "PLEASE ENTER A PROPER ANSWER: ";
        cin.ignore();
        cin >> answer;
    }
    
    num.setNumber(answer);  //sets number to answer
    num.print(num);         //calls the print function
    
    return 0;
}

//static array that holds the data it is set to
string Numbers::lessThan20[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                                "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                                "seventeen", "eighteen", "nineteen"};
string Numbers::hundred = "hundred";    //static string that holds the hundred data
string Numbers::thousand = "thousand";  //static string that holds the thousand data
//static array that holds the data it is set to
string Numbers::tens[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

//purpose: constructor that sets number to 0;
//arguments: no arguments
Numbers::Numbers()
{
    number = 0; //sets number to 0
}

//purpose: function that sets number to the value that is sent over to it
//arguments: a is the value numbers is being set to
void Numbers::setNumber(int a)
{
    number = a; //sets number to a
}

//purpose: returns the value stored in number
//arguments: no arguments
int Numbers::getNumber()
{
    return number;  //returns number
}

//purpose: this function display that number value in string form after doing comparisons to see what it would
//be in string form
//arguments: num is the number being converted
void Numbers::print(Numbers num)
{
    string line;        //holds the line data
    int currentNum;     //holds the currentNum data
    int length;         //holds the length data
    bool teens = false; //holds the teens data and is set to false
    
    line = to_string(num.number);   //converts the number into a string
    length = line.length();         //sets length to the length of the line string
    
    //if length is 4
    if(length == 4)
    {
        currentNum = line[0] - 48;  //sets current number to the first number in the string
        
        //outputs the number in the array and thousand
        cout << lessThan20[currentNum] << " " << thousand << " ";
    }
    
    //if length is higher than 3
    if((length > 2))
    {
        currentNum = line[length - 3] - 48; //sets currentNum to the hundred spot of the line
        //makes sure currentNum is not 0
        if(currentNum != 0)
        {
            //outputs the currentNum in the array and hundred
            cout << lessThan20[currentNum] << " " << hundred << " " ;
        }
    }
    
    //if length is higher than 1
    if(length > 1)
    {
        currentNum = line[length - 2] - 48; //sets currentNum to the tens spot of the line
        
        //if currentNum is above 1
        if(currentNum > 1)
        {
            //outputs the currentNum of the tens array
            cout << tens[currentNum - 2] << " ";
            
        }
        //if currentNum is 1
        if (currentNum == 1)
        {
            currentNum = (line[length - 1] - 48) + 10;  //sets current num to the 1 spot plus 10
            
            //outputs the currentNum of the lessThan20 array
            cout << lessThan20[currentNum] << " ";
            teens = true;   //sets teens to true
        }
    }

    //if teens is not true
    if(!teens)
    {
        currentNum = (line[length - 1] - 48);   //sets currentNum to the ones spot
        
        //outputs the currentNum of the lessThan20 array
        cout << lessThan20[currentNum];
    }
}
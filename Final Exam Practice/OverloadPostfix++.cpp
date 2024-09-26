//program: Overload ++ Operator Postfix
//purpose: This program overloads the postfix ++ operator so that it incremants the rabbit's speed class by 10
//name: Jenna Wolf
//id: 0347845
//date: May 3rd, 2023

#include <iostream>

using namespace std;

class Rabbit
{
    private:
        string name;    //holds the name data
        int speed;      //holds the speed data
    public:
        Rabbit(string, int);
        string getName();
        int getSpeed();
        int operator++(int);
};

void Accelerate(Rabbit &);
int main()
{
    Rabbit r("Ruby", 0);    //holds the r data and sets its name and speed
    
    //tells the user what to program does
    cout << "this program overloads the postfix ++ operator and increments a rabbits speed by 10 each time it is called."
    cout << endl << "This is demestrated with the rabbit named Ruby" << endl;
    
    //displays the name and speed of Rabbit r
    cout << r.getName() << " " << r.getSpeed() << endl;
    
    //for loop that iterates until i is bigger than 10
    for(int i = 0; i < 10; i++)
        Accelerate(r);  //calls the Accelerate function
    
    //displays the name and speed of Rabbit r    
    cout << r.getName() << " " << r.getSpeed();
    return 0;
}

//purpose: constructor that sets the name and speed of a rabbit
//arguments str and a are what name and speed are set to
Rabbit::Rabbit(string str, int a)
{
    name = str;     //sets name to str
    speed = a;      //sets speed to a
}

//purpose: returns the value stored in name
//arguments: no arguments
string Rabbit::getName()
{
    return name;    //returns the name data
}

//purpose: returns the value stored in speed
//arguments: no arguments
int Rabbit::getSpeed()
{
    return speed;   //returns the speed data
}

//purpose: overloads the ++ operator so that it adds 10 to speed each time its called
//arguments: int allows the operator to be a postfix operator
int Rabbit::operator++(int)
{
    speed = speed + 10; //sets speed to speed plus 10
    return speed;       //rturns the speed data
}

//purpose: this function calls the ++ operator for the Rabbit value sent over
//arguments: r is the value that calls the ++ operator
void Accelerate(Rabbit &r)
{
    r++;    //calls the ++ operator;
}
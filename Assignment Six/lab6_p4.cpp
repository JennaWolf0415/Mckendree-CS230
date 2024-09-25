//File: Lab6_p4
//purpose: This program takes in a password(string) from the user. It then checks that password to make sure
//it has 10 characters, has an uppercase, lowercase, and special character, and has at least 2 digits.
//if it doesnt, then it tells the user whats wrong and makes them enter a new password. If it is fine, then it says so.
//author: Jenna Wolf
//id: 0347845
//date: March 1st, 2023

#include <iostream>
#include <cctype>

using namespace std;
bool lCheck(string);
bool cCheck(string);
bool dCheck(string);
int main()
{
    string password;    //holds the password data
    bool length;        //holds the length data
    bool chars;         //holds the chars data
    bool digits;        //holds the digits data
    
    //explains what the program does
    cout << "This program takes in your password and tells you if it can be used of not! Your password must be 10" << endl;
    cout << "characters long, have an uppercase, lowercase, and a special character, and have at least 2 digits!" << endl;
    cout << "this program keeps going until you enter a password that fits all the requirements" << endl;
    
    //While loop that reapeats until a proper password is entered
    do
    {
        //gets a password from the user
        cout << "please enter a password: ";
        getline(cin, password);
        
        //sets all bools to true
        length = true;
        chars = true;
        digits = true;
        
        //calls the functions to check for password requirements
        length = lCheck(password);
        chars = cCheck(password);
        digits = dCheck(password);
        
        //tells the user what is wrong with their password if anything is wrong
        if(length)
            cout << "Your length is too short! You need at least 10 characters!" << endl;
        if(chars)
            cout << "You need at least one uppercase, one lowercase, and one special character!" << endl;
        if(digits)
            cout << "You need at least 2 digits!" << endl;
        
        //creates a space
        cout << endl;
        
    }while(length || chars || digits);
    //checks to see if requirements were met. If not, loop repeats
    
    //lets the user know their password is good
    cout << "Your password is all good!";

    return 0;
}

//purpose: checks to see if password is at least 10 characters long
//arguments: password is passed over because it is what is checked
bool lCheck(string password)
{
    //checks to see if string length is above 9. If it is, return false, if not, return true
    if(password.length() > 9)
        return false;
    else
        return true;
}

//purpose: checks to see if the string has a lowercase, uppercase, and special
//arguments: password is passed over because it is what is checked
bool cCheck(string password)
{
    bool low = false;   //holds the low data
    bool high = false;  //holds the high data
    bool spec = false;  //holds the spec data
    
    //loop that goes through each character and checks to see if they are lower, upper, or alnum.
    for(int i = 0; i < password.length(); i++)
    {
        if(islower(password[i]))
            low = true;
        else if(isupper(password[i]))
            high = true;
        else if(!isalnum(password[i]))
            spec = true;
    }
    
    //checks to see if low, high, and spec are set to true. if they are, return false, if not, return true
    if(low && high && spec)
        return false;
    else
        return true;
}

//purpose: checks to see if the password has at least 2 digits
//arguments: password is passed over because it is what is checked
bool dCheck(string password)
{
    int digits = 0;     //holds the digit data
    
    //checks to see if characters are digits. If they are, add 1 to digits.
    for(int i = 0; i < password.length(); i++)
    {
        if(isdigit(password[i]))
            digits += 1;
    }
    
    //checks to see if digits is 2 or higher. If it is, return false, if not, return true 
    if(digits >= 2)
        return false;
    else
        return true;
}
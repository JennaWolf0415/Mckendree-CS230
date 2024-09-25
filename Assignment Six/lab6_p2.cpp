//File: Lab6_p2
//purpose: This program takes a string and changes it to "crazy latin" (uppercase to lower, lower to upper, and each
//word ends with ey)
//author: Jenna Wolf
//id: 0347845
//date: March 1st, 2023

#include <iostream>
#include <cctype>

using namespace std;
string convert(string);
string add(string);
int main()
{
    string sen;     //holds the sen data
    
    //explains what the program does:
    cout << "this program will take any sentance you enter and change it to crazy latin! (uppercase to lower, " << endl;
    cout << "lowercase to upper, and each word ends with EY!" << endl << endl;
    
    //takes in a sentance from the user
    cout << "Enter a sentance and I will change it to crazy latin!" << endl;
    getline(cin, sen);

    //calls the convert function and displays what it returns
    cout << convert(sen);
    
    return 0;
}

//purpose: takes a string and converts its uppercase to lower, lowercase to upper, and adds ey to the end of each word
//argument: sen is taken in as it is what is being modified
string convert(string sen)
{
    string sent;    //holds the sent data
    
    //goes through each letter of a string. If a character is lower, it is changed to upper.
    //if it is upper, change to lower. If is is a space, add EY.
    for(int i = 0; i < sen.length(); i++)
    {
        if(islower(sen[i]))
            sent += (char)toupper(sen[i]);
        else if(isupper(sen[i]))
            sent += (char)tolower(sen[i]);
        else if(isspace(sen[i]))
            sent += "EY ";
        
    }
    
    //adds EY to the end of the last word
    sent += "EY";
    
    //sends sent string back
    return sent;
}
//assignment: lab7_p2
//purpose: This program takes in a line from the user that has digits, letters, spaces, and punctuation. it
//then coverts said line to morse code.
//name: Jenna Wolf
//student ID: 0347845
//date: March 14th, 2023
#include <iostream>
#include <cctype>

using namespace std;

string morseCode(string, char [], string []);
int main()
{   
    string line;    //holds the line data
    //holds the letter data and sets each value of the array
    char letters[40] = {' ', ',', '.', '?', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
                        'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    //holds the morse data and sets each value of the array
    string morse[40] = {" ", "--..--", ".-.-.-", "..--..", "-----", ".----", "..---", "...--", "....-",
                        ".....", "-....", "--...", "---..", "----.", ".-", "-...", "-.-.", "-..", ".",
                        "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
                        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    //displays what the progam does
    cout << "this program will take in a string the user eneters and turn it into morse code!" << endl;
    
    //gets a string input from the user
    cout << "Enter a string of numbers, letters, spaces, and punctuation (, . ?): ";
    getline(cin, line);
    
    //checks the make sure each element of the string is a number, letter, space, or punctuation
    for(int i = 0; i < line.length(); i++)
    {
        //if the current element is not a number, letter, space, or punctuation, then it gets a new line
        //from the user and sets i to -1 
        if(!isalnum(line[i]) && !isspace(line[i]) && line[i] != '.' && line[i] != '?')
        {
            cout << "please enter a proper line!: ";
            getline(cin, line);
            i = -1;
        }
    }
    
    //sets each lowercase letter in the array to an uppercase letter
    for(int i = 0; i < line.length(); i++)
    {
        if(islower(line[i]))
            line[i] = toupper(line[i]);
    }
    
    //calls the morseCode function and displays the outcome
    cout << "your string in morse code is: " << endl << morseCode(line, letters, morse) << endl;

    return 0;
}

//purpose: convert the line sent to the function into a line of morse code using the l and m arrays. then
//return the new line.
//arguments: line is what is being checked/coverted. l is what is being checked with line. m is what is
//holding the morse code and being added to the new line
string morseCode(string line, char l[], string m[])
{
    string nline;   //holds the nline data
    
    //steps through each variable of the string
    for(int i = 0; i < line.length(); i++)
    {
        //steps through each element of the array
        for(int j = 0; j < 40; j++)
        {
            //if the current variable of the line equals the current element of the l array, then
            //nline adds the corresponding m array element
            if(line[i] == l[j])
                nline += m[j];
        }
    }
    
    //returns nline
    return nline;
}
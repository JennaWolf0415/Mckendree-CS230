//File: Lab6_p5
//purpose: Take in data from a file and check each character to see if it is a lowercase, uppercase, digits, or spaces.
//It then outputs the results
//author: Jenna Wolf
//id: 0347845
//date: March 1st, 2023

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;
string readInFile(string);
void amounts(string, int *, int *, int *, int *);
int main()
{
    string text;    //holds the text data
    int low;        //holds the low data
    int high;       //holds the high data
    int digs;       //holds the digs data
    int words;      //holds the words data
    int * ptr1;     //holds the ptr1 data (is a pointer)
    int * ptr2;     //holds the ptr2 data (is a pointer)
    int * ptr3;     //holds the ptr3 data (is a pointer)
    int * ptr4;     //holds the ptr4 data (is a pointer)
    
    ptr1 = &low;    //makes ptr1 point to the address of low
    ptr2 = &high;   //makes ptr2 point to the address of high
    ptr3 = &digs;   //makes ptr3 point to the address of digs
    ptr4 = &words;  //makes ptr4 point to the address of words
    
    //Tells the user what this program does
    cout << "This program takes in text from a file. It then tells the user how manny lowercase letters, uppercase letters,";
    cout << endl << "digits, and words said file has" << endl;
    
    //calls the readInFile function and assigns it to text
    text = readInFile(text);
    
    //calls the amount function
    amounts(text, ptr1, ptr2, ptr3, ptr4);
    
    //outputs the amount of lowercase, uppercase, digits, and words
    cout << endl;
    cout << "The amount of lowercase: " << *ptr1 << endl;
    cout << "The amount of uppercase: " << *ptr2 << endl;
    cout << "The amount of digits: " << *ptr3 << endl;
    cout << "The amount of words: " << *ptr4 << endl;
    
    return 0;
}
//purpose: Read in info from a file to a string varaible. Goes letter by letter.
//arguments: string in is sent over because it is what holds the string data.
string readInFile(string in)
{
    char c;                     //holds the c data
    ifstream infile;            //holds the infile data
    infile.open("text.txt");    //opens the file
    
    //Makes sure file is opened correctly. Error is sent out if it is not
    if(!infile)
    {
        cout << "File failed to open, try again" << endl;
        exit(EXIT_FAILURE);
    }

    //takes in info from file character by character and adds it to the string
    while(infile.get(c))
    {
        in += c;
    }

    //closes the file
    infile.close();
    
    //returns the string
    return in;
}

//purpose: check each character of the string to see weather they are a lowercase, uppercase, digit, or space. Add them
//together and returns them.
//arguments: text is sent because it is what is being checked. the pointers are sent because they point to the address in
//main that hold the lower, upper, digit, and space data.
void amounts(string text, int * ptr1, int * ptr2, int * ptr3, int * ptr4)
{
    int length = text.length(); //holds the length data and sets it to text length
    
    //goes through each character or the string text. Checks to see if it is lower, upper, digit, or space, and
    //adds one to the data type that it is.
    for(int i = 0; i < length; i++)
    {
        if(islower(text[i]))
            *ptr1 += 1;
        else if(isupper(text[i]))
            *ptr2 += 1;
        else if(isdigit(text[i]))
            *ptr3 += 1;
        else if(isspace(text[i]))
            *ptr4 += 1;
    }
    
    //adds one more to space (so words match)
    *ptr4 += 1;
}
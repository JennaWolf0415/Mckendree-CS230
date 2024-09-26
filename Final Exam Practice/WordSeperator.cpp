//program: Word Seperator
//purpose: Seperates a string of alphabetical characters by finding the capitalized ones and adding a space between them
//name: Jenna Wolf
//id: 0347845
//date: May 2nd, 2023

#include <iostream>

using namespace std;

int main()
{
    string sentance;    //holds the sentance data
    int length;         //holds the length data
    int count = 0;      //holds the count data and sets it to 0
    char * completed;   //holds the completed data (is a pointer);
    
    //tells the user what the program does
    cout << "This program will take a sentance of alphabetical characters you enter without spaces and turn it";
    cout << endl << "into a sentance with spaces and no capitalization besides the first letter" << endl;
    
    //gets the sentance from the user
    cout << "Please enter a sentance with only letters and each word capitalized: " << endl;
    getline(cin, sentance);
    
    //for loop that iterates until i is equal to the length of sentance
    for(int i = 0; i < sentance.length(); i++)
    {
        //makes sure the character in sentance is a alphabetical character
        if(!isalpha(sentance[i]))
        {
            //gets a new sentance from the user
            cout << "Please enter a proper sentance! " << endl;
            getline(cin, sentance);
            i = -1;     //sets i to -1
        }
    }
    
    //for loop that iterates until i is bigger than the length of sentance
    for(int i = 0; i < sentance.length(); i++)
    {
        //sees is the current character in sentance is uppercase
        if(isupper(sentance[i]))
            length++;   //adds one to length
    }
    
    //dynamically allocates completed to a new char array of size sentance length plus length
    completed = new char[sentance.length() + length];
    
    //for loop that iterates until i is bigger than the length of sentance
    for(int i = 0; i < sentance.length(); i++)
    {
        //checks to see if i is 0
        if(i == 0)
            completed[i] = sentance[i]; //sets completed[i] to sentance[i] (first letter of sentance)
            
        //checks to see if the current character of sentance is uppercase
        else if(isupper(sentance[i]))
        {
            completed[i + count] = ' ';                     //sets completed[i + count] to a space
            count++;                                        //adds one to count
            completed[i + count] = tolower(sentance[i]);    //sets completed[i + count] to a lowercase sentace[i]
        }
        else
            completed[i + count] = sentance[i];             //sets completed[i + count] to sentance[i]
    }
    
    //for loop that iterates until i is bigger than the length of sentance
    for(int i = 0; i < sentance.length() + length; i++)
        cout << completed[i];       //displays the current character of completed
        
    return 0;
}

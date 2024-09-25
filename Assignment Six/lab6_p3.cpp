//File: Lab6_p3
//purpose: This program recreates the stoi function. It changes a string to an int
//author: Jenna Wolf
//id: 0347845
//date: March 1st, 2023
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;
int stringToInt(int, int, string);
int main()
{
    string str;     //holds the str data
    string str2;    //holds the str2 data
    int nums;       //holds the nums data
    int length;     //holds the length data
    bool alpha;     //holds the alpha data
    
    //explains what the program does
    cout << "this program is a replication of the stoi function. It transfers an string to an integer and displays the results" << endl << endl;
    
    //takes in a string from the user
    cout << "please enter a string: ";
    getline(cin, str);
    
    //sets length to the length of the string
    length = str.length();
    
    //goes through each element of the string
    for(int i = 0; i < length; i++)
    {
        //if the first element of the string is an alpha, set alpha to true (int will be 0)
        if(i == 0 && isalpha(str[i]))
            alpha = true;
        else
            //checks to see if string element is a number. If it is, adds it to str2. If not, sets i to length (ends loop)
            if(!isalpha(str[i]))
                str2 += str[i];
            else
                i = length;
    }
    
    //length is set to str2 length
    length = str2.length();
    
    //if alpha is not true, calls the stringToInt function and sets it to nums
    if(!alpha)
        nums = stringToInt(nums, length, str2);
        
    //displays nums
    cout << nums;
    
    return 0;
}

//purpose: transfer the elements of str2 to nums (string variable to int variable)
//arguments: nums is sent over because it holds the value being returned. length is sent over because it
//strops the loop from going past the string. str2 is sent over because it is what is being changed to an int
int stringToInt(int nums, int length, string str2)
{
    //goes through each element of str2 and adds it to the nums variable.
    for(int i = 0; i < length; i++)
        nums += (str2[length - i - 1] - 48) * pow(10,i);
        
    //returns nums
    return nums;
}
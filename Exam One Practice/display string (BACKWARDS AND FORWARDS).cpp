/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
void display(string);
void display2(string);
int main()
{
    string words = "hi there";
    
    display(words);
    display2(words);
    return 0;
}

void display(string words)
{
    static int i = 0;
    
    if(i < words.length())
    {
        cout << words[i] << endl;
        i = i + 1;
        display(words);
    }
}

void display2(string words)
{
    static int i = 0;
    
    if(i < words.length())
    {
        cout << words[words.length() - i - 1] << endl;
        i = i + 1;
        display2(words);
    }
}
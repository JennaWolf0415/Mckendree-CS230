/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
bool palindormic(string, int, int);
int main()
{
    string words = "kayak";
    int start = 0;
    int end = words.length() - 1;
    
    if(palindormic(words, start, end))
        cout << "The word is palindormic" << endl;
    else
        cout << "the word is not palindormic" << endl;

    return 0;
}

bool palindormic(string words, int start, int end)
{
    
    if(start > end)
        return true;
    else
    {
        if(words[start] == words[end])
            return palindormic(words, start + 1, end - 1);
        else
            return false;
    }
}
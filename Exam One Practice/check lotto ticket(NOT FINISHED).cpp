/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void generateLotteryNumbers(int []);
void getUserNumbers(int []);
int matchDigits(int [],int [],int);
void printOutResults(int [],int [],int);
int main()
{
    int lottery[5];
    int guess[5];
    int same;
    
    generateLotteryNumbers(lottery);
    getUserNumbers(guess);
    printOutResults(lottery, guess, same);

    return 0;
}

void generateLotteryNumbers(int lottery[])
{
    srand(time(0));
    
    for(int i = 0; i < 5; i++)
        lottery[i] = rand() % 10;
}

void getUserNumbers(int guess[])
{
    for(int i = 0; i < 5; i++)
    {
        cout << "please enter your number for position " << i + 1 << endl;
        cin >> guess[i];
    }
}

int matchDigits(int lottery[],int guess[],int same)
{
    for(int i = 0; i < 5; i++)
    {
        if(lottery[i] == guess[i])
            same++;
    }
    return same++;
}
void printOutResults(int lottery[],int guess[],int same)
{
    cout << "Winning lotto ticket: " << endl;
    for(int i = 0; i < 5; i++)
        cout << lottery[i] << " ";
        
    cout << endl;
    cout << matchDigits(lottery, guess, same) << " of your digits matched" ;
    
    if(matchDigits(lottery, guess, same) == 5)
        cout << "congrats! you won the lottery!";
}
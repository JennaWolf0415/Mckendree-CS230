/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void generateLotteryNumbers(int [][3]);
void getUserNumbers(int [][3]);
int matchDigits(int [][3],int [][3], int);
void printOutResults(int [][3],int [][3], int);
int main()
{
    int lottery[3][3];
    int guess[3][3];
    int same;
    
    generateLotteryNumbers(lottery);
    getUserNumbers(guess);
    printOutResults(lottery, guess, same);

    return 0;
}

void generateLotteryNumbers(int lottery[][3])
{
    srand(time(0));
    
    for(int i = 0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
            lottery[i][j] = rand() % 10;
    }
}

void getUserNumbers(int guess[][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << "please enter your next nubmer: ";
            cin >> guess[i][j];
        }
    }
}

int matchDigits(int lottery[][3],int guess[][3],int same)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(lottery[i][j] == guess[i][j])
                same++;
        }
    }
    return same++;
}
void printOutResults(int lottery[][3],int guess[][3],int same)
{
    cout << "Winning lotto ticket: " << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << lottery[i][j] << " ";
        cout << endl;
    }
    
    cout << "Your lotto ticket: " << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            cout << guess[i][j] << " ";
        cout << endl;
    }
    
    cout << endl;
    cout << matchDigits(lottery, guess, same) << " of your digits matched" ;
    
    if(matchDigits(lottery, guess, same) == 5)
        cout << "congrats! you won the lottery!";
}
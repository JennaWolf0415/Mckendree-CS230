//File:lab3_p3
//Description: Takes in 5 students scores and drops the lowest of them. Then calculates the average of the other 5.
//Author: Jenna Wolf
//Student ID: 0347845
//Date: January 31st, 2023
#include <iostream>

using namespace std;
void getScore(double &);
void calcAverage(double,double,double,double,double);
int findLowest(double,double,double,double,double);
int main()
{
    double score1;      //holds the 1st score data
    double score2;      //holds the 2nd score data
    double score3;      //holds the 3rd score data
    double score4;      //holds the 4th score data
    double score5;      //holds the 5th score data
    
    //explains what this program does
    cout << "This program allows you to enter 5 students scores. It then will get rid of the lowest score and display the";
    cout << endl << "average of the other 4 scores." << endl;
    
    //Calls the getScore function so the scores can be inupted
    getScore(score1);
    getScore(score2);
    getScore(score3);
    getScore(score4);
    getScore(score5);
    
    //Calcs the calAverage function to calculate the average of the scores
    calcAverage(score1, score2, score3, score4, score5);

    return 0;
}

//Purpose: The purpose of this function is to get each of the students scores. It then sends the scores entered back to main
//by using a refrence parameter.
//Parameters: &num is a refrence parameter that is used to send back the score entered to the argument score that is
//sent over
void getScore(double &num)
{
    //Takes the input for the score
    cout << "What is the score of this student? ";
    cin >> num;
    
    //Checks to make sure the score is between 0 and 100
    while(num > 100 || num < 0)
    {
        cout << "please enter a proper score! (between 0 and 100) ";
        cin >> num;
    }
}

//Purpose: The purpose of this function is to calculate the average of the 5 scores that are sent over.
//Parameters: s1, s2, s3, s4, and s5 are all just simplified names that hold the score data so that the function
//can calculate the average of the 5.
void calcAverage(double s1, double s2, double s3, double s4, double s5)
{
    double average;     //holds the average data
    double low;         //holds the low data
    
    //calls the findLowest to find the lowest score
    low = findLowest(s1, s2, s3, s4, s5);
    
    //calculates the average of the 4 highest scores
    average = (s1 + s2 + s3 + s4 + s5 - low) / 4;
    
    //displays the score
    cout << "Your average test score is " << average;
}

//Purpose: The purpose of this function is to find the lowest score out of the 5 scores and send it back to findAverage
//so that the findAverage function can get rid of the lowest score during its calculations.
//Parameters: s1, s2, s3, s4, and s5 are sent to this function so that the function has the data it needs to determin
//which of the 5 scores are lowest. It uses these number to tell the findAverage function which of the 5 it should get rid of.
int findLowest(double s1, double s2, double s3, double s4, double s5)
{
    double low;     //holds the low data
    double value;   //holds the value data
    
    //assignes score1 as the lowest score. Then runs through a check to see if any other scores are lower.
    low = s1;
    value = s2;
    if(value < low)
        low = value;
    value = s3;
    if(value < low)
        low = value;
    value = s4;
    if(value < low)
        low = value;
    value = s5;
    if(value < low)
        low = value;
    return low;
}
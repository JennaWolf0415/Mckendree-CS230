//program: lab9_p1
//purpose: This program asks 5 questions to one player and 5 questions to another player. It then displays how
//many questions each player got right and which player won.
//name: Jenna Wolf
//student id: 0347845
//date: April 10th, 2023
#include <iostream>
#include <fstream>

using namespace std;

class Question
{
    private:
        string quest;   //holds the quest data
        string opt1;    //holds the opt1 data
        string opt2;    //holds the opt2 data
        string opt3;    //holds the opt3 data
        string opt4;    //holds the opt4 data  
        char awn;       //holds the awn data
    public:
        Question();
        void setQuest(string a);
        void setOpt1(string a);
        void setOpt2(string a);
        void setOpt3(string a);
        void setOpt4(string a);
        void setAwn(int a);
        string getQuest() const;
        string getOpt1() const;
        string getOpt2() const;
        string getOpt3() const;
        string getOpt4() const;
        int getAwn() const;
};

void getFileData(Question *);
const int SIZE = 10;    //const that holds the SIZE data at 10
int main()
{
    Question * ptr = new Question[SIZE];    //holds the ptr data and sets it to new Quetion of SIZE
    int PlayOne = 0;                        //holds the playOne data and sets it to 0
    int PlayTwo = 0;                        //holds the playTwo data and sets it to 0
    int choice;                             //holds the choice data
    
    //tells the user what the program is
    cout << "this program is a game! Each player gets 5 questions to answer and whoever gets the most right wins!" << endl << endl;
    
    getFileData(ptr);   //gets the data from the file

    //for loop that repeats until i and bigger that SIZE
    for(int i = 0; i < SIZE; i++)
    {
        //displays PLAYER ONE when i = 0
        if(i == 0)
            cout << "PLAYER ONE:" << endl << endl;
        
        //displays PLAYER TWO when i = 5
        if(i == 5)
            cout << "PLAYER TWO:" << endl << endl;
        
        //displays the question and options. Takes in answer from user
        cout << ptr[i].getQuest() << endl << "1. " << ptr[i].getOpt1() << endl << "2. " << ptr[i].getOpt2() << endl;
        cout << "3. " << ptr[i].getOpt3() << endl << "4. " << ptr[i].getOpt4() << endl;
        cin >> choice;
        
        //makes sure answer is between 0 and 4
        while(choice > 4 || choice < 0)
        {
            cout << "PLEASE ENTER A PROPER CHOICE! ";
            cin >> choice;
        }
        
        //checks to see if choice is equal to ptr[i].Awn
        if(choice == ptr[i].getAwn())
        {
            //adds one to playerOne is i is less that 5. if not, add one to playerTWo
            if(i < 5)
                PlayOne += 1;
            else
                PlayTwo += 1;
        }
        
        //creates a empty line
        cout << endl;
    }
    
    //displays how many points each player got
    cout << "Player one points: " << PlayOne << endl << "Player two points: " << PlayTwo << endl;
    
    //displays weather the players tied or which player won
    if(PlayOne == PlayTwo)
        cout << "ITS A TIE!" << endl;
    else if (PlayOne > PlayTwo)
        cout << "PLAYER ONE WINS!" << endl;
    else
        cout << "PLAYER TWO WINS!" << endl;
        

    return 0;
}

//purpose: constructor that sets all values of Question to 0
//argument: no arguments
Question::Question()
{
    quest = " ";    //sets quest to blank
    opt1 = " ";     //sets opt1 to blank
    opt2 = " ";     //sets opt2 to blank
    opt3 = " ";     //sets opt3 to blank
    opt4 = " ";     //sets opt4 to blank
    awn = 0;        //sets awn to 0
}

//purpose: function sets quest to a
//argument: a is what quest is set to
void Question::setQuest(string a)
{
    quest = a;  //sets quest to a
}

//purpose: function sets opt1 to a
//argument: a is what opt1 is set to
void Question::setOpt1(string a)
{
    opt1 = a;   //sets opt1 to a
}

//purpose: function sets opt2 to a
//argument: a is what opt2 is set to
void Question::setOpt2(string a)
{
    opt2 = a;   //sets opt2 to a
}
//purpose: function sets opt3 to a
//argument: a is what opt3 is set to
void Question::setOpt3(string a)
{
    opt3 = a;   //sets opt2 to a
}

//purpose: function sets opt4 to a
//argument: a is what opt4 is set to
void Question::setOpt4(string a)
{
    opt4 = a;  //sets opt4 to a
}

//purpose: function sets awn to a
//argument: a is what awn is set to
void Question::setAwn(int a)
{
    awn = a;    //sets awn to a
}

//purpose: returns the value stored in quest
//argument: no argument
string Question::getQuest() const
{
    return quest;   //returns quest
}

//purpose: returns the value stored in opt1
//argument: no argument
string Question::getOpt1() const
{
    return opt1;    //returns opt1
}

//purpose: returns the value stored in opt2
//argument: no argument
string Question::getOpt2() const
{
    return opt2;    //returns opt2
}

//purpose: returns the value stored in opt3
//argument: no argument
string Question::getOpt3() const
{
    return opt3;    //returns opt3
}

//purpose: returns the value stored in opt4
//argument: no argument
string Question::getOpt4() const
{
    return opt4;    //returns opt4
}

//purpose: returns the value stored in awn
//argument: no argument
int Question::getAwn() const
{
    return awn;     //returns awn
}

//purpose: this function gets the data from the file and sets the values in ptr to it
//arguments: ptr is what holds the data in the file
void getFileData(Question * ptr)
{
    string temp;    //holds the temp data
    
    //opens the file
    ifstream infile;
    infile.open("text.txt");
    
    //makes sure the file opens properly
    if(!infile)
    {
        cout << "FILE FAILED TO OPEN!!" << endl;
        exit(EXIT_FAILURE);
    }
    
    //for loop that repeats until i is bigger than SIZE
    for(int i = 0; i < SIZE; i++)
    {
        //sets Quest to temp
        getline(infile, temp);
        ptr[i].setQuest(temp);
        
        //sets Opt1 to temp
        getline(infile, temp);
        ptr[i].setOpt1(temp);
        
        //sets Opt2 to temp
        getline(infile, temp);
        ptr[i].setOpt2(temp);
        
        //sets Opt3 to temp
        getline(infile, temp);
        ptr[i].setOpt3(temp);
        
        //sets Opt4 to temp
        getline(infile, temp);
        ptr[i].setOpt4(temp);
        
        //sets awn to temp
        getline(infile, temp);
        ptr[i].setAwn(stoi(temp));
        
        //gets the empty line
        getline(infile, temp);
    }
}
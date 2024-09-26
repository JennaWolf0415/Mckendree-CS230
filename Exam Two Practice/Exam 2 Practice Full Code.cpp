//lab:EXAM 2 PRACTICE
//purpose: Read in data from a file that has descriptions and parts. Let the user choose weather they want to edit a bin
//(lets them add/remove parts or change the description of a bin), write data of bin to a file, sort the bins in
//ascending/descending order by parts/descriptions, search for a description or number of parts, or quit.
//name: Jenna Wolf
//student ID: 0347845
//date: 3/28/2023
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
struct InventoryBin
{
  string description;       //holds the description data
  int parts;                //holds the parts data
};

int getN();
void readFile(InventoryBin *, int);
void selectBin(InventoryBin[], int);
void addParts(InventoryBin&, int);
void removeParts(InventoryBin&, int);
void editDiscription(InventoryBin&, int);
void outputToFile(InventoryBin *, int);
void swap(InventoryBin &, InventoryBin &);
void sortBinsDescending(InventoryBin *, int, int);
void sortBinsAscending(InventoryBin *, int, int);
void searchDescription(InventoryBin *, int);
void searchParts(InventoryBin *, int);
int main()
{
    int n;              //holds the n (number) data
    int ans;            //holds the ans data
    int sortAns;        //holds the sortAns data
    InventoryBin * ptr; //holds the ptr data (is a pointer)
    
    n = getN();                 //scalls getN and sets n to the result
    ptr = new InventoryBin[n];  //dynamically allocated ptr to an array of size n
    readFile(ptr, n);           //calls the readFile function
    
    //a loop that runs until the user enters 5
    do
    {
        //aligns output to the left and displays headers. Then displays the data in ptr. Then displays an endl.
        cout << std::left << setw(4) << "#" << setw(20) << "description" << "parts" << endl;
        for(int i = 0; i < n; i++)
            cout << setw(4) << i + 1 << setw(20) << ptr[i].description << ptr[i].parts << endl;
        cout << endl;
        
        //displays a menu to the user and takes in their answer. Makes sure said answer is a proper answer.
        cout << "please select an option: " << endl;
        cout << "1. edit a bin" << endl;
        cout << "2. write bin data to a file" << endl;
        cout << "3. Sort bins in a order" << endl;
        cout << "4. search the bins for a description or number of parts" << endl;
        cout << "5. quit" << endl;
        cin >> ans;
        while (ans > 5 || ans < 1)
        {
            cout << "please enter a proper answer!" << endl;
            cin >> ans;
        }
        
        //if statements that check what ans is and goes to the appropriate commands
        if(ans == 1)
            selectBin(ptr, n);  //calls the selectBin function
        else if(ans == 2)
            outputToFile(ptr, n);   //calls the outputToFile function
        else if(ans == 3)
        {
            //displays a menu and takes in input from user. Makes sure answer is a proper answer.
            cout << "How would you like to organize the bins?" << endl;
            cout << "1. Ascending parts" << endl;
            cout << "2. Ascending description" << endl;
            cout << "3. Descending parts" << endl;
            cout << "4. Descending description" << endl;
            cin >> sortAns;
            while (sortAns > 4 || sortAns < 1)
                {
                    cout << "please enter a proper answer!" << endl;
                    cin >> sortAns;
                }
            
            //if statements that check what sortAns is and goes to the appropriate commands
            if(sortAns < 3)
                sortBinsAscending(ptr, n, sortAns);     //calls the sortBinsAscending function
            else
                sortBinsDescending(ptr, n, sortAns);    //calls the sortBinsDescending function
        }
        else if(ans == 4)
        {
            //displays a menu and takes in the users input. makes sure input is a proper answer.
            cout << "where would you like to search? " << endl;
            cout << "1.description" << endl;
            cout << "2.parts" << endl;
            cin >> sortAns;
            while (sortAns > 2 || sortAns < 1)
                {
                    cout << "please enter a proper answer!" << endl;
                    cin >> sortAns;
                }
            //if statements that check what ans is and goes to the appropriate commands
            if(sortAns == 1)
                searchDescription(ptr, n);  //calls the searchDescription function
            else
                searchParts(ptr, n);        //calls the searchParts function
        }
         
        sortAns = 0;  //sets sortAns to 0
        
    }while (ans != 5);  //if ans = 5, then loop ends
    
    return 0;
}

//purpose: This function goes through the file and gets the amount of lines in the file and returns the value
//arguments: none
int getN()
{
    int n;                      //holds the n data
    string temp;                //holds the temp data
    
    //opens the file
    ifstream infile;            
    infile.open("text.txt");
    
    //displays an error is file didn't open
    if(!infile)
    {
        cout << "file failed to open, try again!" << endl;
        exit(EXIT_FAILURE);
    }
    
    //adds 1 to n for each line in the file
    while(getline(infile, temp))
        n += 1;
        
    infile.close(); //closes the file
    
    return n;   //returns n
}

//purpose:  This function reads the data from the file into ptr's description and parts values.
//argument: ptr is sent over because it is what holds the data, n is sent over because it is the size of ptr
void readFile(InventoryBin * ptr, int n)
{
    string temp;                //holds the temp data
    int position;               //holds the position data
    
    //opens the file
    ifstream infile;
    infile.open("text.txt");
    
    //displays and error is file fails to open
    if(!infile)
    {
        cout << "file failed to open, try again!" << endl;
        exit(EXIT_FAILURE);
    }
    
    //loop that steps through each line in the file
    for(int i = 0; i < n; i++)
    {
        getline(infile, temp);          //gets the line from the file and sets it to temp
        position = temp.find(",", 0);   //sts position to where the , is in the file
        
        //sets description to the line left of position and parts to the line right of position
        ptr[i].description = temp.substr(0, position - 1);
        ptr[i].parts = stoi(temp.substr(position + 1, temp.length()));
    }
    
    infile.close(); //closes the file
}

//purpose: This function allows the user to pick the bin they want to change as well as allowing the user to
//choose what they want to do in each bin.
//arguments: ptr holds the data that is being changes/used. n holds the size of ptr, which is needed for checks.
void selectBin(InventoryBin ptr[], int n)
{
    int bin;        //holds the bin data
    int decision;    //holds the decision data
    
    //asks the user what bin they want to change and takes in their answer. Makes sure proper answer is entered.
    cout << "which bin would you like to edit? ";
    cin >> bin;
    while( bin > n || bin < 0)
    {
        cout << "please enter a proper answer! (bins are between 1 and " << n << ")" << endl;
        cin >> bin;
    }
            
    //displays a menu for the user and takes in their input. Makes sure proper answer is entered.
    cout << "what would you like to do in this bin?" << endl;
    cout << "1.Add Parts" << endl;
    cout << "2.Remove Parts" << endl;
    cout << "3.Change Description" << endl;
    cin >> decision;
    while( decision > 3 || decision < 0)
    {
        cout << "please enter a proper answer!" << endl;
        cin >> decision;
    }
            
    //if statements that check what decision is and goes to the appropriate commands
    if(decision == 1)
        addParts(ptr[bin - 1], bin);        //calls the addParts function
    else if(decision == 2)
        removeParts(ptr[bin - 1], bin);     //calls the removeParts function
    else
        editDiscription(ptr[bin - 1], bin); //calls the editDiscription function
}

//purpose: This function lets the user add parts to the bin of there choice (up to 30 parts)
//arguments: current holds the data that is being edited. bin is the number bin that is being edited.
void addParts(InventoryBin &current, int bin)
{
    int number; //holds the number data
    
    //asks the user how many parts they would like to add to the bin and takes in the answer. Checks to make
    //sure proper answer is entered
    cout << "how many parts would you like to add to bin " << bin << "?" << endl;
    cout << "(this bin current has " << current.parts << " parts)" << endl;
    cin >> number;
    while (number + current.parts > 30)
    {
        cout << "that makes the bin have more than 30 parts! that is not allowed!" << endl;
        cout << "how many parts would you like to add to bin " << bin << "? " << endl;
        cin >> number;
    }
    
    current.parts += number;    //adds number to the parts in the selected bin
}

//purpose: This function lets the user remove parts from the bin of there choice (can't be less than 0)
//arguments: current holds the data that is being edited. bin is the number bin that is being edited.
void removeParts(InventoryBin &current, int bin)
{
    int number; //holds the number data
    
    //asks the user how many parts they would like to remove from the bin and takes in the answer. Checks to make
    //sure proper answer is entered
    cout << "how many parts would you like to remove from bin " << bin << "?" << endl;
    cout << "(this bin current has " << current.parts << " parts)" << endl;
    cin >> number;
    while (current.parts - number < 0)
    {
        cout << "that makes the bin have no parts! that is not allowed!" << endl;
        cout << "how many parts would you like to remove from bin " << bin << "? " << endl;
        cin >> number;
    }
    
    current.parts -= number;    //removes number from the parts in the selected bin
}

//purpose: edits the description of the bin the user selected
//arguments: current holds the data that is being edited. bin is the number bin that is being edited.
void editDiscription(InventoryBin &current, int bin)
{
    //asks the user what they would like the new description to be and sets their input to the description
    //of the current bin
    cout << "current discription: " << current.description << endl;
    cout << "What would you like the new description to be?" << endl;
    cin.ignore();
    getline(cin, current.description);
}

//purpose: output the current data of all bins to the text.txt file.
//ptr holds the data that is being exported. n is the number of bins and is used for checks
void outputToFile(InventoryBin * ptr, int n)
{
    //opens the output file
    ofstream outfile;
    outfile.open("text.txt");
    
    //sends an error if file fails to open
    if(!outfile)
    {
        cout << "file failed to open, try again!" << endl;
        exit(EXIT_FAILURE);
    }
    //sends all data from ptr to the text file
    for(int i = 0; i < n; i++)
        outfile << ptr[i].description << " , " << ptr[i].parts << endl;
        
    //closes the file
    outfile.close();
}

//purpose: swarp the data of the two items sent over
//arguments: a and b hold the data being swapped
void swap(InventoryBin &a, InventoryBin &b)
{
    InventoryBin temp = a;      //holds the temp data and is set to a
    a = b;                      //a is set to b
    b = temp;                   //b is set to temp
}

//purpose: sort the bins into ascending order either by parts or description (users choice)
//arguments: ptr is the data being sorted, n is the size of ptr and is used for checks, ans is
//the users decision to sort either description or parts
void sortBinsAscending(InventoryBin * ptr, int n, int ans)
{
    int minI;   //holds the minI data
    int minV;   //holds the minV data
    int current; //holds the current data
    
    //checks to see what the user awnsers and follows code accordingly
    if(ans == 1)
    {
        //tests to see if all elements of the array have been stepped through. If they have, loop ends.
        for (int start = 0; start < (n - 1); start ++)
        {
            //sets minI and minV to the current element of the array we are testing.
            minI = start;
            minV = ptr[start].parts;
        
            //steps through each element on the array, testing them. After all elements have been stepped through, loop stops
            for (int i = start + 1; i < n; i ++)
            {
                //tests to see if a element is smaller than the current element in its spot. If it is, minV and minI are set to
                //the current elements spot (to soon be swapped if it is the smalest)
                if(ptr[i].parts < minV)
                {
                    minV = ptr[i].parts;
                    minI = i;
                }
            }
            swap(ptr[minI], ptr[start]);    //calls the swap function
        }
    }
    else
    {
        //tests to see if all elements of the array have been stepped through. If they have, loop ends.
        for (int start = 0; start < (n - 1); start ++)
        {
            //sets minI and minV to the current element of the array we are testing.
            //sets current to beginning position
            current = 0;
            minI = start;
            minV = ptr[start].description[current];
        
            //steps through each element on the array, testing them. After all elements have been stepped through, loop stops
            for (int i = start + 1; i < n; i ++)
            {
                //compares the current letters to see if they are the same. If they are, set variables to the next letter.
                while(ptr[i].description[current] == minV)
                {
                    current += 1;
                    minV = ptr[start].description[current];
                }
                //tests to see if a element is smaller than the current element in its spot. If it is, minV and minI are set to
                //the current elements spot (to soon be swapped if it is the smalest)
                if(ptr[i].description[current] < minV)
                {
                    minV = ptr[i].description[current];
                    minI = i;
                    current = 0;
                }
            }
            swap(ptr[minI], ptr[start]);    //calls the swap function
        }
    }
}

//purpose: sort the bins into descending order either by parts or description (users choice)
//arguments: ptr is the data being sorted, n is the size of ptr and is used for checks, ans is
//the users decision to sort either description or parts
void sortBinsDescending(InventoryBin * ptr, int n, int ans)
{
    int minI;   //holds the minI data
    int minV;   //holds the minV data
    int current; //holds the current data
    
    //checks to see what the user awnsers and follows code accordingly
    if(ans == 3)
    {
        //tests to see if all elements of the array have been stepped through. If they have, loop ends.
        for (int start = 0; start < (n - 1); start ++)
        {
            //sets minI and minV to the current element of the array we are testing.
            minI = start;
            minV = ptr[start].parts;
        
            //steps through each element on the array, testing them. After all elements have been stepped through, loop stops
            for (int i = start + 1; i < n; i ++)
            {
                //tests to see if a element is bigger than the current element in its spot. If it is, minV and minI are set to
                //the current elements spot (to soon be swapped if it is the smalest)
                if(ptr[i].parts > minV)
                {
                    minV = ptr[i].parts;
                    minI = i;
                }
            }
            swap(ptr[minI], ptr[start]);    //calls the swap function
        }
    }
    else
    {
        //tests to see if all elements of the array have been stepped through. If they have, loop ends.
        for (int start = 0; start < (n - 1); start ++)
        {
            //sets minI and minV to the current element of the array we are testing.
            //sets current to beginning position
            current = 0;
            minI = start;
            minV = ptr[start].description[current];
        
            //steps through each element on the array, testing them. After all elements have been stepped through, loop stops
            for (int i = start + 1; i < n; i ++)
            {
                //compares the current letters to see if they are the same. If they are, set variables to the next letter.
                while(ptr[i].description[current] == minV)
                {
                    current += 1;
                    minV = ptr[start].description[current];
                }
                //tests to see if a element is bigger than the current element in its spot. If it is, minV and minI are set to
                //the current elements spot (to soon be swapped if it is the smalest)
                if(ptr[i].description[current] > minV)
                {
                    minV = ptr[i].description[current];
                    minI = i;
                    current = 0;
                }
            }
            swap(ptr[minI], ptr[start]);    //calls the swap function
        }
    }
}

//purpose: searches through all description and tells the user if a bin has the description
//they are searching for.
//arguments: ptr is what is being searched, n is the size of ptr and is used for checks
void searchDescription(InventoryBin * ptr, int n)
{
    string search;      //holds the search data
    int index = 0;      //holds the index data and is set to 0
    
    //takes in the input from the user on what they are searching for
    cout << "what are you searching for? (Beware of capitalization!)" << endl;
    cin.ignore();
    getline(cin, search);
    
    //checks each bin description
    while(index < n)
    {
        //if the current bin description matches the search, then it tells the user
        if(ptr[index].description == search)
                    cout << "the description you were looking for is in bin " << index + 1 << endl;
        index++;    //adds one to index
    }
    cout << endl;   //creates a space
}

//purpose: searches through all parts and tells the user if a bin has the parts
//they are searching for.
//arguments: ptr is what is being searched, n is the size of ptr and is used for checks
void searchParts(InventoryBin * ptr, int n)
{
    int search;         //holds the seach data
    int index = 0;      //holds the index data at 0
    
    //takes in the input from the user on what they are searching for
    cout << "What number of parts are you searching for?" << endl;
    cin >> search;
    while(search > 30 || search < 0)
    {
        cout << "please enter a proper answer!";
        cin >> search;
    }
    
    //checks each bins parts
    while(index < n)
    {
        //if the current bin parts matches the search, then it tells the user
        if(ptr[index].parts == search)
            cout << "bin " << index + 1 << " has " << search << " parts" << endl;
        index++;    //adds one to index
    }
    cout << endl;   //creates a space
}
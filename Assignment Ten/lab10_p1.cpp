//program: lab10_p1
//purpose: This program is used to practice inheritance. It has CustomerData, which is a derived class, and
//Persondata, which is a base class. It reads in data from a file a file and displays it.
//name: Jenna Wolf
//student id: 0347845
//date: May 1st, 2023

#include <iostream>
#include <fstream>

using namespace std;

class PersonData
{
    private:
        string lastName;        //holds the lastName data
        string firstName;       //holds the firstName data
        string address;         //holds the address data
        string city;            //holds the city data
        string state;           //holds the state data
        string zip;             //holds the zip data
        string phone;           //holds the phone data
    public:
        PersonData();
        void setLastName(string);
        void setFirstName(string);
        void setAddress(string);
        void setCity(string);
        void setState(string);
        void setZip(string);
        void setPhone(string);
        string getLastName();
        string getFirstName();
        string getAddress();
        string getCity();
        string getState();
        string getZip();
        string getPhone();
};

class CustomerData : public PersonData
{
    private:
        int customerNumber;         //holds the customerNumber data
        bool mailingList;           //holds the mailingList data
    public:
        CustomerData();
        void setCustomerNumber(int);
        void setMailingList(bool);
        int getCustomerNumber();
        bool getMailingList();
};

void readFile(CustomerData []);
int main()
{
    CustomerData data[10];  //creates an array that holds the data(has a size of 10)
    readFile(data);         //calls the readFile function

    //displays the data in the array
    for(int i = 0; i < 10; i++)
    {
        cout << data[i].getLastName() << ", " << data[i].getFirstName() << ", " << data[i].getAddress() << ", ";
        cout << data[i].getCity() << ", " << data[i].getState() << ", " << data[i].getZip() << ", ";
        cout << data[i].getPhone() << ", " << data[i].getCustomerNumber() << ", ";
        if(data[i].getMailingList())
            cout << "YES!" << endl;
        else
            cout << "NO!" << endl;
    }
    return 0;
}

//purpose: sets the data in PersonData to blanks
//arguments: no arguments
PersonData::PersonData()
{
    lastName = " ";     //sets lastName to a blank
    firstName = " ";    //sets firstName to a blank
    address = " ";      //sets address to a blank
    state = " ";        //sets state to a blank
    city = " ";         //sets city to a blank
    zip = " ";          //sets zip to a blank
    phone = " ";        //sets phone to a blank
}

//purpose: sets lastName to the data that is sent over
//argument: string holds the data lastName is set to
void PersonData::setLastName(string str)
{
    lastName = str;     //sets lastName to str
}

//purpose: sets firstName to the data that is sent over
//argument: string holds the data firstName is set to
void PersonData::setFirstName(string str)
{
    firstName = str;    //sets firstName to str
}

//purpose: sets address to the data that is sent over
//argument: string holds the data address is set to
void PersonData::setAddress(string str)
{
    address = str;      //sets address to str
}

//purpose: sets city to the data that is sent over
//argument: string holds the data city is set to
void PersonData::setCity(string str)
{
    city = str;         //sets city to str
}

//purpose: sets state to the data that is sent over
//argument: string holds the data state is set to
void PersonData::setState(string str)
{
    state = str;        //sets state to str
}

//purpose: sets zip to the data that is sent over
//argument: string holds the data zip is set to
void PersonData::setZip(string str)
{
    zip = str;          //sets zip to str
}

//purpose: sets phone to the data that is sent over
//argument: string holds the data phone is set to
void PersonData::setPhone(string str)
{
    phone = str;        //sets phone to str
}

//purpose: returns the data stored in lastName
//argument: no arguments
string PersonData::getLastName()
{
    return lastName;    //return the data in lastName
}

//purpose: returns the data stored in firstNAme
//argument: no arguments
string PersonData::getFirstName()
{
    return firstName;   //return the data in firstName
}

//purpose: returns the data stored in address
//argument: no arguments
string PersonData::getAddress()
{
    return address;     //return the data in address
}

//purpose: returns the data stored in city
//argument: no arguments
string PersonData::getCity()
{
    return city;        //return the data in city
}

//purpose: returns the data stored in state
//argument: no arguments
string PersonData::getState()
{
    return state;       //return the data in state
}

//purpose: returns the data stored in zip
//argument: no arguments
string PersonData::getZip()
{
    return zip;         //return the data in zip
}

//purpose: returns the data stored in phone
//argument: no arguments
string PersonData::getPhone()
{
    return phone;       //return the data in phone
}

//prupose: sets the data in customerData to blanks
//arguments: no arguments
CustomerData::CustomerData()
{
    customerNumber = 0;     //sets customerNumber to 0
    mailingList = false;    //sets mailingList to false
}

//purpose: sets customerNumber to the data that is sent over
//argument: string holds the data customerNumber is set to
void CustomerData::setCustomerNumber(int a)
{
    customerNumber = a;     //sets customerNumber to a
}

//purpose: sets mailingList to the data that is sent over
//argument: string holds the data mailingList is set to
void CustomerData::setMailingList(bool ans)
{
    mailingList = ans;      //sets mailingList to ans
}

//purpose: returns the data stored in customerNumber
//argument: no arguments
int CustomerData::getCustomerNumber()
{
    return customerNumber;  //return the data in customerNumber
}

//purpose: returns the data stored in mailingList
//argument: no arguments
bool CustomerData::getMailingList()
{
    return mailingList;     //return the data in mailingList
}

//purpose: read in the data from the file and set it to the values in CustomerData
//argmuents: data is what holds the data from the file
void readFile(CustomerData data[])
{
    string temp;    //holds the temp data
    int pos;        //holds the pos data
    
    //opens the infile text.txt
    ifstream infile;        
    infile.open("text.txt");
    
    //makes sure file opens properly
    if(!infile)
    {
        cout << "FILE FAILED TO OPEN!" << endl;
        exit(EXIT_FAILURE);
    }
    
    //for loop that goes through each value of the array
    for(int i = 0; i < 10; i++)
    {
        //sets the Last Name
        getline(infile, temp);
        pos = temp.find(",", 0);
        data[i].setLastName(temp.substr(0, pos));
        
        //sets the First Name
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        data[i].setFirstName(temp.substr(1, pos - 1));
        
        //sets the Address
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        data[i].setAddress(temp.substr(1, pos - 1));
        
        //sets the City
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        data[i].setCity(temp.substr(1, pos - 1));
        
        //sets the State
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        data[i].setState(temp.substr(1, pos - 1));
        
        //sets the Zip Code
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        data[i].setZip(temp.substr(1, pos - 1));
        
        //sets the Phone Number
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        data[i].setPhone(temp.substr(1, pos - 1));
        
        //sets the Customer Number
        temp = temp.substr(pos + 1, temp.length());
        pos = temp.find(",", 0);
        data[i].setCustomerNumber(stoi(temp.substr(1, pos - 1)));
        
        //sets the Mailing List
        if(temp[pos + 2] - 48 != 1)
            data[i].setMailingList(true);
    }
}
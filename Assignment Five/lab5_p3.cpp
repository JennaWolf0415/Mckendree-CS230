//file: lab5_p3
//purpose: This program displays an array of random size and random elements between 1 and 10. It then reverse the array
//elements and displays the array again
//author: Jenna Wolf
//student id: 0347845
//date: 2/23/2023

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int *reverse(int *, int);
void showArray(int *, int);
int main()
{
    int * ptr;  //holds the ptr data (is a pointer)
    int size;   //holds the size data
    
    //tells the user what the program does
    cout << "this program takes in a size for an array from the user. It then displays an array of that size with random" << endl;
    cout << "elemetns between 1 and 10. It then displays that array again, but the order is now backwards." << endl << endl;
    
    //takes in the array size from the user
    cout<<"Enter a size: ";
    cin >> size;
    
    ptr = new int[size];    //sets the pointer to a new int array that is equal to size;
    
    //fills the ptr with random elements between 1 and 10
    srand(time(0));
    for(int i = 0; i < size; i++)
        ptr[i] = (rand() % 11);
        
    //dispalys the ptr array
    cout << "array forward: ";
    for(int i = 0; i < size; i++)
        cout << ptr[i] << " ";
    cout << endl;
    
    //calls the reverse function and sets the ptr to what is returned
    ptr = reverse(ptr, size);
    
    //calls the showArray function
    showArray(ptr, size);
    
    //deletes what the ptr is pointing to
    delete []ptr;
    return 0;
}

//purpose: the purpose of this array is to take in an array and reverse the order of the elements in said array. It then
//returns the array
//arguments: ptr is sent over because it points to the array that is being reversed. Size is used to tell how many
//elements are in the array
int *reverse(int * ptr, int size)
{
    int * ptr2;             //holds the ptr2 data (is a pointer)
    ptr2 = new int[size];   //sets ptr to point to a new int array of size
    
    //sets ptr2 array to the elements of ptr array in the opposite order
    for(int i = 0; i < size; i++)
        ptr2[i] = ptr[size - 1 - i];
        
    //returns what ptr2 is pointing to
    return ptr2;
}

//purpose: This array displays the array that is held by ptr
//arguments: ptr points the the array that is being displayed. size is used to tell how many elements are in the array
void showArray(int * ptr, int size)
{
    //displays the ptr array
    cout << "array backwards: ";
    for(int i = 0; i < size; i++)
        cout << ptr[i] << " ";
}
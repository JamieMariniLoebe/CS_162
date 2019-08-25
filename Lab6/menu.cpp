/**************************************
 * Program Name: Lab 6
 * Author: Jamie Loebe
 * Date: 11/04/2018
 * Description: This is the menu file
**************************************/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int menu()
{
    int choice;// Int variable to store the choice
    do
    { //Loop through the menu display if user made an invalid choice

        // Display menu
        cout<<"Welcome!"<<endl;
        cout<<"Please select corresponding number for related operation"<<endl;
        cout<<"1. Add a new node to the head of doubly linked list"<<endl;
        cout<<"2. Add a new node to the tail of doubly linked list"<<endl;
        cout<<"3. Delete first node from the doubly linked list"<<endl;
        cout<<"4. Delete tail node from the doubly linked list"<<endl;
        cout<<"5. Traverse the list reversely"<<endl;
        cin>>choice;// Read in user's choice
        if(choice<1 || choice>5)// Check if choice value is out of range
            cout<<"Invalid menu option! Please try again!"<<endl;// If invalid, display error message
    }while(choice<1||choice>6);// Repeat if choice value is out of range
    return choice;// Return the choice value
}


/********************************************
* Description: This function validates whether
* user entered in valid input.
********************************************/

int readInteger()
{
    int number;// Int variable to store the number entered by the user
    cin>>number;// Read in the number
    while(!cin)// Check if input is a valid integer, if not repeat
    {
        cout<<"Entered number is not an integer! Please enter again: ";// Display an error message and ask user to try again
        cin.clear();// Clear the cin buffer
        cin.ignore();// Ignore the cin input
        cin>>number;// Read in the number again
    }
    return number;
}



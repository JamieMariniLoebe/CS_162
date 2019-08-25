/*********************************************
 * Program Name: Lab 6
 * Author: Jamie Loebe
 * Date: 11/04/2018
 * Description: This is the main file.
*********************************************/

#include "DLL.hpp"
#include "Node.hpp"

int menu();
int readInteger();

// main.cpp
int main()
{
    int menuChoice,number;// Declare ints to store menu choice and number to store into the linked list
    char choice;// Char variable to store user choice if the user wants to repeat operations
    DLL newDLL;// Create an object to class DLL
    do
    {
        menuChoice=menu();// Display menu and read in user input
        switch(menuChoice)// Switch statement according to user input
        {
            case 1://if user entered 1
                cout<<endl<<"Enter an integer to add to head of doubly linked list: ";
                number=readInteger();// Read in number
                newDLL.addNewNodeToHead(number);// Call function and add new number to head of list
                newDLL.traverseList();// Display the list
                break;
            case 2://if user entered 2
                cout<<endl<<"Enter an integer to add to tail of doubly linked list: ";
                number=readInteger();// Read in number
                newDLL.addNewNodeToTail(number);// Call function to add node to tail of list
                newDLL.traverseList();// Display the list
                break;
            case 3://if user entered 3
                cout<<endl<<"Removing a number from head of doubly linked list: ";
                newDLL.deleteHeadNode();// Call function to delete a node from start of the list
                newDLL.traverseList();// Display the list
                break;
            case 4://if user entered 4
                cout<<endl<<"Removing a number from tail of doubly linked list: ";
                newDLL.deleteTailNode();// Call function to delete a node from end of the list
                newDLL.traverseList();// Display the list
                break;
            case 5://if user entered 5
                cout<<endl<<"Linked list in reverse order: "<<endl;
                newDLL.traverseListReverse();// Call function to display the list in reverse order
                break;
        }
        cout<<endl<<"Do you want to continue (y/n)?: ";
        cin>>choice;// Read in the choice
    }while(tolower(choice)=='y');// Loop until user choice is y
    cout<<endl<<endl;
    return 0;
}


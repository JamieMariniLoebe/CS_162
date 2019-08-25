/******************************************
 * Program Name: Lab 7
 * Author: Jamie Loebe
 * Date: 11/10/2018
 * Description: This is the main file for 
 * Lab 7.
******************************************/

#include "Queue.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void add(Queue &newQueue);


int main()
{
    int choice;
    bool cont = false;
    Queue nodes;
    while (!cont)

    {
        cout << "1. Add a value to the back of queue." << endl;
        cout << "2. Display the front value." << endl;
        cout << "3. Remove the front node." << endl;
        cout << "4. Display the queue's content" << endl;
        cout << "5. Exit program." << endl;
        cin >> choice;
    
        switch(choice) // Switch statement for each choice
        {
            case 1:
                add(nodes); // Add node to queue
                break;

            case 2:
                if(nodes.isEmpty()) // If Queue is empty
                    cout << "The queue is empty, please try again!" << endl;
                else
                { // Print first node in queue
                    cout << "The first node in the queue is " << nodes.getFront() << endl;
                    break;
                }

            case 3:
                nodes.removeFront(); // Remove node from front of queue.
                break;

            case 4:
                cout << "Here is the queue so far...." << endl;
                nodes.printQueue(); // Print whole queue
                break;

            case 5:
                cont = true; // Terminate program.
                break;
        }
    }
}

/***********************************
 * Description: This function prompts
 * the user for an integer, validates
 * the input for positive integers,
 * and then adds it to the Queue.
***********************************/

void add(Queue &newQueue)
{
    int val;

    while (true)
    {
        cout << "Enter an integer: " << endl;
        cin >> val;

        if (val<=0)
	    {
            cout << "Invalid value, please enter again." << endl;
	    }
        else
	    {
            break;
	    }

    }
        newQueue.addBack(val);
}

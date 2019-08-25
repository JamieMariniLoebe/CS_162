/*************************************
 * Program Name: Lab 7
 * Author: Jamie Loebe
 * Date: 11/11/2018
 * Description: This is the source file
 * for Queue.
 *
*************************************/

#include "Queue.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**********************************
* Description: This functions sets
* head to null for an empty list.
**********************************/

Queue::Queue()
{
    head = NULL; // Empty list
}

/***********************************
* Description: This function, when
* true, sets the head to NULL and 
* thus sets the list to empty.
***********************************/

bool Queue::isEmpty()
{
    return head == NULL; // set list to empty
}

/****************************************
* Description: This function checks to 
* see if list is empty, and if it is, it 
* adds a new node to the list. If the list
* is not empty, then it adds the user inputted
* integer into the end of the list.
****************************************/

void Queue::addBack(int val)
{
    if (isEmpty())
    {
        head = new QueueNode;
        head->val = val;
        head->next = head;
        head->prev = head;
    }
    else
    {
        QueueNode *last = head->prev;

        QueueNode *n = new QueueNode;
        n->val = val;
        n->prev = last;
        n->next = head;

        last->next = n;
        head->prev = n;
    }
}

/*****************************************
* Description: This function returns the
* value at the front of the queue.
*****************************************/

int Queue::getFront()
{
    return head->val;
}

/****************************************
* Description: This function iterates
* through if statements and then takes action. 
* If there is no list, then nothing.
* If there is one node, delete that node.
* If the list exists, delete the front node.
****************************************/

void Queue::removeFront()
{

    if(isEmpty())
    {
        return;
    }

    if (head == head->next)
    {
        delete head;
        head = NULL;
    }
    
    else
    {
        QueueNode *temp = head;
        head = head->next;
        head->prev = temp->prev;
        head->prev->next = head;
        delete temp;
    }
}


/*****************************************
* Description: This function traverses the 
* the queue and prints out each node.
*****************************************/

void Queue::printQueue()
{
    if(!isEmpty())
    {
        QueueNode *current = head;
        while (current->next != head)
        {
            cout << current->val << " " << endl;
            current = current->next;
        }

        cout << current->val << endl;
    }
}

/**************************************
* Description: This is the destructor
* which frees the memory from the queue.
**************************************/

Queue::~Queue()
{
    while (!isEmpty())
    {
        removeFront();
    }
}


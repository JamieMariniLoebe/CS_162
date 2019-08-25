/******************************************
 * Program Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/17/2018
 * Description: This is the source file for 
 * LinkedList.
******************************************/

#include "LinkedList.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*****************************
* Description: This function
* sets head to nullptr, and thus
* sets list to empty.
*****************************/

LinkedList::LinkedList() {
    head = NULL;
}

/*****************************
* Description: This function
* checks if list is empty,
* and if it is, it dynamically
* allocates memory for the new 
* node. If not, it just adds a
* new node to the list.
*****************************/

void LinkedList::insertAtHead(Character *c) {
    if(head == NULL) {
        head = new Node(c);
        return;
    }
    Node *temp = new Node(c);
    temp->next = head;
    head = temp;
}

/*****************************
* Description: This function
* checks if list is empty, and
* if so, adds new dynamically
* allocated node. While list
* is not empty, it adds new node.
*****************************/

void LinkedList::insertAtTail(Character *c) {
    if(head == NULL) {
        head = new Node(c);
        return;
    }
    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(c);
}

/*****************************
* Description: This function
* iterates through checks on
* if list is empty, and returns
* accordingly.
*****************************/

Character* LinkedList::getHead() {
    if(head == NULL)
        return NULL;
    if(head->next == NULL) {
        Node *temp = head;
        head = NULL;
        return temp->c;
    }
    Node *temp = head->next;
    Node *ret = head;
    head = temp;
    return ret->c;
}

/******************************
* Description: This funtion
* displays the list while it is
* not empty.
******************************/

void LinkedList::printList() {
    Node *temp = head;
    while(temp != NULL) {
        if(temp->next == NULL) {
            cout << temp->c->getName() << endl;
            temp = temp->next;
        }
        else {
            cout << temp->c->getName() << ", ";
            temp = temp->next;
        }
    }
}


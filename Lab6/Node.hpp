/**********************************************
 * Program Name: Lab 6
 * Author: Jamie Loebe
 * Date: 11/04/2018
 * Description: This is the header file for 
 * Node.
 *
**********************************************/

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

#ifndef NODE_HPP
#define NODE_HPP

// Class with name Node
class Node {

protected:
    // Member variables are declared as protected to be able to access in DLL class
    int val;// Declare an integer to store an integer value
    Node* next;// Declare a pointer to Node class with name next
    Node* prev;// Declare a pointer to Node class with name prev

public:
    Node(int x);// Node class constructor with a parameter as value of Node
    int getVal() const;
    void setVal(int val);
    Node *getNext() const;
    void setNext(Node *next);
    Node *getPrev() const;
    void setPrev(Node *prev);
};

#endif

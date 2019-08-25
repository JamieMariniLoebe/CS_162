/*******************************************
 * Program Name: Lab 6
 * Author: Jamie Loebe
 * Date: 11-04-2018
 * Description: This is the header file for
 * DLL (Doubly linked list).
*******************************************/

#include <iostream>
#include "Node.hpp"
// DLL.hpp

#ifndef DLL_HPP
#define DLL_HPP
class DLL {
private:// Private member variables
    Node* head;// Create a pointer to class Node indicating the head of the doubly linked list
    Node* tail;// Create a pointer to class Node indicating the tail of the doubly linked list
public:// Public member functions
    DLL();// Default constructor
    void addNewNodeToHead(int toAddVal);// Add a node to head of the doubly linked list
    void addNewNodeToTail(int toAddVal);// Add a node to tail of the doubly linked list
    void deleteHeadNode();// Delete a node from head
    void deleteTailNode();// Delete a node from tail
    void traverseListReverse();// Display the list in reverse order
    void traverseList();// Display the list from start to end
};

#endif


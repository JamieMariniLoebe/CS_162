/******************************************
 * Program Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/17/2018
 * Description: This is the header file for
 * LinkedList.
******************************************/


#ifndef LINKEDLIST_hpp
#define LINKEDLIST_hpp

#include <iostream>
#include "Character.hpp"



class LinkedList {
    class Node {
    public:
        Character *c;
        Node *next;
    public:
        Node(Character *c) {
            this->c = c;
            next = NULL;
        }
    };

private:
    Node *head;

public:
    LinkedList();
    void insertAtHead(Character *c);
    void insertAtTail(Character *c);
    Character *getHead();
    void printList();
};


#endif


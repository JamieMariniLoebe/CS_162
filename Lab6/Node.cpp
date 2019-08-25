/******************************
 * Program Name: Lab 6
 * Author: Jamie Loebe
 * Date: 11/04/2018
 * Description: This is the 
 * source file for Node.
******************************/

#include <iostream>
#include "Node.hpp"

Node::Node(int x)
{
    val=x;// Set x as val
    next=NULL;// Set next pointer to current node as null
    prev=NULL;// Set prev pointer to current node as null
}

int Node::getVal() const {
    return val;
}

void Node::setVal(int val) {
    Node::val = val;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

Node *Node::getPrev() const {
    return prev;
}

void Node::setPrev(Node *prev) {
    Node::prev = prev;
}



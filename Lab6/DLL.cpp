/******************************************
 * Program Name: Lab 6
 * Author: Jamie Loebe
 * Date: 11/04/2018
 * Description: This is the source file for 
 * the DLL (doubly linked list) file.
******************************************/

#include <iostream>
#include "DLL.hpp"
#include "Node.hpp"

// DLL.cpp

DLL::DLL()
{
    head=NULL;// Set head node as NULL
    tail=NULL;// Set tail node as NULL indicating empty list
}

/*****************************************
* Description: This function adds an integer
* to the head of the doubly linked list.
*****************************************/
void DLL::addNewNodeToHead(int toAddVal) {
    Node* n=new Node(toAddVal);// Dynamically allocate memory for new node to be added
    if(head==NULL)// If the head node of linked list is empty, then the list is empty
    {
        head=n;// Set 'n' as head node
        tail=n;// Set 'n' as tail node
    }
    else
    {
        head->setPrev(n);// Set 'n' as previous node to head
        n->setNext(head);// Set next node to 'n' as head
        head=n;// Set 'n' as head node
    }
}

/*****************************************
* Description: This function adds an integer
* to the end of the doubly linked list.
*****************************************/
void DLL::addNewNodeToTail(int toAddVal)
{
    Node *n=new Node(toAddVal);// Dynamically allocate memory for new node to be added
    Node *temp=head;// Create a temp node that equals the head node of the linked list
    if(temp==NULL)// Check if temp is 'NULL'
    {
        head=n;// Set 'n' as head node
    }
    else
    {
        while(temp->getNext()!=NULL)// Traverse through the end of the linked list
        {
            temp=temp->getNext();// Point to next node
        }
        temp->setNext(n);// Set 'n' as next node to temp
        n->setPrev(temp);// Set prev node to 'n' as temp
        tail=n;// Set tail to 'n'
    }
}
/*****************************************
* Description: This function deletes a node
* from the start of the doubly linked list.
*****************************************/
void DLL::deleteHeadNode()
{
    Node* tempNode;// Take a node pointer to delete a node
    if(head!=NULL && head->getPrev()==NULL && head->getNext()==NULL)// Check if there is only oneelement in the linked list that is a head
    {
            delete head;// Delete the head node
            head=NULL;// Set head node to null
            tail=NULL;// Set tail node to null
    }
    else if(head!=NULL)// Check if head is not null
    {
        tempNode=head;// Set head as a temp node
        head=head->getNext();// Set next pointer to head node as current head
        head->setPrev(NULL);// Set head node's prev node as null
        delete tempNode;// Delete the tempNode
    }
    else
    {
        cout<<"The list is empty"<<endl; // Output that list is empty
    }
}
/*****************************************
* Description: This function deletes a node
* from the end of the doubly linked list.
*****************************************/
void DLL::deleteTailNode()
{
    Node* delNode;// Take a node pointer indicating the node to be deleted
    Node* tempNode;// Take a node pointer that is a temp node to traverse the linked list
    delNode=head;// Set head to delNode
    if(delNode==NULL)// Check if delnode is null
    {
        cout<<"The list is empty"<<endl;// Output that list is empty
    }
    else if(delNode->getPrev()==NULL && delNode->getNext()==NULL)// Check if head is not null but head's prev and next are null
    {
        delete head;// Delete head
        head=NULL;//make head as null
        tail=NULL;//make tail as null node as well
    }
    else
    {
        while(delNode->getNext()!=NULL)// Traverse through the end of the linked list
        {
            delNode=delNode->getNext();// Move to next node
        }
        tempNode=delNode;// Set delNode as tempNode
        delNode=tempNode->getPrev();// Set temp node's prev pointer to delNode
        delete tempNode;// Delete tempNode
        delNode->setNext(NULL);// Set next pointer to delNode as null
    }
}
/*****************************************
* Description: This function displays the
* doubly linked list in reverse order.
*****************************************/
void DLL::traverseListReverse()
{
    Node* tempNode=tail;// Take a temporary node which points to tail
    while(tempNode!=NULL)// Traverse through the list in reverse order
    {
        cout<<tempNode->getVal()<<"\t";// Display each node's value to screen
        tempNode=tempNode->getPrev();// Point to previous node
    }
}
/*****************************************
* Description: This function displays the
* linked list in order.
*****************************************/
void DLL::traverseList()
{
    Node* tempNode=head;// Take a temporary node which points to head
    while(tempNode!=NULL)// Traverse through the linked list
    {
        cout<<tempNode->getVal()<<"\t";// Display each node's value to screen
        tempNode=tempNode->getNext();// Point to next node
    }
}


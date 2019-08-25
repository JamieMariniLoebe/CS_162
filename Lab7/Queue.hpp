/*********************************************
 * Program Name: Lab 7
 * Author: Jamie Loebe
 * Date: 11/10/2018
 * Description: This is the Queue header file.
*********************************************/

#ifndef Queue_HPP
#define Queue_HPP

class Queue{
protected:
    struct QueueNode{
        int val;
        QueueNode *next;
        QueueNode *prev;
        };
    QueueNode *head;

public:
    Queue(); // Constructor
    bool isEmpty(); // Bool for empty list
    void addBack(int val); // Add node to queue
    int getFront(); // Display first node
    void removeFront(); // Remove first node
    void printQueue(); // Display whole queue
    ~Queue(); // Destructor
};

#endif

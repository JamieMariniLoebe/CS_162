/**************************************
 * Program Name: Final Project
 * Author: Jamie Loebe
 * Date: 11/29/2018
 * Description: This is the header file
 * for Space.
***************************************/


#include <iostream>
#include <string>
#include "Location.hpp"

#ifndef SPACE_HPP
#define SPACE_HPP

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Space {

protected:
    Space *top; // Top pointer
    Space *left; // Left pointer
    Space *right; // Right pointer
    Space *bottom; // Bottom pointer
    Location* location;

public:
    Space(); // Constructor
    void setTop(Space *top);
    void setLeft(Space *left);
    void setRight(Space *right);
    void setBottom(Space *bottom);
    Space *getTop() const;
    Space *getLeft() const;
    Space *getRight() const;
    Space *getBottom() const;
    Location *getLocation() const;
};




#endif

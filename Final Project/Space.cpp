/**************************************
 * Program Name: Final Project
 * Author: Jamie Loebe
 * Date: 11/29/2018
 * Description: This is the source file
 * for Space.
**************************************/

#include "Space.hpp"
#include <string>

using std::string;

/*******************************
 * Description: This constructor 
 * sets each pointer to NULL 
 * and pointers location to
 * getNewLocation function.
*******************************/

Space::Space() {
    top = NULL;
    bottom = NULL;
    left = NULL;
    right = NULL;
    location = location->getNewLocation();
}

/**********************************
 * Description: This function 
 * initializes top.
**********************************/

void Space::setTop(Space *top) {
    Space::top = top;
}

/**********************************
 * Description: This function 
 * initializes left
**********************************/

void Space::setLeft(Space *left) {
    Space::left = left;
}

/**********************************
 * Description: This function 
 * initializes right
**********************************/

void Space::setRight(Space *right) {
    Space::right = right;
}

/**********************************
 * Description: This function 
 * initializes the bottom
**********************************/

void Space::setBottom(Space *bottom) {
    Space::bottom = bottom;
}

/**********************************
 * Description: This function 
 * returns top.
**********************************/

Space *Space::getTop() const {
    return top;
}

/**********************************
 * Description: This function 
 * returns left.
**********************************/

Space *Space::getLeft() const {
    return left;
}

/**********************************
 * Description: This function 
 * returns right.
**********************************/

Space *Space::getRight() const {
    return right;
}

/**********************************
 * Description: This function 
 * returns bottom.
**********************************/

Space *Space::getBottom() const {
    return bottom;
}

/**********************************
 * Description: This function 
 * returns location.
**********************************/

Location *Space::getLocation() const {
    return location;
}


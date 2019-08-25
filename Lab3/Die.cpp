/**********************************
** Program Name: Lab 3
** Author: Jamie Loebe
** Date: 10/10/2018
** Description: This is the source
** file for the Die class.
**********************************/

#include <string>
#include <cstdlib>
#include "Die.hpp"

// Default constructor
Die::Die() {    
    numOfSides = 0;
    dieType = "";
}

Die::Die(int sides) // Constructor.
{
    numOfSides = sides;
    dieType = "Normal";
    std::srand(time(0)); // Random number ge
}

int Die::Roll() // Roll dice, return random number for normal die.
{    
    return (std::rand() % numOfSides) + 1;
}

int Die::getNumOfSides() // Return # of sides of die
{
    return numOfSides;
}

std::string Die::getDieType() // Return type of die
{
    return dieType;
}

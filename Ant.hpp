/*****************************************************
** Program Name: Langton's Ant
** Author: Jamie Loebe
** Date: 10-08-2018
** Description: This is the header file for the Ant 
** source file.
*****************************************************/

#ifndef ANT_hpp
#define ANT_hpp
#include "Board.hpp"
#include <iostream>

class Ant
{

private:
    char direction; // Declare variable for direction
    int xCoord; // Declare xCoord --> AntBoard
    int yCoord; // Declare yCoord --> AntBoard
    int maxSteps;  // Variable to represent current step
    int stepsSoFar; // Variable to represent steps taken
    char colorOfSquareOn; // Variable to represent color of square

public:
    bool makeMove(Board&); // The movement of the ant itself
    Ant(int, int, char, int,Board&); // Constructor
    Ant(char,int, int, int, int, int,Board&); // Default constructor. Takes step & direction.
};

#endif


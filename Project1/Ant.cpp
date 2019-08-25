/****************************************************
** Program Name: Langton's Ant
** Author: Jamie Loebe
** Date: 10-08-2018
** Description: This is the source file for Ant. It
** contains the functions from the Ant header file.
****************************************************/

#include "Ant.hpp"
#include "Board.hpp"
#include <iostream>

/*****************************************************
** Description: This bool function moves the ant on the 
** board. It returns false if the stepsSoFar variable 
** is more or equal to the maxSteps variable, otherwise
** it returns true.. It then sets the direction the
** ant will turn depoending on if the space it is on is
** black or white. It also sets the color of the color
** of the square the ant leaves.
*****************************************************/

 
bool Ant::makeMove(Board &board)
{
    if (stepsSoFar >= maxSteps) // If steps go beyond max, return false.
    {
        return false;
    }
    if (colorOfSquareOn == ' ') // If color of square ant is on is white
    {
        board.setColorOfSquareOnBoard(xCoord,yCoord,'#'); // Set color of square to black
        if (direction == 'W') // If direction faced is W
        {
            direction = 'N'; // Turn N
        }
        else if (direction == 'N') // If direction faced is N
        {
            direction = 'E'; // Turn E
        }
        else if (direction == 'E') // If direction faced is E
        {
            direction = 'S'; // Turn S
        }
        else if (direction == 'S') // If direction faced is S
        {
            direction = 'W'; // Turn W
        }
    }

    else
    {
        board.setColorOfSquareOnBoard(xCoord, yCoord, ' '); // If square ant is on is white
        if (direction == 'W') // If direction faced is W
        {
            direction = 'S'; // Turn S
        }
        else if (direction == 'N') // If direction is N
        {
            direction = 'W'; // Turn W
        }
        else if (direction == 'E') // If direction is E
        {
            direction = 'N'; // Turn N
        }
        else if (direction == 'S') // If direction is S
        {
            direction = 'E'; // Turn E
        }
    }

    if (yCoord == 0 && direction == 'W')
    {
        yCoord = board.getColumns()-1;
    }
    else if (xCoord == 0 && direction == 'N')
    {
        xCoord = board.getRows()-1;
    }
    else if (yCoord == (board.getColumns()-1) && direction == 'E')
    {
        yCoord = 0;
    }
    else if (xCoord == (board.getRows()-1) && direction == 'S')
    {
        xCoord = 0;
    }
    else
    {
        if (direction == 'W')
        {
            yCoord--;
        }
        else if (direction == 'E')
        {
            yCoord++;
        }
        else if (direction == 'N')
        {
            xCoord--;
        }
        else if (direction == 'S')
        {
            xCoord++;
        }
    }
    colorOfSquareOn = board.getColorOfSquareOnBoard(xCoord, yCoord); // Get color of square
    board.setColorOfSquareOnBoard(xCoord, yCoord, '*'); // Set ant on board
    stepsSoFar++; // Increase stepsSoFar
    return true;
}

/***************************************************
** Description: This constructor initializes the 
** stepsSoFar variable to 0, and initializes the variables
** direction of ant and maxSteps that ant can move.
***************************************************/

Ant::Ant(int rows, int columns, char myDirection, int myMaxSteps,Board &board)
{
    stepsSoFar = 0;
    direction = myDirection;
    maxSteps = myMaxSteps;
}

/****************************************************
** Description: This constructor initailizes stepsSoFar
** to 0, and initializes the variables for direction
** of the ant and maxSteps that the ant can move.
** It also sets the nth starting row and column of ant.
** It also updates the colorOfSquareOn variable 
** of the Ant object.
****************************************************/
Ant::Ant(char myDirection, int x, int y, int myMaxSteps, int rows, int columns,Board &board)
{
    stepsSoFar = 0;
    direction = myDirection;
    xCoord = x;
    yCoord = y;
    colorOfSquareOn = board.getColorOfSquareOnBoard(x, y);
    board.setColorOfSquareOnBoard(xCoord, yCoord, '*');
    maxSteps = myMaxSteps;
}



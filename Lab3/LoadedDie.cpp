/***********************************************
** Program Name: Lab 3
** Author: Jamie Loebe
** Date: 10/10/2018
** Description: This is the source file for the 
** LoadedDie file. It contains the functions
** from both the Die and LoadedDie classes through
** inheritance.
***********************************************/

#include <string>
#include <cstdlib>
#include "LoadedDie.hpp"

LoadedDie::LoadedDie()
{
    numOfSides = 0; // Initialize to 0
}

LoadedDie::LoadedDie(int sides)
{
    numOfSides = sides; 
    dieType = "Loaded";
    std::srand(time(0)); // Random number generator
}

int LoadedDie::Roll()
{
    if ((std::rand() % 2 + 1) == 1) // if remainder of rand and 2 + 1 is equal to 1, return.
    {
        return (std::rand() % numOfSides + 1); // Return random number
    }
    else
    {
        return numOfSides; // Return number of sides of die (highest number)
    }
}



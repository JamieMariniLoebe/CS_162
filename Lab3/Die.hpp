#ifndef DIE_HPP
#define DIE_HPP

#include <cstdlib>
#include <ctime>
#include <string>

class Die
{
protected:
    int numOfSides; // Variable for # of sides of die
    std::string dieType; // Loaded or not loaded?
    
public:
    Die(); // Default constructor
    Die(int);// Set default variables
    virtual int Roll();// Function to roll die, return random number from 1-n
    int getNumOfSides(); // Return number of sides
    std::string getDieType(); // Return dieType
};

#endif


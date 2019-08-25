/*****************************************
** Program Name: Lab 3
** Author: Jamie Loebe
** Date: 10/10/2018
** Description: This is the header file for
** the LoadedDie file. It contains the 
** Loaded Die class, and it's public functions
*****************************************/

#ifndef LOADEDDIE_hpp
#define LOADEDDIE_hpp

#include "Die.hpp"
#include <string>

//Use inheritance to pull from Die class

class LoadedDie : public Die
{

public:
    LoadedDie(); // Default constructor
    LoadedDie(int sides); 
    int Roll();

};

#endif




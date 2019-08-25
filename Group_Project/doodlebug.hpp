/*********************************************************************
** Program Name: Group Project
** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
Jordan Sperry
** Date: 10/23/18
** Description: This is the doodlebug.cpp definition file. It differs
from an Ant as there is a variable that keeps track of the starveCount
of the Doodlebug. The Doodlebug inherits steps, x, y, symbol, bredThisTurn,
and movedThisTurn from Critter. Doodlebug also inherits virtual functions
such as move and breed. Doodlebug has it's own function to return if
the Doodlebug is starving if it has not eaten an ant for three steps.
*********************************************************************/

#include "critter.hpp"

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

class Doodlebug : public Critter
{
private:
	int starveCount;

public:
	Doodlebug(int, int);
	virtual void move(Critter***);
	virtual void breed(Critter***);
	bool starve();
};

#endif
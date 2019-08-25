/*********************************************************************
** Program Name: Group Project
** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
Jordan Sperry
** Date: 10/23/18
** Description: This is the ant.cpp implementation file. The Ant inherits
steps, x, y, symbol, bredThisTurn, and movedThisTurn from Critter. Ant
also inherits virtual functions such as move and breed.
*********************************************************************/

#include "critter.hpp"
#include "board.hpp"

#ifndef ANT_HPP
#define ANT_HPP

class Ant : public Critter {
public:
	Ant(int, int); // Create Ant at X, Y position
	virtual void move(Critter***); // Move with param a pointer to array of pointers to arrays that have object pointers
	virtual void breed(Critter***); // Breed with param a pointer to array of pointers to arrays that have object pointers
};

#endif
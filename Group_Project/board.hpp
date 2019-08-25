/*********************************************************************
** Program Name: Group Project
** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
Jordan Sperry
** Date: 10/23/18
** Description: This is the board.cpp definition file. It creates
a Board class with functions to populate, move, breed, starve, display,
delete board, and delete critters off the board.
*********************************************************************/

#include "critter.hpp"

#ifndef BOARD_HPP
#define BOARD_HPP

class Board {
private:
	Critter ***board; // Pointer to array of 2D object pointers
public:
	Board(); // Create board
	~Board(); // Delete objects and board to free memory
	void populate(); // Populate board with Doodlebugs and Ants
	void moveAll(); // Move all Critters
	void breedAll(); // Breed all Critters
	void starve(); // Starve all Doodlebugs
	void display(); // Print out board to console
	void deleteCritter(int, int); // Delete critter at X,Y location
	void resetFlags(); // movedThisTurn = false; bredThisTurn = false
};

#endif
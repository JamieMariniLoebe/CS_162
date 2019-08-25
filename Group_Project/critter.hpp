/*********************************************************************
** Program Name: Group Project
** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
Jordan Sperry
** Date: 10/23/18
** Description: This is the critter.cpp definition file. Critter is a
base class for Ant and Doodlebug. It tracks variables such as steps, x,
y, symbol, bredThisTurn, and movedThisTurn from Critter. Ant also inherits
virtual functions such as move and breed.
*********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter {
protected:
	int steps; // # steps Critter took
	int x; // X-position
	int y; // Y-position
	char symbol; // X for Doodlebug, O for Ant
	bool movedThisTurn; // Did this Critter already move this turn?
	bool bredThisTurn; // Did this Critter already breed this turn?
public:
	Critter(); // Create Critter
	virtual void move(Critter*** board); // Placeholder for Ant and Doodle move
	virtual void breed(Critter*** board); // Placeholder for Ant and Doodle breed

	//get
	int getSteps(); // Get # steps Critter took
	int getX(); // Get X-position
	int getY(); // Get Y-position
	char getSymbol(); // Get char of 'X' or 'O'
	bool getMovedThisTurn(); // True if moved this turn, false if not moved
	bool getBredThisTurn(); // True if bred this turn, false if not moved

	//set
	void setSteps(int); // Set # steps
	void setX(int); // Set X-position
	void setY(int); // Set Y-position
	void setSymbol(char); // Set Critter symbol 'X' or 'O'
	void setMovedThisTurn(bool); // Set if Critter moved this turn
	void setBredThisTurn(bool); // Set if Critter bred this turn
};

#endif
/*********************************************************************
** Program Name: Group Project
** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
Jordan Sperry
** Date: 10/23/18
** Description: This is the critter.cpp definition file. It is the
base class for Ant and Doodlebug. It creates a default constructor of
a Critter. Move and breed functions are undefined as Ant and Doodlebug
have their 
*********************************************************************/

#include "critter.hpp"

/*********************************************************************
** Description: This is the default Critter constructor. Creates a Critter
object with 0 steps, (0,0) location, a placeholder symbol, and if Critter
has moved that turn (false as it has not been moved yet).
*********************************************************************/
Critter::Critter() {
	steps = 0;
	x = 0;
	y = 0;
	symbol = ' ';
	movedThisTurn = false;
	bredThisTurn = false;
}

/*********************************************************************
** Description: Placeholder virtual function for Ant and Doodlebug move
functions. Takes in a pointer to array pointers that point to Critter
pointers. Does not return a value.
*********************************************************************/
void Critter::move(Critter*** board) {

}

/*********************************************************************
** Description: Placeholder virtual function for Ant and Doodlebug breed
functions. Takes in a pointer to array pointers that point to Critter
pointers. Does not return a value.
*********************************************************************/
void Critter::breed(Critter*** board) {

}

/*********************************************************************
** Description: This function gets the number of steps a Critter has
survived for. Does not take in a parameter. Returns the number of steps
as an integer.
*********************************************************************/
int Critter::getSteps() {
	return steps;
}

/*********************************************************************
** Description: This function gets the X-position of the Critter. Does
not take in a parameter. Returns the X-position as an integer.
*********************************************************************/
int Critter::getX() {
	return x;
}

/*********************************************************************
** Description: This function gets the Y-position of the Critter. Does
not take in a parameter. Returns the Y-position as an integer.
*********************************************************************/
int Critter::getY() {
	return y;
}

/*********************************************************************
** Description: This function gets the symbol of the Critter. 'X' for
Doodlebug and 'O' for Ant. Does not take in a parameter. Returns the 
symbol as a character.
*********************************************************************/
char Critter::getSymbol() {
	return symbol;
}

/*********************************************************************
** Description: This function gets whether the Critter has moved this
turn. Does not take in a parameter. Returns true if Critter has moved
this turn. Return false if Critter has not moved this turn.
*********************************************************************/
bool Critter::getMovedThisTurn() {
	return movedThisTurn;
}

/*********************************************************************
** Description: This function gets whether the Critter has bred this
turn. Does not take in a parameter. Returns true if Critter has bred
this turn. Return false if Critter has not bred this turn.
*********************************************************************/
bool Critter::getBredThisTurn() {
	return bredThisTurn;
}

/*********************************************************************
** Description: This function sets the number of steps a Critter takes
using the int that is passed as a parameter and sets this object's steps
variable to that value. Does not return a value.
*********************************************************************/
void Critter::setSteps(int steps) {
	this->steps = steps;
}

/*********************************************************************
** Description: This function sets the X-position of the Critter using
the int that is passed as a parameter and sets this object's x variable
to that value. Does not return a value.
*********************************************************************/
void Critter::setX(int x) {
	this->x = x;
}

/*********************************************************************
** Description: This function sets the Y-position of the Critter using
the int that is passed as a parameter and sets this object's x variable
to that value. Does not return a value.
*********************************************************************/
void Critter::setY(int y) {
	this->y = y;
}

/*********************************************************************
** Description: This function sets the char symbol of the Critter using
the char that is passed as a parameter and sets this object's symbol varible
to that value. Does not return a value.
*********************************************************************/
void Critter::setSymbol(char symbol) {
	this->symbol = symbol;
}

/*********************************************************************
** Description: This function sets if the Critter has moved this turn
using true or false as the parameters. It sets this object's movedThisTurn
variable to the value passed in. Does not return a value.
*********************************************************************/
void Critter::setMovedThisTurn(bool movedThisTurn) {
	this->movedThisTurn = movedThisTurn;
}

/*********************************************************************
** Description: This function sets if the Critter has bred this turn
using true or false as the parameters. It sets this object's bredThisTurn
variable to the value passed in. Does not return a value.
*********************************************************************/
void Critter::setBredThisTurn(bool bredThisTurn) {
	this->bredThisTurn = bredThisTurn;
}
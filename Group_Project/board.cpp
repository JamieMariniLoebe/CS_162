/*********************************************************************
** Program Name: Group Project
** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
Jordan Sperry
** Date: 10/23/18
** Description: This is the board.cpp implementation file. It creates
a Board class with functions to populate, move, breed, starve, display,
delete board, and delete critters off the board.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "board.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

using std::cout;
using std::endl;

/*********************************************************************
** Description: This is the Board constructor. It creates a 2D dynamic
array (20 x 20) of object pointers and sets all of the pointers to NULL
providing a template for the populate() function to assign pointer values.
*********************************************************************/
Board::Board() {
	board = new Critter**[20]; // Create pointer to array

	for (int i = 0; i < 20; i++) { // Create array of pointers
		board[i] = new Critter*[20];
	}

	for (int i = 0; i < 20; i++) { // Set pointers to NULL
		for (int j = 0; j < 20; j++) {
			board[i][j] = NULL;
		}
	}
}

/*********************************************************************
** Description: This destructor will delete the current Board state.
*********************************************************************/
Board::~Board() {
	for (int i = 0; i < 20; i++) { // Loop row
		for (int j = 0; j < 20; j++) { // Loop column
			delete board[i][j]; // Delete each element
		}
		delete[] board[i]; // Delete each array
	}
	delete[] board; // Delete pointer to arrays
	board = NULL; // Set pointer to NULL
}

/*********************************************************************
** Description: This function creates 100 Ants and 5 Doodlebugs in
random locations on the Board. Sets the board[x][y] value to a Critter.
This function does not take parameters and does not return a value.
*********************************************************************/
void Board::populate() {
	int ant = 0; // Ant count
	int doodlebug = 0; // Doodlebug count

	while (ant < 100) { // Loop until 100 Ants are created
		int x = rand() % 20; // Random x location
		int y = rand() % 20; // Random y location
		if (board[x][y] == NULL) { // Trigger if element value is NULL
			board[x][y] = new Ant(x, y); // Set element to an Ant object
			ant++; // Add 1 to Ant counter
		}
	}

	while (doodlebug < 5) { // Loop until 5 Doodlebugs are created
		int x = rand() % 20; // Random x location
		int y = rand() % 20; // Random y location
		if (board[x][y] == NULL) { // Trigger if element value is NULL
			board[x][y] = new Doodlebug(x, y); // Set element to an Ant object
			doodlebug++; // Add 1 to Doodlebug counter
		}
	}
}

/*********************************************************************
** Description: This function moves all Critters if possible where
Doodlebugs move first. This function does not take parameters and does
not return a value.
*********************************************************************/
void Board::moveAll() {
	// Find Doodlebugs and move them
	for (int i = 0; i < 20; i++) { // Loop row
		for (int j = 0; j < 20; j++) { // Loop column
			if (board[i][j] != NULL) {
				if (board[i][j]->getSymbol() == 'X') { // Find Doodlebug
					if (!board[i][j]->getMovedThisTurn()) {
						board[i][j]->move(board); // Move Doodlebug
					}
				}
			}
		}
	}

	// Find Ants and move them
	for (int i = 0; i < 20; i++) { // Loop row
		for (int j = 0; j < 20; j++) { // Loop column
			if (board[i][j] != NULL) { 
				if (board[i][j]->getSymbol() == 'O') { // Find Ant
					if (!board[i][j]->getMovedThisTurn()) {
						board[i][j]->move(board); // Move Ant
					}
				}
			}
		}
	}
}

/*********************************************************************
** Description: This function makes all Critters breed if possible. This
function does not take parameters and does not return a value.
*********************************************************************/
void Board::breedAll() {
	// Find Ants and breed them, if possible
	for (int i = 0; i < 20; i++) { // Loop row
		for (int j = 0; j < 20; j++) { // Loop column
			if (board[i][j] != NULL) {
				if (board[i][j]->getSymbol() == 'O') { // Find Ant
					if (!board[i][j]->getBredThisTurn()) {
						board[i][j]->breed(board); // Breed Ant, if possible
					}
				}
			}
		}
	}

	// Find Doodlebugs and breed them, if possible
	for (int i = 0; i < 20; i++) { // Loop row
		for (int j = 0; j < 20; j++) { // Loop column
			if (board[i][j] != NULL) {
				if (board[i][j]->getSymbol() == 'X') { // Find Doodlebug
					if (!board[i][j]->getBredThisTurn()) {
						board[i][j]->breed(board); // Breed Doodlebug, if possible
					}
				}
			}
		}
	}
}

/*********************************************************************
** Description: This function will kill all Doodlebugs that have not
eaten in 3 steps. This function does not take parameters and does not
return a value.
*********************************************************************/
void Board::starve() {
	// Find Doodlebug and starve them, if possible
	for (int i = 0; i < 20; i++) { // Loop row
		for (int j = 0; j < 20; j++) { // Loop column
			if (board[i][j] != NULL) {
				// Find Doodlebug that is starving
				if (board[i][j]->getSymbol() == 'X') {
					if (static_cast<Doodlebug*>(board[i][j])->starve()) {
						deleteCritter(i, j); // Kill Doodlebug
					}
				}
			}
		}
	}
}

/*********************************************************************
** Description: This function will display the current Board state to
the console. This function does not take parameters and does not return
a value.
*********************************************************************/
void Board::display() {
	cout << "----------------------" << endl;
	for (int i = 0; i < 20; i++) { // Print row
		cout << "|"; // Border
		for (int j = 0; j < 20; j++) { // Print column
			if (board[i][j] == NULL) { // If element is NULL
				cout << " "; // Print blank space
			}
			else if (board[i][j]->getSymbol() == 'X') { // If object is Doodlebug
				cout << "X"; // Print X
			}
			else if (board[i][j]->getSymbol() == 'O') { // If object is Ant
				cout << "O"; // Print O
			}
		}
		cout << "|" << endl; // Border
	}
	cout << "----------------------" << endl;
	cout << endl;
}

/*********************************************************************
** Description: This function will delete the Critter at the marked at
the x,y location passed in by integer parameters of x and y. The value
will then be set to NULL. This function does not return a value.
*********************************************************************/
void Board::deleteCritter(int x, int y) {
	delete board[x][y]; // Delete Critter
	board[x][y] = NULL; // Set element to NULL
}

/*********************************************************************
** Description: This function will reset all bool flags to false such as
movedThisTurn and bredThisTurn. Without this function a Critter may
breed or move multiple times. This function does not take a parameter
and does not return a value.
*********************************************************************/
void Board::resetFlags() {
	for (int i = 0; i < 20; i++) { // Row
		for (int j = 0; j < 20; j++) { // Column
			if (board[i][j] != NULL) { // Make sure space is occupied
				if (board[i][j]->getSymbol() == 'X' || board[i][j]->getSymbol() == 'O') { // Ant or Doodle
					board[i][j]->setMovedThisTurn(false); // Set moved to false
					board[i][j]->setBredThisTurn(false); // Set bred to false
				}
			}
		}
	}
}
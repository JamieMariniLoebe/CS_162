/*********************************************************************
** Program Name: Group Project
** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
Jordan Sperry
** Date: 10/23/18
** Description: This is the doodlebug.cpp implentation file. It differs
from an Ant as there is a variable that keeps track of the starveCount
of the Doodlebug. The Doodlebug inherits steps, x, y, symbol, bredThisTurn,
and movedThisTurn from Critter. Doodlebug also inherits virtual functions
such as move and breed. Doodlebug has it's own function to return if
the Doodlebug is starving if it has not eaten an ant for three steps.
*********************************************************************/

#include <cstdlib>
#include <vector>
#include <algorithm>
#include "doodlebug.hpp"
#include "board.hpp"

using std::vector;
using std::random_shuffle;

/*********************************************************************
** Description: This is the default Doodlebug constructor. Creates a 
Doodlebug object with 0 steps, x,y (given via parameter) location, an
'X' symbol, and if Critter has moved/bred that turn (false as it has not
been moved/bred yet).
*********************************************************************/
Doodlebug::Doodlebug(int x, int y) {
	this->x = x;
	this->y = y;
	symbol = 'X';
	steps = 0;
	starveCount = 0;
	movedThisTurn = false;
	bredThisTurn = false;
}

/*********************************************************************
** Description: This function prioritizes the Doodlebug to a space 
containing an Ant. Otherwise it randomly moves up, down, left, or
right as long as the next position is empty. Takes in a parameter of
a pointer to pointers to arrays that have pointers to Critters. Does not
return a value.
*********************************************************************/
void Doodlebug::move(Critter*** board) {
	int direction = -1; // Non direction

	if (y - 1 >= 0) { // Column cannot be less than 0
		if (board[x][y - 1] != NULL) { // Space is occupied
			if (board[x][y - 1]->getSymbol() == 'O') { // Ant
				direction = 0; // Left
			}
		}
	}
	if ((x - 1 >= 0)) { // Row cannot be less than 0
		if (board[x - 1][y] != NULL) { // Space is occupied
			if (board[x - 1][y]->getSymbol() == 'O') { // Ant
				direction = 1; // Up
			}
		}
	}
	if ((y + 1 <= 19)) { // Column cannot be greater than 19
		if (board[x][y + 1] != NULL) { // Space is occupied
			if (board[x][y + 1]->getSymbol() == 'O') { // Ant
				direction = 2; // Right
			}
		}
	}
	if ((x + 1 <= 19)) { // Row cannot be greater than 19
		if (board[x + 1][y] != NULL) { // Space is occupied
			if (board[x + 1][y]->getSymbol() == 'O') { // Ant
				direction = 3; // Down
			}
		}
	}

	// Look left for Ant
	if (direction == 0) {
		delete board[x][y - 1]; // Delete Ant; free mem
		board[x][y - 1] = this; // New board position points to this Doodle
		board[x][y] = NULL; // Previous board position does not point to Doodle
		y--; // Update position in Doodle
		steps++; // Update steps
		starveCount = 0; // Reset starve count
		movedThisTurn = true; // Already moved so board does not move it again
	}

	// Look up for Ant
	if (direction == 1) {
		delete board[x - 1][y]; // Delete Ant; free mem
		board[x - 1][y] = this; // New board position points to this Doodle
		board[x][y] = NULL; // Previous board position does not point to Doodle
		x--; // Update position in Doodle
		steps++; // Update steps
		starveCount = 0; // Reset starve count
		movedThisTurn = true; // Already moved so board does not move it again
	}

	// Look right for Ant
	if (direction == 2) {
		delete board[x][y + 1]; // Delete Ant; free mem
		board[x][y + 1] = this;  // New board position points to this Doodle
		board[x][y] = NULL; // Previous board position does not point to Doodle
		y++; // Update position in Doodle
		steps++; // Update steps
		starveCount = 0; // Reset starve count
		movedThisTurn = true; // Already moved so board does not move it again
	}
	

	// Look down for Ant
	if (direction == 3) {
		delete board[x + 1][y]; // Delete Ant; free mem
		board[x + 1][y] = this; // New board position points to this Doodle
		board[x][y] = NULL; // Previous board position does not point to Doodle
		x++; // Update position in Doodle
		steps++; // Update steps
		starveCount = 0; // Reset starve count
		movedThisTurn = true; // Already moved so board does not move it again
	}

	// Case where there is no adjacent Ant
	if (direction == -1) {
		direction = rand() % 4;

		if (direction == 0) { // UP
			if (x - 1 != -1) { // Row cannot be less than 0
				if (board[x - 1][y] == NULL) { // If position is empty
					board[x - 1][y] = this; // This board position now points to this Doodle
					board[x][y] = NULL; // Old position does not point to this Doodle
					x--; // Update position in Doodle
					steps++; // Update steps
					starveCount++; // Update starve count
					movedThisTurn = true; // Already moved so board does not move it again
				}
			}
		}
		else if (direction == 1) { // DOWN
			if (x + 1 != 20) {
				if (board[x + 1][y] == NULL) { // If position is empty
					board[x + 1][y] = this; // This board position now points to this Doodle
					board[x][y] = NULL; // Old position does not point to this Doodle
					x++; // Update position in Doodle
					steps++; // Update steps
					starveCount++; // Update starve count
					movedThisTurn = true; // Already moved so board does not move it again
				}
			}
		}
		else if (direction == 2) { // LEFT
			if (y - 1 != -1) {
				if (board[x][y - 1] == NULL) { // If position is empty
					board[x][y - 1] = this; // This board position now points to this Doodle
					board[x][y] = NULL; // Old position does not point to this Doodle
					y--; // Update position in Doodle
					steps++; // Update steps
					starveCount++; // Update starve count
					movedThisTurn = true; // Already moved so board does not move it again
				}
			}
		}
		else if (direction == 3) { // RIGHT
			if (y + 1 != 20) {
				if (board[x][y + 1] == NULL) { // If position is empty
					board[x][y + 1] = this; // This board position now points to this Doodle
					board[x][y] = NULL; // Old position does not point to this Doodle
					y++; // Update position in Doodle
					starveCount++; // Update steps
					steps++; // Update starve count
					movedThisTurn = true; // Already moved so board does not move it again
				}
			}
		}
	}
}

/*********************************************************************
** Description: This function creates a new Doodlebug, simulating when 
a new Doodlebug is born. It checks to see if the Ant is able to breed
(every eight steps). If it is able to breed, find a random EMPTY 
up/down/left/right spot and create a new ant in that position. If Ant
cannot find an empty spot to breed, nothing happens.
*********************************************************************/
void Doodlebug::breed(Critter*** board) {
	if (steps % 8 == 0 && steps != 0) { // Every 8 steps
		vector<int> directionNotOccupied; // Create vector to store empty directions

		if (x - 1 != -1) { // UP
			if (board[x - 1][y] == NULL) { // Make sure position is null
				directionNotOccupied.push_back(0); // Add position
			}
		}

		if (x + 1 != 20) { // DOWN
			if (board[x + 1][y] == NULL) { // Make sure position is null
				directionNotOccupied.push_back(1); // Add position
			}
		}

		if (y - 1 != -1) { // LEFT
			if (board[x][y - 1] == NULL) { // Make sure position is null
				directionNotOccupied.push_back(2); // Add position
			}
		}

		if (y + 1 != 20) { // RIGHT
			if (board[x][y + 1] == NULL) { // Make sure position is null
				directionNotOccupied.push_back(3); // Add position
			}
		}

		if (!directionNotOccupied.empty()) { // Make sure vector has elements

			// Shuffle vector
			random_shuffle(directionNotOccupied.begin(), directionNotOccupied.end());

			int direction = directionNotOccupied[0]; // First element value is direction

			if (direction == 0) { // UP
				if (x - 1 != -1) { // Row cannot be less than 0
					if (board[x - 1][y] == NULL) { // Check if position is empty
						board[x - 1][y] = new Doodlebug(x - 1, y); // Create new Doodle in space
						bredThisTurn = true; // Flag that it has bred this turn
					}
				}
			}
			else if (direction == 1) { // DOWN
				if (x + 1 != 20) { // Row cannot be greater than 19
					if (board[x + 1][y] == NULL) { // Check if position is empty
						board[x + 1][y] = new Doodlebug(x + 1, y); // Create new Doodle in space
						bredThisTurn = true; // Flag that it has bred this turn
					}
				}
			}
			else if (direction == 2) { // LEFT
				if (y - 1 != -1) { // Column cannot be less than 0
					if (board[x][y - 1] == NULL) { // Check if position is empty
						board[x][y - 1] = new Doodlebug(x, y - 1); // Create new Doodle in space
						bredThisTurn = true; // Flag that it has bred this turn
					}
				}
			}
			else if (direction == 3) { // RIGHT
				if (y + 1 != 20) { // Column cannot be greater than 19
					if (board[x][y + 1] == NULL) { // Check if position is empty
						board[x][y + 1] = new Doodlebug(x, y + 1); // Create new Doodle in space
						bredThisTurn = true; // Flag that it has bred this turn
					}
				}
			}
		}
	}
}

/*********************************************************************
** Description: This function returns true if the Doodlebug is starving,
or has had three steps without eating an Ant and returns false if it has
eaten an Ant within the last three steps.
*********************************************************************/
bool Doodlebug::starve() {
	if (starveCount == 3) { // 3 steps without eating Ant
		return true;
	}
	else { // Has eaten an Ant within the last 3 steps
		return false;
	}
}
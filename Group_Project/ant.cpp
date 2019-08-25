/*********************************************************************
** Program Name: Group Project
** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
Jordan Sperry
** Date: 10/23/18
** Description: This is the ant.cpp implementation file. The Ant inherits
steps, x, y, symbol, bredThisTurn, and movedThisTurn from Critter. Ant
also inherits virtual functions such as move and breed.
*********************************************************************/

#include <cstdlib>
#include <vector>
#include <algorithm>
#include "ant.hpp"
#include "board.hpp"

using std::vector;
using std::random_shuffle;

/*********************************************************************
** Description: This is the default Ant constructor. Creates an Ant
object with 0 steps, x,y (given via parameter) location, an 'O' symbol,
and if Critter has moved/bred that turn (false as it has not been moved
/bred yet).
*********************************************************************/
Ant::Ant(int x, int y) {
	this->x = x;
	this->y = y;
	symbol = 'O';
	movedThisTurn = false;
	bredThisTurn = false;
}

/*********************************************************************
** Description: This function moves the Ant randomly up, down, left, or
right as long as the next position is empty. Takes in a parameter of
a pointer to pointers to arrays that have pointers to Critters. Does not
return a value.
*********************************************************************/
void Ant::move(Critter*** board) {
	int direction = rand() % 4; // 0-3

	if (direction == 0) { // UP
		if (x - 1 != -1) { // Row cannot be less than 0
			if (board[x - 1][y] == NULL) { // If position is empty
				board[x - 1][y] = this; // This board position now points to this Ant
				board[x][y] = NULL; // Old position does not point to this Ant
				x--; // Update X-position
				steps++; // Update # steps
				movedThisTurn = true; // Ant has already moved this turn
			}
		}
	}
	else if (direction == 1) { // DOWN
		if (x + 1 != 20) { // Row cannot be greater than 19
			if (board[x + 1][y] == NULL) { // If position is empty
				board[x + 1][y] = this; // This board position now points to this Ant
				board[x][y] = NULL; // Old position does not point to this Ant
				x++; // Update X-position
				steps++; // Update # steps
				movedThisTurn = true; // Ant has already moved this turn
			}
		}
	}
	else if (direction == 2) { // LEFT
		if (y - 1 != -1) { // Column cannot be less than 0
			if (board[x][y - 1] == NULL) { // If position is empty
				board[x][y - 1] = this; // This board position now points to this Ant
				board[x][y] = NULL; // Old position does not point to this Ant
				y--;// Update Y-position
				steps++; // Update # steps
				movedThisTurn = true; // Ant has already moved this turn
			}
		}
	}
	else if (direction == 3) { // RIGHT
		if (y + 1 != 20) { // Column cannot be greater than 19
			if (board[x][y + 1] == NULL) { // If position is empty
				board[x][y + 1] = this; // This board position now points to this Ant
				board[x][y] = NULL; // Old position does not point to this Ant
				y++; // Update Y-position
				steps++; // Update # steps
				movedThisTurn = true; // Ant has already moved this turn
			}
		}
	}
}

/*********************************************************************
** Description: This function creates a new Ant, simulating when a new
Ant is born. It checks to see if the Ant is able to breed (every three
steps). If it is able to breed, find a random EMPTY up/down/left/right
spot and create a new ant in that position. If Ant cannot find an empty
spot to breed, nothing happens.
*********************************************************************/
void Ant::breed(Critter*** board) {
	if (steps % 3 == 0 && steps != 0) { // Ant able to breed? Ant breeds in 3 steps
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

			int direction = directionNotOccupied[0]; // Create new Ant in this direction

			if (direction == 0) { // UP
				if (x - 1 != -1) { // Row cannot be less than 0
					if (board[x - 1][y] == NULL) { // Check if position is empty
						board[x - 1][y] = new Ant(x - 1, y); // Create new Ant in space
						bredThisTurn = true; // Flag that it has bred this turn
					}
				}
			}
			else if (direction == 1) { // DOWN
				if (x + 1 != 20) { // Row cannot be greater than 19
					if (board[x + 1][y] == NULL) { // Check if position is empty
						board[x + 1][y] = new Ant(x + 1, y); // Create new Ant in space
						bredThisTurn = true; // Flag that it has bred this turn
					}
				}
			}
			else if (direction == 2) { // LEFT
				if (y - 1 != -1) { // Column cannot be less than 0
					if (board[x][y - 1] == NULL) { // Check if position is empty
						board[x][y - 1] = new Ant(x, y - 1); // Create new Ant in space
						bredThisTurn = true; // Flag that it has bred this turn
					}
				}
			}
			else if (direction == 3) { // RIGHT
				if (y + 1 != 20) { // Column cannot be greater than 19
					if (board[x][y + 1] == NULL) { // Check if position is empty
						board[x][y + 1] = new Ant(x, y + 1); // Create new Ant in space
						bredThisTurn = true; // Flag that it has bred this turn
					}
				}
			}
		}
	}
}
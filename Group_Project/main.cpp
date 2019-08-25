/*********************************************************************
** Program Name: Group Project
** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
Jordan Sperry
** Date: 10/23/18
** Description: This is a simulation program for a Predator-Prey Game.
It asks the user to input the number of steps they would like to proceed
with and then prints out the board of Ants and Doodlebugs for each step.
For each step Ants and Doodlebugs will move, breed, and Doodlebugs starve.
It will then display the board to the user and reset flags for if an
Ant or Doodlebug has moved or bred during the turn. After all the steps
have been reached it will ask the user to run steps again or exit. If
the user chooses to run more steps it will ask the user for the number of
steps.
*********************************************************************/

#include "menu.hpp"

int main() {
	mainMenu();
	return 0;
}
/*********************************************************************
 ** Program Name: Group Project
 ** Author: Kimberly Cu, Brandon Goza, Matthew Harbinson, Jamie Loebe,
 Jordan Sperry
 ** Date: 10/23/18
 ** Description: Menu implementation file for Group Project. Will prompt
 user for number of steps of Critter simulation and then ask user to
 continue simulation, play again, or quit.
 *********************************************************************/

#include "board.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
#include "menu.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*********************************************************************
** Description: This function runs the menu, creates the board, triggers
each step of the board (move, breed, starve, display, reset flags). User
will be asked for the number of steps they would like to run. The board
will display on the console after moves for each step have been completed.
Once the board reaches the time step, the user can play again or quit. If
the user wants to play again, it asks the user for an amount of steps to
continue from where the board left off.
*********************************************************************/
void mainMenu()
{

	cout << "Welcome to the Predator-Prey Game!" << endl << endl;

	cout << "This is a simulation of a board of Ants and Doodlebugs." << endl << endl;

	cout << "Please enter the number of steps you would like to start with for the simulation." << endl;

	cout << "You may enter up to 10000 steps." << endl << endl;

	int numSteps;

	cin >> numSteps;

	if (((numSteps < 1) || (numSteps > 10000) || cin.fail() || cin.get() != '\n'))
	{
		do
		{
			cout << "That is not a valid menu option. Please enter an integer between 1 and 10000." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> numSteps;
		} while (((numSteps < 1) || (numSteps > 10000)) || cin.fail() || cin.get() != '\n');
	}

	Board sim;

	sim.populate();

	sim.display();

	int totalLoops = 1;

	for (int i = 0; i < numSteps; i++)
	{
		cout << "Step " << totalLoops << endl;
		sim.moveAll();
		sim.breedAll();
		sim.starve();
		sim.display();
		sim.resetFlags();

		totalLoops++;
	}

	cout << "Enter 1 to run simulation another number of steps." << endl;
	cout << "Enter 2 to stop the simulation." << endl;

	int runSim;

	cin >> runSim;

	if ((runSim < 1) || (runSim > 2) || cin.fail() || cin.get() != '\n')
	{
		do
		{
			cout << "That is not a valid menu option. Please enter integer 1 or 2." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> runSim;
		} while ((runSim < 1) || (runSim > 2) || cin.fail() || cin.get() != '\n');
	}

	if (runSim == 1)
	{
		do
		{
			cout << "Please enter how many more steps you'd like to run for the simulation." << endl;

			int numSteps;

			cin >> numSteps;

			if (((numSteps < 1) || (numSteps > 10000) || cin.fail() || cin.get() != '\n'))
			{
				do
				{
					cout << "That is not a valid menu option. Please enter an integer between 1 and 10000." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> numSteps;
				} while (((numSteps < 1) || (numSteps > 10000)) || cin.fail() || cin.get() != '\n');
			}

			for (int i = 0; i < numSteps; i++)
			{
				cout << "Step " << totalLoops << endl;
				sim.moveAll();
				sim.breedAll();

				sim.starve();
				sim.display();
				sim.resetFlags();

				totalLoops++;
			}

			cout << "Would you like to continue the simulation?" << endl;

			cout << "If so, press 1 to continue." << endl;
			cout << "Press 2 to quit." << endl;

			cin >> runSim;

			if ((runSim < 1) || (runSim > 2) || cin.fail() || cin.get() != '\n')
			{
				do
				{
					cout << "That is not a valid menu option. Please enter integer 1 or 2." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> runSim;
				} while ((runSim < 1) || (runSim > 2) || cin.fail() || cin.get() != '\n');
			}

		} while (runSim == 1);



		if (runSim == 2)
		{
			cout << "You have ended this simulation." << endl;

			playAgainMenu();

			return;
		}

		return;
	}
}

/*********************************************************************
** Description: This function runs the menu after it has been ran once.
It gives the user an option to continue or to quit. If the user continues
the simulation it will ask for the user to run a new simulation or quit.
If the user picks a new sim a new board is created and runs the program
to time steps.
*********************************************************************/
void playAgainMenu()
{
	cout << endl;
	cout << "Enter 1 to run a new simulation." << endl;
	cout << "Enter 2 to quit the program." << endl;

	int userOption;

	cin >> userOption;

	if ((userOption < 1) || (userOption > 2) || cin.fail() || cin.get() != '\n')
	{
		do
		{
			cout << "That is not a valid menu option. Please enter integer 1 or 2." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> userOption;
		} while ((userOption < 1) || (userOption > 2) || cin.fail() || cin.get() != '\n');
	}

	if (userOption == 1)
	{
		mainMenu();
		return;
	}

	else if (userOption == 2)
	{
		cout << endl;
		cout << "You have chosen to quit the program. Goodbye!" << endl;
		return;
	}

	return;
}
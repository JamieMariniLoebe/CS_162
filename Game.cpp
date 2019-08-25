/*****************************************************
** Program Name: Lab 3
** Author: Jamie Loebe
** Date: 10/10/2018
** Description: This is the source file for the Game 
** file. It contains the functions from the Game class
******************************************************/

#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


/****************************************************
** Description: This is the default constructor.
** It initializes p1, p2 to NULL and numOfRounds to 0.
*****************************************************/

Game::Game() 
{
    p1 = p2 = NULL;
    numOfRounds = 0;
}


/****************************************************
** Description: This function sets numOfRounds to 
** the number of rounds the user input by using the
** this pointer.
****************************************************/


void Game::setRounds(int numOfRound)
{
    this->numOfRounds = numOfRounds;
}

/*****************************************************
** Description: This function displays the menu and 
** asks the user to input their choices for the type of
** die, # of sides of die and number of rounds. It then
** dynamically allocates memory depending on whether
** user chose a LoadedDie or normal die. If user chooses
** to exit game, the program termiantes.
*****************************************************/
void Game::display_Menu()
{
    int beginGame;
    int numOfSides;
    int func_numOfRounds;
    std::string typeOfDie;

    cout << "Welcome to Jamie's Dice playing game." << endl;
    cout << "Please follow the prompts below to begin." << endl;
    cout << "Please type '1' to play the game, or '2' to exit." << endl;
    cin >> beginGame;

    if (beginGame == 1)
    {
        cout << "Wonderful! Let's begin." << endl;

        cout << "Player 1, do you want a loaded die? Please answer 'Yes' or 'No'" << endl;
        cin >> typeOfDie;

        cout << "Player 1, how many sides on your die?" << endl;
        cin >> numOfSides;

        if(typeOfDie.compare("Yes") == 0 || typeOfDie.compare ("yes") == 0)
        {
            p1 = new LoadedDie(numOfSides);
        }

        else
        {
            p1 = new Die(numOfSides);
        }

        cout << "Player 2, do you want a loaded die? Please answer 'Yes' or 'No'" << endl;
        cin >> typeOfDie;

        cout << "Player 2, how many sides on your die?" << endl;
        cin >> numOfSides;

        if (typeOfDie.compare("Yes") == 0 || typeOfDie.compare("yes") == 0)
        {
            p2 = new LoadedDie(numOfSides);
        }

        else 
        {
            p2 = new Die(numOfSides);
        }

        cout << "How many rounds would you like to play?" << endl;
        cin >> numOfRounds;
        setRounds(numOfRounds);
     }

     else
     {
        cout << "Terminating....";
     }

}

/*******************************************
** Description: This function begins the game
** and rolls the dice for each player.
*******************************************/
void Game::play_Game()
{
    for (int i=0; i < numOfRounds; i++)
    {
        rounds[i][0] = p1->Roll();
        rounds[i][1] = p2->Roll();
    }
}

/********************************************
** Description: This function displays the results
** of each round, and at the end of the game. 
** Ir also tallies the points after each round
** for whichever player won, and displays whether
** the round was a win, loss or draw.
********************************************/

void Game::game_Results()
{
    int points1 = 0, points2 = 0;

    cout << "Rounds played: " << numOfRounds << endl;
    cout << "Player 1 uses " << p1->getDieType() << " die with " << p1->getNumOfSides() << " sides." << endl;
    cout << "Player 2 uses " << p2->getDieType() << " die with " << p2->getNumOfSides() << " sides." << endl;

    for (int i=0; i < numOfRounds; i++)
    {
        cout << endl << "Round: " << (i+1) << endl;
        cout << "Player 1: " << rounds[i][0] << " Player 2: " << rounds[i][1] << endl <<endl;

        if (rounds[i][0] > rounds [i][1])
        {
            points1++;
        }

        else if (rounds[i][0] < rounds [i][1])
        {
            points2++;
        }

        cout << "Player 1 wins " << points1 << " times" << endl;
        cout << "Player 2 wins " << points2 << " times" << endl;

        if (rounds[i][0] > rounds[i][1])
        {
            cout << "Player 1 wins!" << endl;
        }

        else if (rounds[i][0] < rounds[i][1])
        {
            cout << "Player 2 wins!" << endl;
        }
        
        else 
        {
            cout << "It is a draw!" << endl;
        }

    }

    delete [] p1;
    delete [] p2;

}



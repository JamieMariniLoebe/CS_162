/*****************************************
** Program Name: Lab 3
** Author: Jamie Loebe
** Date: 10/10/2018
** Description: This is the main file for
** the Lab 3 program.
*****************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{

    Game beginGame;

    beginGame.display_Menu();
    beginGame.play_Game();
    beginGame.game_Results();
    return 0;
}


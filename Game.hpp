/***************************************************
** Program Name: Lab 3
** Author: Jamie Loebe
** Date: 10-10-2018
** Description: This is the header file for the 
** Game file. It contains the variables and functions
** of the Game class.
***************************************************/

#ifndef GAME_hpp
#define GAME_hpp

#include <string>
#include "Die.hpp"

class Game
{
private:
    int numOfRounds;
    Die *p1, *p2; // player 1, player 2
    int rounds[50][2]; // Max 50 rounds, 2 players

public:
    Game();
    void setRounds(int numOfRounds);
    void display_Menu();
    void play_Game();
    void game_Results();
};

#endif



/*************************************
 * Program Name: Final Project
 * Author: Jamie Loebe
 * Date: 12/01/2018
 * Description: This is the header file
 * for Game.
*************************************/


#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include "Player.hpp"

#define SIZE 10

class Game {

protected:
    Space* start;
    Space* end;
    Space* current;
    Player* player;

public:
    Game(Player *player);
    void printMap();
    bool isWon();
    bool isLost();
    void displayHealth();
    void displayItems();
    void makeMove(int c);
};

#endif

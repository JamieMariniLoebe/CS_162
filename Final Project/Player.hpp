/**************************************
 * Program Name: Final Project
 * Author: Jamie Loebe
 * Date: 11/29/2018
 * Description: This is the header file
 * for Player.
***************************************/

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player {

protected:
    int capacity;
    string *container;
    string name;
    int health;
    int noOfItems;

public:
    Player(const string &name);
    string *getContainer() const;
    const string &getName() const;
    int getHealth() const;
    int getNoOfItems() const;
    bool addItem(string item);
    bool isKeyAvailable(string key);
    void setHealth(int health);
};


#endif

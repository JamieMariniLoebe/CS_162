/*****************************************
 * Program Name: Final Project
 * Author: Jamie Loebe
 * Date: 12/01/2018
 * Description: This is the source file
 * for Player.
*****************************************/

#include "Player.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/************************************
 * Description: This is a constructor,
 * and it initializes the variables in
 * Player.
************************************/

Player::Player(const string &name) : name(name) {
    capacity = 15;
    container = new string[capacity];
    health = 25;
    noOfItems = 0;
}

/*****************************************
 * Description: This function gets and 
 * returns the container.
*****************************************/

string *Player::getContainer() const {
    return container;
}

/*****************************************
 * Description: This function gets and returns
 * the variable name.
*****************************************/

const string &Player::getName() const {
    return name;
}

/*****************************************
 * Description: This function gets and returns
 * the player's health.
*****************************************/

int Player::getHealth() const {
    return health;
}

/*****************************************
 * Description: This function gets and returns
 * the number of items.
*****************************************/

int Player::getNoOfItems() const {
    return noOfItems;
}

/*****************************************
 * Description: This function initializes
 * the variable health.
*****************************************/

void Player::setHealth(int health) {
    Player::health = health;
}

/*****************************************
 * Description: This function checks if there
 * is capacity to add an item.
*****************************************/

bool Player::addItem(string item) {
    if(noOfItems < capacity){
        container[noOfItems]=item;
        noOfItems++;
        return true;
    }
    else{
        return false;
    }
}

/*****************************************
 * Description: This function checks if 
 * there is a key in the player's container. 
*****************************************/

bool Player::isKeyAvailable(string key) {
    for (int i = 0; i < noOfItems ; ++i) {
        if(key==container[i]){
            return true;
        }
    }
    return false;
}


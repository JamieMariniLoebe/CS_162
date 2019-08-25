/***************************************
* Program Name: Project 4
* Author: Jamie Loebe
* Date: 11/15/2018
* Description: This is the header file
* for Barbarian.
***************************************/

#ifndef Barbarian_hpp
#define Barbarian_hpp

#include "Character.hpp"
#include <stdio.h>

class Barbarian : public Character{

public:
    int attack(); // Attack function
    int attack_roll(); // Dice roll attack
    void defend(int attacker_roll); // Defend function
    int defend_roll(); // Dice roll defend
    int getArmor(); // Get armor info
    int getStrength(); // Get strength info

    void setInfo(); // Set Barbarian info
    std::string getName(); // Get character name
    bool isDead(); // Check if character dead
    ~Barbarian(); // Barbarian deconstructor
};


#endif


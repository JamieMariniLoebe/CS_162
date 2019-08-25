/****************************
 * Program Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/16/2018
 * Description: This is the
 * header file for vampire.
****************************/

#ifndef Vampire_hpp
#define Vampire_hpp

#include "Character.hpp"
#include <string>

using std::string;


class Vampire:public Character{

protected:
    int charm; // Special vampire ability

public:
    void setInfo(); // Set vampire info
    int attack(); // Attack function
    int attack_roll(); // Dice roll attack
    void defend(int attacker_roll); // Defend function
    int defend_roll(); // Dice roll defend
    bool isDead(); // Check if vampire dead
    string getName(); // Get character name
    int getArmor(); // Get vampire armor info
    int getStrength(); // Get vampire strength info
    ~Vampire(); // Vampire deconstructor
};

#endif




/****************************************
 * Program Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/16/2018
 * Description: This is the header file
 * for Medusa.
****************************************/

#ifndef Medusa_hpp
#define Medusa_hpp

#include "Character.hpp"

class Medusa:public Character{
protected:
    int Glare_stone(); // Special ability.

public: 
    void setInfo(); // Set character info
    int attack(); // Attack function
    int attack_roll(); // Dice roll attack
    void defend(int attacker_roll); // Defend function
    int defend_roll(); // Dice roll defend
    std::string getName(); // Get character name
    int getArmor(); // Get character armor
    int getStrength(); // Get character strength
    bool isDead(); // Check if character is dead
    ~Medusa(); // Medusa deconstructor

};

#endif

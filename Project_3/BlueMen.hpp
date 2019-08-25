/***************************************
 * Program Name: Fantasy Combat Game
 * Author: Jamie Loebe
 * Date: 10/31/2018
 * Description: This is the header file
 * for BlueMen.
**************************************/

#ifndef BlueMen_hpp
#define BlueMen_hpp

#include "Character.hpp"
#include <iostream>

class BlueMen : public Character{
protected:
    int mob_swarm(); // Special ability, lose die

public:
    int attack(); // Attack function
    int attack_roll(); // Dice roll attack
    void defend(int attacker_roll); // Defend function
    int defend_roll(); // Dice roll defend
    int getArmor(); // Get armor
    int getStrength(); // Get strength

    void setInfo(); // Set bluemen info
    string getName(); // Get name
    bool isDead(); // Check if character dead
    ~BlueMen(); // Deconstructor
};



#endif /* BlueMen_hpp */


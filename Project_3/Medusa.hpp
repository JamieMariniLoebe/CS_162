/***********************************************
 * Program Name: Fantasy Combat Game
 * Author: Jamie Loebe
 * Date: 11-01-2018
 * Description: This is the Medusa header file.
***********************************************/

#ifndef Medusa_hpp
#define Medusa_hpp

#include "Character.hpp"

class Medusa:public Character{
protected:
    int Glare_stone(); // Special ability.

public:
    void setInfo(); // Set default Medusa info
    int attack(); // Medusa attack
    int attack_roll(); // Random die roll
    void defend(int attacker_roll); // Medusa defend
    int defend_roll(); // Random die roll
    string getName(); // Get Medusa name
    int getArmor(); // Get armor
    int getStrength(); // Get strength
    bool isDead(); // Check if dead
    ~Medusa(); // Medusa deconstructor

};

#endif

/***************************************
* Program Name: Fantasy Combat Game 
* Author: Jamie Loebe
* Date: 11/01/2018
* Description: This is the header file
* for Harry Potter.
***************************************/

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include "Character.hpp"

class HarryPotter:public Character{
protected:
    int Hogwarts(); // Special ability to restore strength

public:
    void setInfo();
    int attack();
    int attack_roll();
    void defend(int attacker_roll);
    int defend_roll();
    bool isDead();
    string getName();
    int getArmor();
    int getStrength();
    ~HarryPotter();

};

#endif


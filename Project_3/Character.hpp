/********************************************************
 * Program Name: Fantasy Combat Game
 * Author: Jamie Loebe
 * Date: 10/28/2018
 * Description: This is the header file for Character.
********************************************************/

#ifndef Character_hpp
#define Character_hpp

#include <string>

using std::string;


class Character{

protected:
    bool dead;
    string name;
    int armor;
    int strength;
    int mob;
    int glare;
    int hogwarts;

public:
    virtual int attack(); // Attack function
    virtual int attack_roll(); // Dice roll attack
    virtual void defend(int d); // Defend function
    virtual int defend_roll(); // Dice roll defend
    virtual int getArmor(); // Get character armor info
    virtual int getStrength(); // Get character strength info

    virtual void setInfo(); // Set character info
    virtual string getName(); // Get character name
    virtual bool isDead(); // Check if character dead
    virtual ~Character();
};

#endif



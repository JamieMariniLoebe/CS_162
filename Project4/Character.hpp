/**************************************
 * Program Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/15/2018
 * Description: This is the header file
 * for the character file.
**************************************/

#ifndef Character_hpp
#define Character_hpp

#include <string>

class Character{

protected:
    bool dead;
    std::string name;
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
    virtual int getArmor(); // Get character armor
    virtual int getStrength(); // Get character strength

    virtual void setInfo(); // Set character info
    virtual std::string getName(); // Get character name
    virtual bool isDead(); // Check if character dead
    virtual ~Character();

    void recovery();

    void setName(const std::string &name);
};

#endif



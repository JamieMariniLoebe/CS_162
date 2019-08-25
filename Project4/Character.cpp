/******************************************
 * Program Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/15/2018
 * Description: This is the source file for 
 * Character
******************************************/

#include "Character.hpp"

#include <cstdlib>

Character::~Character()
{
}

int Character::attack()
{
    return 0;
}

void Character::defend(int d)
{
}

int Character::defend_roll()
{
    return 0;
}

int Character::attack_roll()
{
    return 0;
}

int Character::getStrength()
{
    return 0;
}

int Character::getArmor()
{
    return 0;
}

void Character::setInfo()
{
}

bool Character::isDead()
{
    return false;
}

std::string Character::getName()
{
    return "";
}

void Character::recovery()
{
    int die = rand() % 5+1;
    strength = 0.01 * die * strength;
}

void Character::setName(const std::string &name)
{
    Character::name = name;
}



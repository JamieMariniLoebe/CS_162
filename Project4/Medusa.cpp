/************************************
 * Project Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/16/2018
 * Description: This is source file for
 * Medusa.
************************************/

#include "Medusa.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

/*********************************
* Description: This function sets
* the specifics of the character,
* randomly seeds the number generator
* and sets dead to false.
*********************************/

void Medusa::setInfo() {
    name = "Medusa";
    armor = 3;
    strength = 8;
    dead = false;
    srand(time(NULL));
    glare = 1;
}

/*********************************
* Description: This function returns
* the damage inflicted by Medusa,
* and outputs the points generated.
*********************************/

int Medusa::attack() {
    int damage = attack_roll();
    cout << "Medusa attacked and generated " << damage << " attack points!!" << endl;
    return damage;
}

/*********************************
* Description: This function returns
* the roll of the die, and randomly
* generates the the die rolls. It 
* also checks for glare and sets
* roll accordingly.
*********************************/

int Medusa::attack_roll() {
    int roll = rand() % 6 + 1;
    roll = roll + (rand() % 6 + 1);
    if(glare==1 && roll == 12){
        glare = 0;
        roll = 999;
    }
    return roll;
}

/*********************************
* Description: This function randomly
* generates the roll of the die and
* returns roll.
*********************************/

int Medusa::defend_roll() {
    int roll = rand() % 6 + 1;
    return roll;
}

/*********************************
* Description: This function iterates
* through if, else-if statements and
* checks what the damage from the 
* attacker was. Depending on the 
* damage from attacker, it outputs
* specific Medusa info, and udpates
* armor and strength. 
*********************************/

void Medusa::defend(int attacker_roll) {
    int defender_roll = defend_roll();

    if(attacker_roll < 999){
        cout << "Medusa defended and Medusa generated " << defender_roll << " defend points!!" << endl;
    }
    int damage;
    damage = attacker_roll - defender_roll;

    if (damage <= 0) {
        cout << "Medusa defends attack! Armor and strength remain the same." << endl;
        cout << "Medusa armor remains at " << armor << endl;
        cout << "Medusa strength remains at " << strength << endl;
    }
    else if (damage <= armor) {
        armor = armor - damage;
        cout << "Medusa armor absorbed the attack!" << endl;
        cout << "Medusa armor remains at " << armor << endl;
        cout << "Medusa strength remains at " << strength << endl;
    }
    else if(damage >= 999 ){
        cout << "Oh no! Medusa has died!" << endl;
        cout << "Armor points: 0" << endl;
        cout << "Strength points: 0" << endl;
        armor = 0;
        strength = 0;
        dead = true;
    }
    else if(damage > armor){
        damage = damage - armor;
        strength = strength - damage;
        armor = 0;
        cout << "Medusa defend attack but lose armor!" << endl;
        cout << "Medusa armor remains at " << armor << endl;
        cout << "Medusa strength remains at " << strength << endl;
    }

    if(strength<=0 ){
        dead = true;
    }
}

/*********************************
* Description: This function returns
* the name of the character
*********************************/

std::string Medusa::getName() {
    return name;
}

/*********************************
* Description: This function returns
* the armor of the character
*********************************/

int Medusa::getArmor() {
    return armor;
}

/*********************************
* Description: This function returns
* the strength of the character
*********************************/

int Medusa::getStrength() {
    return strength;
}

/*********************************
* Description: This function returns
* dead, which checks if character
* is dead or not.
*********************************/

bool Medusa::isDead() {
    return dead;
}

/*********************************
* Description: This is the deconstructor.
*********************************/

Medusa::~Medusa() {

}


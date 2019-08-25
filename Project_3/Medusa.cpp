/*******************************************************
 * Program Name: Fantasy Combat Game
 * Author: Jamie Loebe
 * Date: 11-01-2018
 * Description: This is the source file for Medusa.
*******************************************************/

#include "Medusa.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

/*************************************
* Description: This function sets default
* values for private member variables.
* Also seeds random number generator.
**************************************/

void Medusa::setInfo() { // Default Medusa values
    name = "Medusa";
    armor = 3;
    strength = 8;
    dead = false;
    srand(time(NULL)); // Seed random number
    glare = 1; 
}

/*************************************
* Description: This function sets int 
* variable damage to attack die roll. 
* Outputs attack points, returns damage.
***************************************/

int Medusa::attack() {
    int damage = attack_roll(); // Set damage to attack die roll
    cout << "Medusa attacked and generated " << damage << " attack points!!" << endl;
    return damage;
}

/*************************************
* Description: This function calculates
* die roll of 2 six-sided die. Checks if
* Medusa will use glare also.
**************************************/

int Medusa::attack_roll() {
    int roll = rand() % 6 + 1; // Roll die
    roll = roll + (rand() % 6 + 1);
    if(glare==1 && roll == 12){ // Use glare on enemy
        glare = 0;
        roll = 999; // Max damage from glare
    }
    return roll;
}

/*************************************
* Description: This function calculates
* die roll for defend.
**************************************/

int Medusa::defend_roll() {
    int roll = rand() % 6 + 1; // Random die roll
    return roll;
}

/*************************************
* Description: This function iterates
* through if-statements and outputs
* accordingly what happened to Medusa.
* Also updates armor, strength or death.
************************************/

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
        cout << "Medusa defends attack but loses armor!" << endl;
        cout << "Medusa armor remains at " << armor << endl;
        cout << "Medusa strength remains at " << strength << endl;
    }

    if(strength<=0 ){
        dead = true;
    }
}

/*************************************
* Description: This function returns 
* Vampire name.
**************************************/

string Medusa::getName() {
    return name;
}

/*************************************
* Description: This function returns 
* Vampire armor.
**************************************/

int Medusa::getArmor() {
    return armor;
}

/*************************************
* Description: This function returns 
* Vampire strength.
**************************************/

int Medusa::getStrength() {
    return strength;
}

/*************************************
* Description: This function returns 
* whether Vampire is dead or not.
**************************************/

bool Medusa::isDead() {
    return dead;
}

/*************************************
* Description: This is the Vampire
* deconstructor.
**************************************/

Medusa::~Medusa() {

}


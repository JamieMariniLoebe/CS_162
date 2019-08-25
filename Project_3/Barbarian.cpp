/******************************************************
 * Program Name: Fantasy Combat Game
 * Author: Jamie Loebe
 * Date: 10/31/2018
 * Description: This is the source file for Barbarian.
*****************************************************/

#include "Barbarian.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>


using std::cout;
using std::cin;
using std::endl;

/*************************************
* Description: This function sets
* default values for Barbarian
* private member variables and also
* seeds the random number generator.
************************************/

void Barbarian::setInfo() { // Set default values for Barbarian
    name = "Barbarian";
    armor = 0;
    strength = 12;
    dead = false; 
    srand(time(NULL)); // Seed random number
}

/*************************************
* Description: This function outputs 
* that Barbarian attacked and how much
* points it generated. It also returns
* the die rolled for damage.
************************************/

int Barbarian::attack() {
    int damage = attack_roll();
    cout << "Barbarian attacked and generated " << damage << " attack points!!" << endl;
    return damage;
}

/*************************************
* Description: This function sets a 
* new int variable 'roll' to hold the
* random number that is the die roll.
* Sets it again as Barbarian roll 2 
* die of 6 sides each for attacking.
*************************************/

int Barbarian::attack_roll() {
    int roll = rand() % 6 + 1;
    roll = roll + (rand() % 6 + 1);
    return roll;
}

/*************************************
* Description: This function sets a new
* int variable, 'roll', to hold the 
* random number that is the die roll.
* Sets it again as Barbarian roll 2 die
* of 6 sides each for defending.
*************************************/

int Barbarian::defend_roll() {
    int roll = rand() % 6 + 1;
    roll = roll + (rand() % 6 + 1);
    return roll;
}

/*************************************
* Description: This function works
* through different if-statements
* depending on attack damage, and 
* outputs accordingly.
*************************************/


void Barbarian::defend(int attacker_roll) {
    int defender_roll = defend_roll();

    if(attacker_roll < 999){
        cout << "Barbarian defended and Barbarian generated " << defender_roll << " defend points!!" << endl;
    }
    int damage;
    damage = attacker_roll - defender_roll;

    if (damage <= 0) {
        cout << "Barbarian defends attack! Armor and strength remain the same." << endl;
        cout << "Barbarian armor remains at " << armor << endl;
        cout << "Barbarian strength remains at " << strength << endl;
    }
    else if (damage <= armor) {
        armor = armor - damage;
        cout << "Barbarian armor remains at " << armor << endl;
        cout << "Barbarian strength remains at " << strength << endl;
    }
    else if(damage >= 999 ){
        cout << "Oh no! Barbarian has died!" << endl;
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
        cout << "Barbarian armor remains at " << armor << endl;
        cout << "Barbarian strength remains at " << strength << endl;
    }
    if(strength<=0 ){
        dead = true;
    }
}

/*************************************
* Description: This function returns
* the 'Barbarian' name.
*************************************/

string Barbarian::getName() {
    return name;
}

/*************************************
* Description: This function returns
the Barbarian armor.
*************************************/

int Barbarian::getArmor() {
    return armor;
}

/*************************************
* Description: This function returns
* the Barbarian strength.
*************************************/

int Barbarian::getStrength()
{
    return strength;
}

/*************************************
* Description: This function returns
* whether Barbarian is alive or dead.
*************************************/

bool Barbarian::isDead() {
    return dead;
}

/*************************************
* Description: This function is the 
* deconstructor for Barbarian.
*************************************/

Barbarian::~Barbarian() {

}


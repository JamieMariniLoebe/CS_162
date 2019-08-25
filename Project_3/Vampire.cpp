/***************************************************
 * Program Name: Fantasy Combat Game
 * Author: Jamie Loebe
 * Date: 11-01-2018
 * Description: This is the source file for Vampire.
***************************************************/

#include "Vampire.hpp"

#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

/*************************************
* Description: This function sets
* default values for Vampire private 
* member variables and seeds random
* number generator.
*************************************/

void Vampire::setInfo() { // Default valaues for variables
    name = "Vampire";
    armor = 1;
    strength = 18;
    dead = false;
    srand(time(NULL)); // Seed random number generator

}

/*************************************
* Description: This function returns 
* damage variable, which is the roll
* of attack dice. Outputs how much
* attack Vampire generated. Returns damage.
*************************************/

int Vampire::attack() { 
    int damage = attack_roll(); // Damage variable set equal to roll of die.
    cout << "Vampire attacked and generated " << damage << " attack points!!" << endl;
    return damage;
}

/*************************************
* Description: This function sets int
* variable 'roll' to equal random number
* from die roll of 12 sides.
*************************************/

int Vampire::attack_roll() {
    int roll = rand() % 12 + 1; // Roll variable given random number
    return roll;
}

/*************************************
* Description: This function sets int
* variable 'roll' to random number
* from die roll of 12 sides.
*************************************/

int Vampire::defend_roll() {
    int roll = rand() % 6 + 1; // Roll variable given random number
    return roll;
}

/****************************************
* Description: This function calculates 
* whether charm will be used or not.
* Iterates through if statements and outputs
* accordingly.
****************************************/

void Vampire::defend(int attacker_roll) {
    int defender_roll = defend_roll();
    charm = rand() % 2; // 50% chance attacker does not actually attack vampire with charm ability.
    if(charm==0){ // If no charm ability
        if(attacker_roll < 999){
            cout << "Vampire defended and Vampire generated " << defender_roll << " defend points!!" << endl;
        }
        int damage;
        damage = attacker_roll - defender_roll; // Set damage to actual damage taken in after defend die roll

        if (damage <= 0) {
            cout << "Vampire defends attack! Armor and strength remain the same." << endl;
            cout << "Vampire armor remains at " << armor << endl;
            cout << "Vampire strength remains at " << strength << endl;
        }
        else if (damage <= armor) {
            armor = armor - damage;
            cout << "Vampire armor absorbed the attack!" << endl;
            cout << "Vampire armor remains at " << armor << endl;
            cout << "Vampire strength remains at " << strength << endl;
        }
        else if(damage >= 999 ){
            cout << "Oh no! Vampire has died!" << endl;
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
            cout << "Vampire defend attack but lose armor!" << endl;
            cout << "Vampire armor remains at " << armor << endl;
            cout << "Vampire strength remains at " << strength << endl;
        }
    }
    else{
        cout << "Vampire charmed the opponent! No damage inflicted!" << endl;
        cout << "Vampire armor remains at " << armor << endl;
        cout << "Vampire strength remains at " << strength << endl;
    }

    if(strength<=0 ){
        dead = true;
    }
}

/*************************************
 * Description: This function returns
 * 'Vampire 'name'.
***********************************/

string Vampire::getName() {
    return name;
}


/*************************************
* Description: This function returns 
* Vampire armor.
**************************************/
int Vampire::getArmor() {
    return armor;
}

/*************************************
* Description: This function returns 
* Vampire strength.
**************************************/

int Vampire::getStrength() {
    return strength;
}

/*************************************
* Description: This function returns 
* whether Vampire is dead or not.
**************************************/

bool Vampire::isDead() {
    return dead;
}

/*************************************
* Description: This function is the
* Vampire deconstructor.
**************************************/

Vampire::~Vampire() {
}


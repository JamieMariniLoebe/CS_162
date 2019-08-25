/****************************************
 * Program Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/15/2018
 * Description: This is the source file
 * for Harry Potter.
****************************************/


#include "HarryPotter.hpp"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

/*******************************
* Description: This function sets
* the specifics of the character,
* randomly seed the number generator 
* and sets dead variable to false.
*******************************/

void HarryPotter::setInfo() {
    name = "HarryPotter";
    armor = 0;
    strength = 10;
    dead = false;
    hogwarts = 1;
    srand(time(NULL));
}

/*********************************
* Description: This function returns
* the damage inflicted by Harry Potter,
* and outputs the points generated.
*********************************/

int HarryPotter::attack() {
    int damage = attack_roll();
    cout << "HarryPotter attacked and generated " << damage << " attack points!!" << endl;
    return damage;
}

/*********************************
* Description: This function returns
* the roll of the die, and randomly
* generates the die rolls.
*********************************/

int HarryPotter::attack_roll() {
    int roll = rand() % 6 + 1;
    roll = roll + (rand() % 6 + 1);
    return roll;
}

/*********************************
* Description: This function randomly
* generates number for the rolls
* and returns roll.
*********************************/

int HarryPotter::defend_roll() {
    int roll = rand() % 6 + 1;
    roll = roll + (rand() % 6 + 1);
    return roll;
}

/**********************************
* Description: This function iterates
* through if, else-if statements and
* checks what the damage from the 
* attacker was. Depending on the 
* damage from attacker, it outputs
* specific Harry Potter info, and udpates
* armor and strength. 
**********************************/

void HarryPotter::defend(int attacker_roll) {
    int defender_roll = defend_roll();

    if(attacker_roll < 999){
        cout << "HarryPotter defended and HarryPotter generated " << defender_roll << " defend points!!" << endl;
    }
    int damage;
    damage = attacker_roll - defender_roll;

    if (damage <= 0) {
        cout << "HarryPotter defends attack! Armor and strength remain the same." << endl;
        cout << "HarryPotter armor remains at " << armor << endl;
        cout << "HarryPotter strength remains at " << strength << endl;
    }
    else if (damage <= armor) {
        armor = armor - damage;
        cout << "HarryPotter armor absorbed the attack!" << endl;
        cout << "HarryPotter armor remains at " << armor << endl;
        cout << "HarryPotter strength remains at " << strength << endl;
    }
    else if(damage >= 999 && hogwarts == 0 ){
        cout << "Oh no! HarryPotter has died!" << endl;
        cout << "Armor points: 0" << endl;
        cout << "Strength points: 0" << endl;
        armor = 0;
        strength = 0;
        dead = true;
    }
    else if(damage >= 999 && hogwarts == 1 ){
        armor = 0;
        strength = 20;
        hogwarts  = 0;
        cout << "HarryPotter uses hogwarts comes back to life !" << endl;
        cout << "HarryPotter armor remains at " << armor << endl;
        cout << "HarryPotter strength remains at " << strength << endl;
    }
    else if(damage > armor){
        damage = damage - armor;
        strength = strength - damage;
        armor = 0;
        if(hogwarts == 1 && strength<=0){
            armor = 0;
            strength = 20;
            hogwarts  = 0;
            cout << "HarryPotter uses hogwarts comes back to life !" << endl;
            cout << "HarryPotter armor remains at " << armor << endl;
            cout << "HarryPotter strength remains at " << strength << endl;
        }
        else{
            cout << "HarryPotter defend attack but lose armor!" << endl;
            cout << "HarryPotter armor remains at " << armor << endl;
            cout << "HarryPotter strength remains at " << strength << endl;
        };
    }

    if(strength<=0 ){
        dead = true;
    }
}

/*********************************
* Description: This function returns
* the name of the character
*********************************/

std::string HarryPotter::getName() {
    return name;
}

/*********************************
* Description: This function returns
* the armor of the character
*********************************/

int HarryPotter::getArmor() {
    return armor;
}

/*********************************
* Description: This function returns
* the strength of the character
*********************************/

int HarryPotter::getStrength() {
    return strength;
}

/*********************************
* Description: This function returns
* dead, which checks if character is
* dead or not.
*********************************/

bool HarryPotter::isDead() {
    return dead;
}

/*********************************
* Description: This is the deconstructor.
*********************************/

HarryPotter::~HarryPotter() {

}


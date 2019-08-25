/************************************************
 * Program Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/16/2018
 * Description: This is the source file for 
 * BlueMen.
************************************************/

#include "BlueMen.hpp"

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

void BlueMen::setInfo() {
    name = "BlueMen";
    armor = 3;
    strength = 12;
    dead = false;
    srand(time(NULL));
    mob = 3;
}

/*********************************
* Description: This function returns
* the damage inflicted by BlueMen,
* and outputs the points generated.
*********************************/


int BlueMen::attack() {
    int damage = attack_roll();
    cout << "Blue Men attacked and generated " << damage << " attack points!!" << endl;
    return damage;
}

/*********************************
* Description: This function returns
* the roll of the die, and randomly
* generates the the die rolls.
*********************************/

int BlueMen::attack_roll() {
    int roll = rand() % 10 + 1;
    roll = roll + (rand() % 10 + 1);
    return roll;
}

/*********************************
* Description: This function sets
* roll to 0 and iterates through
* if, else-if statements. Depending
* on the mob special ability, it rolls
* the die a certain number of times.
*********************************/

int BlueMen::defend_roll() {
    int roll = 0;
    if(mob == 1){
        roll = roll + (rand() % 6 + 1);
    }
    else if(mob == 2){
        roll = roll + (rand() % 6 + 1);
        roll = roll + (rand() % 6 + 1);
    }
    else if(mob == 3){
        roll = roll + (rand() % 6 + 1);
        roll = roll + (rand() % 6 + 1);
        roll = roll + (rand() % 6 + 1);
    }
    else{
        return 0;
    }
    return roll;
}

/*********************************
* Description: This function iterates
* through if, else-if statements and
* checks what the damage from the 
* attacker was. Depending on the 
* damage from attacker, it outputs
* specific BlueMen info, and udpates
* armor and strength. 
*********************************/

void BlueMen::defend(int attacker_roll) {
    int defender_roll = defend_roll();

    if(attacker_roll < 999){
        cout << "BlueMen defended and BlueMen generated " << defender_roll << " defend points!!" << endl;
    }
    int damage;
    damage = attacker_roll - defender_roll;

    if (damage <= 0) {
        cout << "BlueMen defends attack! Armor and strength remain the same." << endl;
        cout << "BlueMen armor remains at " << armor << endl;
        cout << "BlueMen strength remains at " << strength << endl;
    }
    else if (damage <= armor) {
        armor = armor - damage;
        cout << "BlueMen armor absorbed the attack!" << endl;
        cout << "BlueMen armor remains at " << armor << endl;
        cout << "BlueMen strength remains at " << strength << endl;
    }
    else if(damage >= 999 ){
        cout << "Oh no! BlueMen has died!" << endl;
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
        cout << "BlueMen defend attack but lose armor!" << endl;
        cout << "BlueMen armor remains at " << armor << endl;
        cout << "BlueMen strength remains at " << strength << endl;
    }

    if(strength<=0 ){
        dead = true;
    }

    mob = strength / 4;

}

/*********************************
* Description: This function returns
* the name of the character
*********************************/

std::string BlueMen::getName() {
    return name;
}

/*********************************
* Description: This function returns
* the armor of the character
*********************************/

int BlueMen::getArmor() {
    return armor;
}

/*********************************
* Description: This function returns
* the strength of the character
*********************************/

int BlueMen::getStrength() {
    return strength;
}

/*********************************
* Description: This function returns
* dead, which checks if character
* is dead or not.
*********************************/

bool BlueMen::isDead() {
    return dead;
}

/*********************************
* Description: This is the deconstructor.
*********************************/

BlueMen::~BlueMen() {

}


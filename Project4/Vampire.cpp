/**********************************
 * Project Name: Project 4
 * Author: Jamie Loebe
 * Date: 11/16/2018
 * Description: This is the source
 * file for vampire.
**********************************/

#include "Vampire.hpp"

#include <string>
#include <iostream>
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

void Vampire::setInfo() {
    name = "Vampire";
    armor = 1;
    strength = 18;
    dead = false;
    srand(time(NULL));

}

/*********************************
* Description: This function returns
* the damage inflicted by vampire,
* and outputs the points generated.
*********************************/

int Vampire::attack() {
    int damage = attack_roll();
    cout << "Vampire attacked and generated " << damage << " attack points!!" << endl;
    return damage;
}

/*********************************
* Description: This function returns
* the roll of the die, and randomly
* generates the die rolls.
*********************************/

int Vampire::attack_roll() {
    int roll = rand() % 12 + 1;
    return roll;
}

/*********************************
* Description: This function randomly
* generates number for the die roll
* then returns roll. 
*********************************/

int Vampire::defend_roll() {
    int roll = rand() % 6 + 1;
    return roll;
}

/*********************************
* Description: This function first
* randomly generates a number for
* charm, then iterates
* through if, else-if statements and
* checks what the damage from the 
* attacker was. It checks the charm
* special ability. Depending on the 
* damage from attacker, it outputs
* specific Vampire info, and udpates
* armor and strength. 
*********************************/

void Vampire::defend(int attacker_roll) {
    int defender_roll = defend_roll();
    charm = rand() % 2;
    if(charm==0){
        if(attacker_roll < 999){
            cout << "Vampire defended and Vampire generated " << defender_roll << " defend points!!" << endl;
        }
        int damage;
        damage = attacker_roll - defender_roll;

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

/*********************************
* Description: This function returns
* the name of the character
*********************************/

string Vampire::getName() {
    return name;
}

/*********************************
* Description: This function returns
* the armor of the character
*********************************/

int Vampire::getArmor() {
    return armor;
}

/*********************************
* Description: This function returns
* the strength of the character
*********************************/

int Vampire::getStrength() {
    return strength;
}

/*********************************
* Description: This function returns
* dead, which checks if character
* is dead or not.
*********************************/

bool Vampire::isDead() {
    return dead;
}

/*********************************
* Description: This is the deconstructor.
*********************************/

Vampire::~Vampire() {
}


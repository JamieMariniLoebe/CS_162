/********************************************************
* Program Name: Fantasy Combat Game
* Author: Jamie Loebe
* Date: 11/01/2018
* Description: This is the source file for Harry Potter.
*******************************************************/


#include "HarryPotter.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>


using std::cout;
using std::cin;
using std::endl;

/********************************************
* Description: This function sets default
* values for private member variables and also
* seeds random number generator.
********************************************/

void HarryPotter::setInfo() {
    name = "HarryPotter";
    armor = 0;
    strength = 10;
    dead = false;
    hogwarts = 1;
    srand(time(NULL));
}

/********************************************
* Description: This function sets int variable
* 'damage' to attack die roll and outputs
* attack poiints and returns damage.
********************************************/

int HarryPotter::attack() {
    int damage = attack_roll();
    cout << "HarryPotter attacked and generated " << damage << " attack points!!" << endl;
    return damage;
}

/********************************************
* Description: This function calculates 
* random die roll for 2 six-sided die.
********************************************/

int HarryPotter::attack_roll() {
    int roll = rand() % 6 + 1;
    roll = roll + (rand() % 6 + 1);
    return roll;
}

/********************************************
* Description: This function calculates random
* die roll for 2 six-sided die.
********************************************/

int HarryPotter::defend_roll() {
    int roll = rand() % 6 + 1;
    roll = roll + (rand() % 6 + 1);
    return roll;
}

/********************************************
* Description: This function iterates through
* if-statements checking damage and attack
* points and outputs message accordingly.
********************************************/

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

/********************************************
* Description: This function returns 
* "Harry Potter" name.
********************************************/

string HarryPotter::getName() {
    return name;
}

/********************************************
* Description: This function Harry Potter's armor
********************************************/

int HarryPotter::getArmor() {
    return armor;
}

/********************************************
* Description: This function returns 
* Harry Potter's strength.
********************************************/

int HarryPotter::getStrength() {
    return strength;
}

/********************************************
* Description: This function returns whether
* Harry Potter is dead or not.
********************************************/

bool HarryPotter::isDead() {
    return dead;
}

/********************************************
* Description: This is the deconstructor for 
* Harry Potter.
********************************************/

HarryPotter::~HarryPotter() {

}


/********************************************
 * Program Name: Final Project
 * Author: Jamie Loebe
 * Date: 12/01/2018
 * Description: This is the source file for
 * Location.
********************************************/

#include "Location.hpp"

string names[] = {"roof","hall","yard","room","kitchen","basement","elevator","office","exit","entrance"};
string items[] = {"sword","shield","money","key0","key1","gun","bullets","key2","elixir","jacket"};
string keys[] = {"key0","key0","key2"};

/***************************************
 * Description: This function initializes
 * each variable.
***************************************/

Location::Location(string name, string itemAtLocation, string key, bool key_required, bool monster, int monster_power,
                   bool healthDrink,int healthGain,bool isItem) {

    this->name = name;
    this->itemAtLocation = itemAtLocation;
    this->key_required = key_required;
    this->key = key;
    this->monster = monster;
    this->monster_power = monster_power;
    this->healthDrink = healthDrink;
    this->healthGain = healthGain;
    this->isItem = isItem;
}

Location* Location::getNewLocation() {

    int n = rand()%SIZE;
    int i = rand()%SIZE;
    int k = rand()%3;
    bool kb = rand() % 5 == 0;
    bool mb = rand() % 5 == 0;
    bool ib = rand() % 3 == 0;
    int mp = rand()%5;
    bool hb = rand() % 5 == 0;
    int hg = rand()%5;

    return new Location(names[n],items[i],keys[k],kb,mb,mp,hb,hg,ib);
}

/***************************************
 * Description: This function
 * returns name of the location.
***************************************/

const string &Location::getName() const {
    return name;
}

/***************************************
 * Description: This function returns
 * the location of item.
***************************************/

const string &Location::getItemAtLocation() const {
    return itemAtLocation;
}

/***************************************
 * Description: This function returns
 * key.
***************************************/

const string &Location::getKey() const {
    return key;
}

/***************************************
 * Description: This function returns
 * true or false if key is required.
***************************************/

bool Location::isKey_required() const {
    return key_required;
}

/***************************************
 * Description: This function returns 
 * true or false if there is a monster.
***************************************/

bool Location::isMonster() const {
    return monster;
}

/***************************************
 * Description: This function returns
 * the power of monster.
***************************************/

int Location::getMonster_power() const {
    return monster_power;
}

/***************************************
 * Description: This function returns
 * true or false if item is a health drink.
***************************************/

bool Location::isHealthDrink() const {
    return healthDrink;
}

/***************************************
 * Description: This functionr returns
 * the health gain.
***************************************/

int Location::getHealthGain() const {
    return healthGain;
}

/***************************************
 * Description: This function returns 
 * true or false if there is an item.
***************************************/

bool Location::isIsItem() const {
    return isItem;
}

/***************************************
 * Description: This function sets item
 * if there is one.
***************************************/

void Location::setIsItem(bool isItem) {
    Location::isItem = isItem;
}

/***************************************
 * Description: This function initializes
 * monster if there is one.
***************************************/

void Location::setMonster(bool monster) {
    Location::monster = monster;
}

/***************************************
 * Description: If item is a health drink,
 * initializes health drink.
***************************************/

void Location::setHealthDrink(bool healthDrink) {
    Location::healthDrink = healthDrink;
}


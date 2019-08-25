/**********************************************
 * Program Name: Final Project
 * Author: Jamie Loebe
 * Date: 12/01/2018
 * Description: This is the header file
 * for Location.
**********************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#ifndef LOCATION_HPP
#define LOCATION_HPP


#define SIZE 10

class Location {

protected:
    string name;
    bool isItem;
    string itemAtLocation;
    string key;
    bool key_required;
    bool  monster;
    int monster_power;
    bool healthDrink;
    int healthGain;

public:
    Location(string name, string itemAtLocation, string key, bool key_required, bool monster,
             int monster_power, bool healthDrink,int healthGain,bool isItem);
    Location* getNewLocation();
    const string &getName() const;
    const string &getItemAtLocation() const;
    const string &getKey() const;
    bool isKey_required() const;
    bool isMonster() const;
    int getMonster_power() const;
    bool isHealthDrink() const;
    int getHealthGain() const;
    bool isIsItem() const;


    void setIsItem(bool isItem);
    void setMonster(bool monster);
    void setHealthDrink(bool healthDrink);

};


#endif

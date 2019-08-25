/***************************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/21/2018
** Description: This is the University
** header file
***************************************/

#ifndef UNIVERSITY_hpp
#define UNIVERSITY_hpp

#include <vector>
#include <string>

#include "Building.hpp"
#include "Person.hpp"

using std::string;
using std::vector;

class University
{
private:// private member variables
    string name;//string for name
    vector<Building> buildings;//vector for building objects
    vector<Person *> people;//vector for people objects

public:
    University(); //default constructor
    University(string n, vector<Building> b, vector<Person *> p); //parameterized constructor
    
    void setName(string n); //setter to set name
    string getName(); //getter to retrieve name
    
    void setBuildings(vector<Building> b); //setter to set vector of Building objects
    vector<Building> getNumBuildings(); //getter to retrieve buildigns vector
    
    void setNumPeople(vector<Person *> p); //setter to set vector of Person objects
    vector<Person *> getNumPeople(); //getter to retrieve Person vector
    
    void printBuildingInfo(); //function to print Building info
    void printPeopleInfo(); //function to print Person info
};

#endif


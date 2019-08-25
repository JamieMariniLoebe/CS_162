/***************************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/21/2018
** Description: This is the University 
** source file.
***************************************/

#include "University.hpp"
#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


University::University()//default constructor
{
    name = "";//sets name as empty string
}

University::University(string n, vector<Building> b, vector<Person *> p)//parameterized constructor
{
    name = n;//sets n as name
    buildings = b;//sets b as vector
    people = p;//sets p as vector
}

void University::setName(string n)//setter to set name
{
    name = n;//sets n as name
}

string University::getName()//getter to retrieve name
{
    return name;//returns name value
}

void University::setBuildings(vector<Building> b)//setter to set vector of Building objects
{
    buildings = b;//sets b as buildings value
}

vector<Building> University::getNumBuildings()//getter to retrieve buildings vector
{
    return buildings;
}

void University::setNumPeople(vector<Person *> p)//setter to set vector of Person objects
{
    people = p;//sets p as Person vector value
}

vector<Person *> University::getNumPeople()//getter to retrieve Person vector
{
    return people;
}

void University::printBuildingInfo()//function to print Building info
{
    for (int i = 0; i < buildings.size(); i++)//iterate through buildings vector
    {
        cout << "Name of building: " << buildings[i].getName() << endl;//print building info
        cout << "Size of building: " << buildings[i].getSize() << " sqft" << endl;
        cout << "Address of building: " << buildings[i].getAddress() << endl << endl;
    }
}

void University::printPeopleInfo()//function to print Person info
{
    for (int i = 0; i < people.size(); i++)//iterate through people vector and
    {
        cout << "Name: " << people[i]->getName() << endl;//print each of the details
        cout << "Age: " << people[i]->getAge() << endl;
        //people[i].do_work();
        cout << endl;
    }
}

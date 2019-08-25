/***********************************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/20/2018
** Description: This is the Building source
** file.
************************************************/

#include "Building.hpp"

Building::Building()//default constructor to set default values of member variables
{
    name = "";//set name as empty string
    size = 0;//set size as 0
    address = "";//set address as empty string
}

Building::Building(string n, double s, string a)//parameterised constructor
{
    name = n;//set n as name
    size = s;//set s as size
    address = a;//set a as address
}

//setter to set name of the building
void Building::setName(string n)
{
    name = n;//sets n as name
}

string Building::getName()//getter to retrieve name of the building
{
    return name;//returns name value
}

//setter to set size of the building
void Building::setSize(double s)
{
    size = s;//sets s as size
}

double Building::getSize()//getter to retrieve size of the building
{
    return size;//returns size value
}

//setter to set address of the building
void Building::setAddress(string a)
{
    address = a;//sets a as address
}

string Building::getAddress()//getter to return the address of the building
{
    return address;//returns address value
}

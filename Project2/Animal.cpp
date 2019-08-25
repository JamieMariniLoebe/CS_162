/*************************************************
** Program Name: Zoo Tycoon
** Author: Jamie Loebe
** Date: 10/17/2018
** Description: This is the source file for the 
** Animal header file.
*************************************************/

#include "Animal.hpp"

Animal::Animal() // Default constructor
{ // Initialize variables to 0
    age = 0;
    cost = 0;
    numOfBabies = 0;
    baseFoodCost = 0;
    payoff = 0;
}

Animal::Animal(int newAge, double newCost, int newNumOfBabies, double newPayoff)
{ // Constructor, implement new variables.
    age = newAge;
    cost = newCost;
    numOfBabies = newNumOfBabies;
    baseFoodCost = 10;
    payoff = newPayoff;
}

void Animal::setAge(int newAge)
{
    age = newAge; 
}

int Animal::getAge()
{
    return age;
}

void Animal::setCost(double newCost)
{
    cost = newCost;
}

double Animal::getCost()
{
    return cost;
}

void Animal::setNumOfBabies(int newNumOfBabies)
{
    numOfBabies = newNumOfBabies;
}

int Animal::getNumOfBabies()
{
    return numOfBabies;
}

void Animal::setBaseFoodCost(double newBaseFoodCost)
{
    baseFoodCost = newBaseFoodCost;
}

double Animal::getBaseFoodCost()
{
    return baseFoodCost;
}

void Animal::setPayoff(double newPayoff)
{
    payoff = newPayoff;
}

double Animal::getPayoff()
{
    return payoff;
}

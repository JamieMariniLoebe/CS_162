/**************************************************
** Program Name: Zoo Tycoon
** Author: Jamie Loebe
** Date: 10/18/2018
** Description: This is the source file for Penguin
**
**************************************************/

#include "Penguin.hpp"

Penguin::Penguin()
{

}

Penguin::Penguin(int newAge, double newCost, int newNumOfBabies,
                 double newPayoff, double feedingCost)
        :Animal(newAge, newCost, newNumOfBabies,
                newPayoff)
{
    Penguin::feedingCost = feedingCost;
}

double Penguin::getFeedingCost() const {
    return feedingCost;
}

void Penguin::setFeedingCost(double feedingCost) {
    Penguin::feedingCost = feedingCost;
}


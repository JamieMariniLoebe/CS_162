/**********************************************
** Program Name: Zoo Tycoon
** Author: Jamie Loebe
** Date: 10/18/2018
** Description: This is the source file for Turtle.
**********************************************/

#include "Turtle.hpp"

Turtle::Turtle()
{

}

Turtle::Turtle(int newAge, double newCost, int newNumOfBabies,
                double newPayoff, double feedingCost)
               :Animal(newAge, newCost, newNumOfBabies,
                        newPayoff)
{
    Turtle::feedingCost = feedingCost;
}

double Turtle::getFeedingCost() const {
    return feedingCost;
}

void Turtle::setFeedingCost(double feedingCost) {
    Turtle::feedingCost = feedingCost;
}


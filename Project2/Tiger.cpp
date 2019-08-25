/*********************************************
** Program Name: Zoo Tycoon
** Author: Jamie Loebe
** Date: 10/17/2018
** Description: This is the source file for 
** the Tiger header file.
*********************************************/

#include "Tiger.hpp"

Tiger::Tiger()
{

}

Tiger::Tiger(int newAge, double newCost, int newNumOfBabies, double newPayoff, double feedingCost)
        :Animal(newAge, newCost, newNumOfBabies,
                newPayoff)
{
    Tiger::feedingCost = feedingCost;
}

double Tiger::getFeedingCost() const {
    return feedingCost;
}

void Tiger::setFeedingCost(double feedingCost) {
    Tiger::feedingCost = feedingCost;
}


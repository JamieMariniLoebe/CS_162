/**************************************************
** Program Name: Zoo Tycoon
** Author: Jamie Loebe
** Date: 10/17/2018
** Description: This is the header file for Penguin.
**
**************************************************/

#ifndef PENGUIN_hpp
#define PENGUIN_hpp

#include "Animal.hpp"

class Penguin : public Animal
{
public:
    Penguin();
    Penguin(int newAge, double newCost, int newNumOfBabies, double newPayoff, double feedingCost);

private:
    double feedingCost;

public:
    double getFeedingCost() const;

    void setFeedingCost(double feedingCost);

};

#endif


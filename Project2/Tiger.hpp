/**************************************************
** Program Name: Zoo Tycoon
** Author: Jamie Loebe
** Date: 10/17/2018
** Description: This is the Tiger header file
**
**************************************************/

#ifndef TIGER_hpp
#define TIGER_hpp

#include "Animal.hpp"

class Tiger : public Animal // Inherit Animal
{
public:
    Tiger(); // Default constructor
    Tiger(int newAge, double newCost, int newNumOfBabies, double newPayoff, double feedingCost);

private:
    double  feedingCost;

public:
    double getFeedingCost() const;

    void setFeedingCost(double feedingCost);
};

#endif


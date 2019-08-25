/********************************************
** Program Name: Zoo Tycoon
** Name: Jamie Loebe
** Date: 10/18/2018
** Description: This is the Turtle header file
**
********************************************/

#ifndef TURTLE_hpp
#define TURTLE_hpp

#include "Animal.hpp"

class Turtle : public Animal
{
public:
    Turtle();
    Turtle(int newAge, double newCost, int newNumOfBabies,
           double newPayoff, double feedingCost);
private:
    double feedingCost;

public:
    double getFeedingCost() const;

    void setFeedingCost(double feedingCost);
};

#endif


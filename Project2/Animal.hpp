/********************************************
** Program Name: Zoo Tycoon
** Author: Jamie Loebe
** Date: 10/19/2018
** Description: This is the header file for Animal
********************************************/

#ifndef ANIMAL_hpp
#define ANIMAL_hpp

class Animal
{
private:
    int age;
    int cost;
    int numOfBabies;
    int baseFoodCost;
    int payoff;

public:
    Animal(); // Default constructor
    Animal(int newAge, double newCost, int newNumberOfBabies,
           double newPayoff); //Constructor

    void setAge(int newAge); // Set age
    
    //Get age
    int getAge();
    
    //Set cost
    void setCost(double newCost);
    
    //Get cost
    double getCost();
    
    //Set # ofbabies
    void setNumOfBabies(int newNumberOfBabies);
    
    //Get # of babies
    int getNumOfBabies();
    
    //Set baseFoodCost
    void setBaseFoodCost(double newBaseFoodCost);
    
    //Get baseFoodCost
    double getBaseFoodCost();
    
    //Set payoff
    void setPayoff(double newPayoff);
    
    //Get payoff
    double getPayoff();
};

#endif


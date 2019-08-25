/*************************************************
** Program Name: Zoo Tycoon
** Author: Jamie Loebe
** Date: 10/19/2018
** Description: This is the Zoo header file/
*************************************************/

#ifndef ZOO_hpp
#define ZOO_hpp

#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

class Zoo
{
private:
    // Arrays of animals
    Tiger **tigers;
    Penguin **penguins;
    Turtle **turtles;

    // Capacity for each animal
    int tigerSpace;
    int penguinSpace;
    int turtleSpace;\

    // Quantity of each animal
    int numOfTigers;
    int numOfPenguins;
    int numOfTurtles;

    // Declare balance and profit
    double balance;
    double profit;

public:

    //Constructors
    Zoo(); // Constructor

    // Add animals
    void addTiger(Tiger *newTiger); // Add new Tiger object
    void addPenguin(Penguin *newPenguin); // Add new Penguin object
    void addTurtle(Turtle *newTurtle); // Add new Turtle object

    // Add babies
    bool addTigerBaby(); // True if tiger baby born
    bool addPenguinBaby(); // True if penguin baby born
    bool addTurtleBaby(); // True if turtle baby born

    // Remove animal from exhibit
    bool tigerDies(); // True if tiger dies
    bool penguinDies(); // True if penguin dies
    bool turtleDies(); // True if turtle dies

    // Voids
    void randomEvent(); // Random event occurs
    void calculateProfit(); // Calculate profit
    void setBalance(double balance); // Set $$ for user
    void resetProfit(); // Reset profits

    //Getters
    double getBalance();
    double getProfit();

    //Increase age by 1 day
    void increaseAge();

    //Pay the feeding cost of each animal
    void payFeedingCost();

    //Start new day
    void newDay();

    //Play the game
    void playGame();
    
    //Output summary of animals
    void zooSummary();

};

#endif


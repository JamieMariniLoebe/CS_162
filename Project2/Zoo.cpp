/*************************************************************
** Program Name: Zoo Tycoon
** Author: Jamie Loebe
** Date: 10/19/2018
** Description: This is the source file for the Zoo header file
**************************************************************/

#include "Zoo.hpp"
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;


/************************************************
** Description: Default constructor. This 
** function initializes the variables and
** dynamically allocates memory for the 
** quantity of animals allowed.
************************************************/

Zoo::Zoo() // Default constructor
{
    double startBalance = 100000;

    tigerSpace = 10; // Set tiger capacity to 10
    penguinSpace = 10; // Set penguin capacity to 10
    turtleSpace = 10; // Set penguin capacity to 10

    tigers = new Tiger*[tigerSpace]; // dynamically allocated pointer to pointer to arrays (size of tigerSpace)
    penguins = new Penguin*[penguinSpace]; // dynamically allocated pointer to pointer to arrays (size of penguinSpace)
    turtles = new Turtle*[turtleSpace]; // dynamically allocated pointer to pointer to arrays (size of turtleSpace)

    balance = startBalance;
    profit = 0; // Initialize profit to 0
    numOfTigers = 0; // Initialize numOfTigers to 0
    numOfPenguins = 0; // Initialize numOfPenguins to 0
    numOfTurtles = 0; // Initialize numOfTurtles to 0

}

/***************************************************
** Description: This function doubles capacity
** if needed to allow more tigers, adds new tiger
** and updates balance to reflect the 
** new tiger being added.
***************************************************/

void Zoo::addTiger(Tiger *newTiger)
{
    if (numOfTigers >= tigerSpace) // if # of tigers is greater or equal to the capacity for tigers
    {
        Tiger** biggerTigers = new Tiger*[2 * tigerSpace]; // Double capacity by multiplying space by 2

        for (int i = 0; i < tigerSpace; i++) // Iterate through tigers
        {
            biggerTigers[i] = tigers[i]; // Transfer array from tigers to biggerTigers
        }

        delete [] tigers; // Delete old array of Tigers
        tigerSpace *= 2; // Double capacity of new space
        tigers = biggerTigers; // Set old array equal to new array
    }

    tigers[numOfTigers] = newTiger; // Add new tiger to tigers array
    numOfTigers++; // Increment tiger size by 1
    balance = balance - 10000; // Subtract $10,000, as a tiger costs $10,000
    balance = balance - 10; //subtract the base food cost
}

/*************************************************
** Description: This function doubles the capacity
** for penguins if needed, and adds the new penguin. 
** It also updates the balance to account for the 
** new penguin.
*************************************************/

void Zoo::addPenguin(Penguin *newPenguin)
{
    if (numOfPenguins >= penguinSpace) // if # of penguins is grater or equal to capacity for penguins
    {
        Penguin** biggerPenguins = new Penguin*[2 * penguinSpace]; // Double array size for penguinSpace
        for (int i =0; i < penguinSpace; i++) // iterate through each penguin
        {
             biggerPenguins[i] = penguins[i]; // Transfer array from penguins to biggerPenguins
        }

        delete [] penguins; // Delete old array
        penguinSpace *= 2; // Double size of penguinSpace
        penguins = biggerPenguins; // Set new array equal to old array
    }

    penguins[numOfPenguins] = newPenguin; // set new array and capacity equal to penguin object(s)
    numOfPenguins++; // Increment # of penguins by 1
    balance = balance - 1000; // Subtract 1000 from balanace, as penguins each cost $1,000
    balance = balance - 10; //subtract the base food cost
}

/************************************************
** Description: This function doubles the capacity 
** for turtles if needed, and adds the new turtle.
** It also updates the balance to account for the 
** new turtle.
************************************************/

void Zoo::addTurtle(Turtle *newTurtle)
{
    if (numOfTurtles >= turtleSpace) // If # of turtles exceeds capacity for turtles
    {
        Turtle** biggerTurtles = new Turtle*[2 * turtleSpace]; // Double turtleSpace
        for (int i=0; i < numOfTurtles; i++) // iterate through each turtle
        {
            biggerTurtles[i] = turtles[i]; // Set turtles equal to new array biggerTurtles
        }

        delete [] turtles; // Delete old array
        turtleSpace *= 2; // Double array size
        turtles = biggerTurtles; // Set old array equal to new array
    }

    turtles[numOfTurtles] = newTurtle; // Set new array and size equal to newTurtle
    numOfTurtles++; // Increment # of turtles by 1
    balance = balance - 100; // Subtract 100 as each turtle costs $100
    balance = balance - 10; //subtract the base food cost
}

/************************************************
** Description: This function adds a tiger baby if
** there is an adult tiger. Iterate through each 
** tiger to check if it is a baby, set new # of babies,
** and update balance.
************************************************/

bool Zoo::addTigerBaby()
{
    for (int i=0; i < numOfTigers; i++) // Iterate through each tiger
    {
        if (tigers[i]->getAge() >= 3) // If tiger is adult..
        {
            tigers[i]->setNumOfBabies(tigers[i]->getNumOfBabies() +1); // Get num of babies, and set to # of babies + 1
            Tiger *t = new Tiger(1, 10000, 0, 2000, 50); // dynamically allocate for new tiger
            addTiger(t); // Add new tiger
            balance += 10000; // Update balance
            return true;
        }
    }
    return false; // If no tiger is an adult
}

/***********************************************************
** Description: This function adds a penguin baby 
** if there is an adult penguin. It iterates through
** each penguin to check if it is a baby, sets the new
** # of babies and then adds 5, as each penguin has 5 babies,
** and updates the balance to account for the new baby.
************************************************************/

bool Zoo::addPenguinBaby()
{
    for (int i=0; i < numOfPenguins; i++) // Iterate through each penguin
    {
        if(penguins[i]->getAge() >= 3) // Get age of each penguin, if age >=3....
        {
            penguins[i]->setNumOfBabies(penguins[i]->getNumOfBabies() + 5); // Get and set # of babies to # of babies +5
            for(int i=0;i<5;i++) { // For loop through 5 new babies
                addPenguin(new Penguin(1, 1000, 0, 100, 10)); // dynamically allocate for new penguin
                balance += 1000; // Update balance
            }
            return true; // set adultFound to true
        }
    }
    return false;
}

/***********************************************************
** Description: This function adds a turtle baby if there is
** an adult turtle. It iterates through each turtle to check
** if it is a baby, then sets the new # of babies and adds 10
** (as each turtle can have 10 babies), and updates the balance.
************************************************************/


bool Zoo::addTurtleBaby()
{
    for (int i=0; i < numOfTurtles; i++) // Iterate through each turtle
    {
        if (turtles[i]->getAge() >= 3) // If turtle is adult
        {
            turtles[i]->setNumOfBabies(turtles[i]->getNumOfBabies() + 10); // Get and set new # of babies +10
            for(int i=0;i<10;i++) { // For loop through 10 new babies
                addTurtle(new Turtle(1, 100, 0, 5, 5)); // Dynamically allocate for new turtle
                balance += 100; // Update balance
            }
            return true;
        }
    }
    return false;
}

/*********************************************
** Description: This function kills a tiger.
** When it is called, if there are 0 tigers, it
** will do nothing, but if there are tigers,
** it will kill/remove one of them.
*********************************************/

bool Zoo::tigerDies()
{
    if (numOfTigers == 0)
    {
        return false;
    }

    else
    {
        cout << "Uh oh! One tiger has died!" << endl;
        numOfTigers--;
        return true;
    }
}

/**********************************************
** Description: This function kills a penguin.
** When this function is caled, if there are 0
** penguins, it does nothing. But if there are 
** penguins, it kills/removes one of them.
**********************************************/

bool Zoo::penguinDies()
{
    if (numOfPenguins == 0)
    {
        return false;
    }

    else
    {
        cout << "Uh oh! One penguin has died!" << endl;
        numOfPenguins--;
        return true;
    }
}

/*********************************************
** Description: This function kills a turtle.
** When this function is called, if there are
** 0 turtles it does nothing. But if there are
** turtles, it kills/removes one of them.
*********************************************/

bool Zoo::turtleDies()
{
    if (numOfTurtles == 0)
    {
        return false;
    }

    else
    {
        cout << "Uh oh! One turtle has died!" << endl;
        numOfTurtles--;
        return true;
    }
}

/********************************************
** Description: This function increases the
** age of an animal by 1.
********************************************/

void Zoo::increaseAge() {

    for(int i=0;i<numOfTigers;i++) { // Iterate through each tiger
        tigers[i]->setAge(tigers[i]->getAge() + 1); // Get tigers age, add 1, anf set new age for tiger.
    }
    for(int i=0;i<numOfPenguins;i++) { // Iterate through each penguin
        penguins[i]->setAge(penguins[i]->getAge() + 1); // Get penguins age, add 1, and set new age for penguin
    }
    for(int i=0;i<numOfTurtles;i++) { // Iterate through each turtle
        turtles[i]->setAge(turtles[i]->getAge() + 1); // Get turtles age, add 1, and set new age for turtle
    }

}

/*******************************************
** Description: This function checks if there
** is enough money to cover the feeding costs
** of each animal. If not, animals will die.
** If there is, nothing will happen. 
**
*******************************************/

void Zoo::payFeedingCost() {

    int index; // Declare variable integer index
    for(int i=0;i<numOfTigers;i++) { // Iterate through each tiger
        if(balance > tigers[i]->getFeedingCost()) { // If balance is greater than tiger feeding cost
            balance -= tigers[i]->getFeedingCost(); // Subtract feeding cost from balance
        }
        else {
            index = i; // Set index equal to i
            cout << numOfTigers - index << "have died as zoo is unable to provide food for tigers" << endl;
            numOfTigers = index + 1; // Set new number of tigers
            break;
        }
    }
    for(int i=0;i<numOfPenguins;i++) { // Iterate through each penguin
        if(balance > penguins[i]->getFeedingCost()) { // If balance is greater than penguin feeding cost
            balance -= penguins[i]->getFeedingCost(); // Subtract feeding cost from balance
        }
        else {
            index = i;
            cout << numOfPenguins - index << "have died as zoo is unable to provide food for penguins" << endl;
            numOfPenguins = index + 1; // Set new number of penguins
            break;
        }
    }
    for(int i=0;i<numOfTurtles;i++) { // Iterate through each turtle
        if(balance > turtles[i]->getFeedingCost()) { // If balance is greater than feeding cost
            balance -= turtles[i]->getFeedingCost(); // Subtract feeding cost from balance
        }
        else {
            index = i;
            cout << numOfTurtles - index << "have died as zoo is unable to provide food for turtules" << endl;
            numOfTurtles = index + 1; // Set new number of turtles
            break;
        }
    }

}

/*************************************************
** Description: This is the random event function.
** It uses the random number generator to call a 
** random event case. This can be an animal dying, 
** an animal being born, or a boom in attendance.
*************************************************/

void Zoo::randomEvent() {
    srand(time(NULL)); // Seed random number generator
    int random_number = rand()%4 + 1;

    switch(random_number) {
        case 1: {
            cout << "A sickness has occured to an Animal, ";
            int random_animal = rand()%3 + 1;
            switch (random_animal) {
                case 1: {
                    cout << "A tiger has died!" << endl;
                    tigerDies(); // Call tigerDies() function
                    break;
                }
                case 2: {
                    cout << "A penguin has died!" << endl;
                    penguinDies(); // Call penguinDies() function
                    break;
                }
                default : {
                    cout << "A turtule has died!" << endl;
                    turtleDies(); // Call turtleDies() function.
                    break;
                }
            }
            break;
        }
        case 2: {
            cout << "A boom in zoo attendance has occured!" << endl;
            int random_payoff = rand()%250 + 251;
            for(int i=0;i<numOfTigers;i++) { // Iterate through each tiger
                profit += random_payoff; // Increase profit by random_payoff
            }
            break;
        }
        case 3: {
            cout << "A baby animal born event has occured, ";

            int random_animal;
            bool f1 = false, f2 = false, f3 = false;
            bool f11 = true, f22 = true, f33 = true;

            while(true) {
                random_animal = rand()%3 + 1;
                switch (random_animal) {
                    case 1: {
                        if(addTigerBaby()) { // If tiger baby is added
                            f1 = true;
                            cout << "A tiger baby is born!" << endl;
                        }
                        else
                            f11 = false;
                        break;
                    }
                    case 2: {
                        if(addPenguinBaby()) {
                            f2 = true;
                            cout << "Penguin babies are born!" << endl;
                        }
                        else
                            f22 = false;
                        break;
                    }
                    default : {
                        if(addTurtleBaby()) {
                            f3 = true;
                            cout << "Turtule babies are born!" << endl;
                        }
                        else
                            f33 = false;
                        break;
                    }
                }
                if(f1 || f2 || f3) {
                    break;
                }
                if(!f11 && !f22 && !f33) {
                    cout << "No animal can give birth since no Animal is an adult!" << endl;
                    break;
                }
            }
            break;
        }
        default:
            break;
    }

}

/***************************************************
** Description: This function calculates the profit
** of each animal.
****************************************************/

void Zoo::calculateProfit() {

    for(int i=0;i<numOfTigers;i++) { // Iterate through each tiger
        profit += tigers[i]->getPayoff(); // Add payoff to profit total
    }
    for(int i=0;i<numOfPenguins;i++) { // Iterate through each penguin
        profit += penguins[i]->getPayoff(); // Add payoff to profit total
    }
    for(int i=0;i<numOfTurtles;i++) { // Iterate through each turtle
        profit += turtles[i]->getPayoff(); // Add payoff to profit total
    }

    balance += profit; // Add profit to balance total

}

/************************************************
** Description: This function returns the profit
************************************************/
double Zoo::getProfit() {
    return Zoo::profit;
}

/***********************************************
** Description:  This function returns the balance
***********************************************/

double Zoo::getBalance() {
    return Zoo::balance;
}

/**********************************************
** Description: This function sets balance to
** balance.
**********************************************/

void Zoo::setBalance(double balance)  {
    Zoo::balance = balance;
}

/*********************************************
** Description: This function sets profit to 0. 
**
*********************************************/

void Zoo::resetProfit() {
    Zoo::profit = 0;
}

/********************************************
** Description: This function begins a new day
** and provides the user with options to continue
** the game. 
**
*******************************************/

void Zoo::newDay() {

    cout << "New Day starts!" << endl;
    int ch = 1;
    while(true) {
        cout << "Please enter 1 if you want to add animal to the zoo else enter 2: ";
        cin >> ch;
        if(ch == 2) // If user enters 2
            break;
        int animal;
        cout << "Please enter the type of the animal you want to add? 1 for tiger, 2 for penguin, 3 for turtle: ";
        cin >> animal;
        while(true) {
            if(animal >= 1  && animal <= 3) { 
                break;
            }
            cout << "The animal type is invalid, Pease input the correct animal type!" << endl;
            cout << "Please enter the type of the animal you want to add? 1 for tiger, 2 for penguin, 3 for turtle: ";
            cin >> animal;
        }
        switch(animal) {
            case 1: {  //balance checks for the base cost to purchse the animal as well as the base food cost of the animal
                if(balance < 10010) {
                    cout << "The balance is less in the zoo! Tiger cannot be purchased!" << endl;
                    break;
                }
                addTiger(new Tiger(0, 10000, 0, 2000, 50)); // If user has sufficient funds, add new tiger.
                break;
            }
            case 2: {
                if(balance < 1010) {
                    cout << "The balance is less in the zoo! Penguin cannot be purchased!" << endl;
                    break;
                }
                addPenguin(new Penguin(0, 1000, 0, 100, 10)); // If user has sufficient funds, add new penguin.
                break;
            }
            default: {
                if(balance < 110) {
                    cout << "The balance is less in the zoo! Turtle cannot be purchased!" << endl;
                    break;
                }
                addTurtle(new Turtle(0, 100, 0, 5, 5)); // If user has sufficient funds, add new turtle.
                break;
            }
        }
    } 
    increaseAge(); // Call increaseAge function
    payFeedingCost(); // Call payFeedingCost function
    resetProfit(); // Call resetProfit function.

    randomEvent(); // Call randomEvent function
    calculateProfit(); // Call calculateProfit function
    cout << "The profit for the day is: " << profit << "." << endl; // Output profit for the day

    cout << "Would you like to buy an Adult animal? Enter 1 for yes or 2 for no: ";
    int c;
    cin >> c;
    if(c == 1) {
        cout << "You want to add an Adult Animal, Please enter the type of the animal you want to add? 1 for tiger, 2 for penguin, 3 for turtle: ";
        int animal;
        cin >> animal;
        while(true) {
            if(animal >= 1  && animal <= 3) {
                break;
            }
            cout << "The animal type is invalid, Pease input the correct animal type!" << endl;
            cout << "Please enter the type of the animal you want to add? 1 for tiger, 2 for penguin, 3 for turtle: ";
            cin >> animal;
        }
        switch(animal) {
            case 1: { //balance checks here for the base cost to purchse the animal as well as the base food cost of the animal
                if(balance < 10010) {
                    cout << "The balance is less in the zoo! Tiger cannot be purchased!" << endl;
                    break;
                }
                addTiger(new Tiger(3, 10000, 0, 2000, 50)); // If user has sufficient funds, add adult tiger
                break;
            }
            case 2: {
                if(balance < 1010) {
                    cout << "The balance is less in the zoo! Penguin cannot be purchased!" << endl;
                    break;
                }
                addPenguin(new Penguin(3, 1000, 0, 100, 10)); // If user has sufficient funds, add adult penguin
                break;
            }
            default: {
                if(balance < 110) {
                    cout << "The balance is less in the zoo! Turtle cannot be purchased!" << endl;
                    break;
                }
                addTurtle(new Turtle(3, 100, 0, 5, 5)); // If user has sufficient funds, add turtle.
                break;
            }
        }
    }

    cout << endl;
    zooSummary(); // Call zooSummar function
    cout << "The profit for the day is: " << profit << endl; // Output profit
    cout << "The balance of the zoo at the end of today is: " << balance << endl; // Output balance
    cout << endl;

}

/*****************************************************
** Description: Thhis function prompts the user if they
** want to continue playing the game or exit. It also
** ends the game if the user has no money left.
**
**
*****************************************************/

void Zoo::playGame() {
    while(true) {
        if(balance <= 0) { // If balance is less than or equal to 0
            cout << "You have no money left! Game ends here!";
            break;
        }
        cout << "Would you like to continue playing the game? Type 1 for yes else 2 for no: ";
        int play;
        cin >> play;
        while(true) {
            if(play == 1 || play == 2)
                break;
            cout << "Input is invalid! Please input the 1 to continue or 2 to exit the game: ";
            cin >> play;
        }
        if(play == 1) {
            newDay(); // Call newDay() function
        }
        else if(play == 2) {
            cout << "Exit from the Game, Game ends here!" << endl;
            break;
        }
    }
}

/****************************************************
** Description: This function outputs the summary
** of how many of each animal the user has.
****************************************************/

void Zoo::zooSummary() {

    cout << "Number of Tigers: " << numOfTigers << endl;
    cout << "Number of Penguins: " << numOfPenguins << endl;
    cout << "Number of Turtles: " << numOfTurtles << endl;
}

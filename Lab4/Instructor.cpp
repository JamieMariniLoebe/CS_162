/*****************************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/19/2018
** Description: This is the Instructor 
** source file.
*****************************************/

#include "Instructor.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


Instructor::Instructor() : Person()//default constructor, inherit person.
{
    rating = 0; //sets rating to 0
}

Instructor::Instructor(string n, int a) : Person(n, a)//parameterized constructor
{
    setRating();//calls setRating to generate random rating between 0-5
}

void Instructor::setRating()//setter to set the rating
{
    rating = rand() % 5;//generate a random number and sets the rating value between 0-5
}

double Instructor::getRating()//getter to retrieve the rating
{
    return rating;//returns the rating value
}

void Instructor::do_work()//function do-work
{
    hours = rand() % 20 + 1;//generates hours of work and display the info
    cout << "Rating: " << getRating() << endl;
    cout << name << " graded papers for " << hours << " hours." << endl;
}

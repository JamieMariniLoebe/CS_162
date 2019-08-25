/**************************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/20/2018
** Description: This is the Instructor
** header file.
**************************************/

#ifndef INSTRUCTOR_hpp
#define INSTRUCTOR_hpp

#include <string>
#include "Person.hpp"

using std::string;

class Instructor: public Person //inherit Person class
{
private:
    double rating; //member variable for rating

public:
    Instructor(); //default constructor that sets rating to 0
    Instructor(string n,int a); //parameterized constructor
    void setRating(); //setter to set the rating
    double getRating(); //getter to retrieve the rating
    void do_work(); //function do-work
};

#endif



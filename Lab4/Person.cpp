/***********************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/19/2018
** Description: This is the Person
** source file
***********************************/

#include "Person.hpp"
#include <string>

Person::Person()//default constructor
{
    name = "";//sets name as empty string
    age = 1;//sets age as 1 year
}

Person::Person(string n, int a)//parameterized constructor
{
    name = n;//sets n as name
    age = a;//sets a as age
}

void Person::setName(string n)//setter to set name
{
    name = n;//sets n as name
}

string Person::getName()//getter to retrieve name
{
    return name;//returns name value
}

void Person::setAge(int a)//setter to set age
{
    age = a;//sets a as age
}

int Person::getAge()//getter to retrieve age
{
    return age;//returns age value
}

void Person::do_work()//virtual function which will be overridden in child classes
{
}


/*************************************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/20/2018
** Description: This is the Person header file.
*************************************************/

#ifndef PERSON_hpp
#define PERSON_hpp

#include <string>

using std::string;

class Person {
protected://declare protected member variables
    string name;//a string for name of the person
    int age;//an integer for age of the person

public:
    int hours;//public variable for hours of work
    Person(); //default constructor

    Person(string n, int a);//parameterized constructor

    void setName(string n);//setter to set name

    string getName();//getter to retrieve name

    void setAge(int a);//setter to set age

    int getAge(); //getter to retrieve age

    virtual void do_work(); //virtual function which will be overridden in child classes
};

#endif


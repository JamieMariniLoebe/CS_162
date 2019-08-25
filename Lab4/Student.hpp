/***********************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/20/2018
** Description: This is the Student
** header file.
***********************************/

#ifndef STUDENT_hpp
#define STUDENT_hpp

#include <string>
#include "Person.hpp"

using std::string;


class Student : public Person // inherit Person class
{
private://private member variable for GPA of student
    double GPA;

public:
    Student(); //default constructor
    Student(string n, int a); //parameterized constructor
    void setGPA(); //setter to set GPA
    double getGPA(); //getter to retrieve GPA
    void do_work(); //function do-work
};

#endif

/*******************************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/20/2018
** Description: This is the Student source
** file.
*******************************************/

#include "Student.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


Student::Student() : Person()//default constructor
{
    GPA = 0;//sets GPA to 0
}

Student::Student(string n, int a) : Person(n, a)//parameterized constructor
{
    setGPA();//call setGPA to generate random GPA in the range 0-4
}

void Student::setGPA()//setter to set GPA
{
    GPA = rand() % 4;//generate random number between 0-4 for GPA
}

double Student::getGPA()//getter to retrieve GPA
{
    return GPA;//returns GPA value
}

void Student::do_work()//function do-work
{
    hours = rand() % 20 + 1;//generates number of hours of work
    cout << "GPA: " << getGPA() << endl;//prints the GPA value
    cout << name << " did " << hours << " hours of homework." << endl;//prints the message
}

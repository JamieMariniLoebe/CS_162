/****************************************
** Program Name: Lab 4
** Author: Jamie Loebe
** Date: 10/21/2018
** Description: This is the main file. It 
** contains the main functions of the program.
****************************************/

#include "University.hpp"
#include "Person.hpp"
#include "Building.hpp"
#include "Instructor.hpp"
#include "Student.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

/************************************
** Description: This function displays
** the menu and prompts the user to 
** choose an option. The user can print
** the building info, people info, make
** a person do work, or exit.
*************************************/
int menu() {
    int choice;//declare an integer for choice and print the following menu to screen
    cout << "1. Print info about all buidings" << endl;
    cout << "2. Print info about all people" << endl;
    cout << "3. Choose a person to do work" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;//read in the choice
    return choice;//returns the choice read in
}


int main() {
    srand(time(0));//call srand to generate  unique random numbers

    Building b1("Adams Hall", 11168, "606 SW 15th ST, Corvallis");//sets b1 as object to class Building
    Building b2("Aero Engineering lab", 3637, "852 SW 30th Street, Corvallis");//sets b2 as object to class Building
    Building b3("Ballard Extension Hall", 45250, "2591 SW Campus way, Corvallis");//sets b3 as object to class Building
    
    vector<Building> buildings;//declare a vector of Building
    
    // Add objects to vector
    buildings.push_back(b1);//add b1 to vector
    buildings.push_back(b2);//add b2 to vector
    buildings.push_back(b3);//add b3 to vector
    
    Instructor i1("Steven Bob", 38);//declare i1 as object to class Instructor
    Instructor i2("Evans", 32);//declare i2 as object to class Instructor
    
    Student s1("Harry James", 16);//declare s1 as object to class Student
    Student s2("George Will", 18);//declare s2 as object to class Student
    
    Person *p1 = &i1;//create 4 pointers to Person class and allot the instructor and student objects to it
    Person *p2 = &i2;
    Person *p3 = &s1;
    Person *p4 = &s2;
    
    vector<Person *> people;//create a vector of Person objects
    
    // Add objects to vector
    people.push_back(p1);//allot p1 to people vector
    people.push_back(p2);//allot p2 to people vector
    people.push_back(p3);//allot p3 to people vector
    people.push_back(p4);//allot p4 to people vector
    
    University univ("Oregon State University", buildings,
                    people);//declare an object to class University, and pass name, buildings vector and people vector as objects
    
    int choice;//declare variable to store menu choice of user

    do {
        cout << "Enter your choice from menu: " << endl;//display menu and prompt user
        choice = menu();
        if (choice == 1)//if choice is 1 then call printBuildingInfo function to print buildings info
        {
            univ.printBuildingInfo();
        } else if (choice == 2)//if choice is 2 then call printPeopleInfo function to print people info
        {
            univ.printPeopleInfo();
        } else if (choice == 3)//if choice is 3
        {
            int personNum;//declare a variable to get which person work to print
            cout << "Select corresponding number of the person you would like to do work: "
                 << endl;//ask user to enter number of corresponding person name
            for (int i = 0; i < people.size(); i++)//iterate through the people vector
            {
                cout << i + 1 << " " << people[i]->getName() << endl;//print all the names
            }
            cin >> personNum;//read in the corresponding number

            while(true) {
                if(personNum >= 1 && personNum <= people.size()) {
                    people[personNum - 1]->do_work();//call corresponding Person's do-work function to print the message
                    break;
                }
                cout << "Invalid Input! Again Select corresponding number of the person you would like to do work: ";
                cin >> personNum;
            }
            cout << endl;
        } else if (choice == 4)//if choice is 4 then print a goodbye message
        {
            cout << "Goodbye!" << endl;
        } else//else print user entered an invalid choice
        {
            cout << "You have entered an invalid menu choice! Please try again" << endl;
        }
    } while (choice != 4);//repeat until user choice is valid

    system("pause");
    return 0;
}

